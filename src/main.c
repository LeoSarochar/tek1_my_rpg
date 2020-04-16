/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** main.c
*/

#include "main.h"
#include "events.h"

void close_window(main_t *main_struct, UNUSED sfEvent event)
{
    sfRenderWindow_close(main_struct->window);
}

void game_event(main_t *main_struct)
{
    for (int i = 0; events_funcs[i].event != sfEvtCount; i++)
        if (events_funcs[i].event == main_struct->event.type) {
            events_funcs[i].ptr(main_struct, main_struct->event);
            break;
        }
}

int main(UNUSED int ac, UNUSED char **av)
{
    main_t main_struct;
    sfVideoMode mode = {1920, 1080, 32};
    sprite_t *sprite = load_sprite("ressources/test.png");
    sprite_t *cursor = load_sprite("ressources/cursor.png");
    main_struct.clock = sfClock_create();
    main_struct.scene = 0;
    sfTime time = sfClock_getElapsedTime(main_struct.clock);
    float seconds = time.microseconds / 1000000.0;
    int pl_com = 0;
    int enem_com = 0;
    sprite_t *red_one = load_sprite("ressources/red.png");
    sprite_t *red_two = load_sprite("ressources/red.png");
    sprite_t *black_one = load_sprite("ressources/black.png");
    sprite_t *black_two = load_sprite("ressources/black.png");

    set_position(&sprite->pos, 0, 0);
    set_position(&cursor->pos, 100, 800);
    main_struct.window = SFWC(mode, "Road 4 GPA", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(main_struct.window, 64);
    init(&main_struct);
    fight_t *fight = create_scene(&main_struct);
    pl_com = main_struct.player->commitment;
    enem_com = fight->enemy->attack.life;
    edit_rect(fight->enemy->attack.sprite, 92, "ressources/stance.png");
    display_life(red_one, red_two, black_one, black_two);
    while (sfRenderWindow_isOpen(main_struct.window)) {
        while (RWPE(main_struct.window, &main_struct.event))
            analyse_fight_event(&main_struct, cursor, fight);
        sfRenderWindow_clear(main_struct.window, sfBlack);
        draw_sprite(&main_struct, sprite);
        draw_sprite(&main_struct, cursor);
        draw_sprite(&main_struct, black_one);
        draw_sprite(&main_struct, black_two);
        draw_sprite(&main_struct, red_one);
        draw_sprite(&main_struct, red_two);
        change_lifebar(pl_com, main_struct.player->commitment, red_one);
        change_lifebar(enem_com, fight->enemy->attack.life, red_two);
        display_scene(&main_struct, fight);
        init_sprite(fight->enemy, &main_struct, "ressources/stance.png");
        time = sfClock_getElapsedTime(main_struct.clock);
        seconds = time.microseconds / 1000000.0;
        if (seconds > 0.1) {
            move_rect(fight->players->charachter->sprite);
            move_rect(fight->enemy->attack.sprite);
            sfClock_restart(main_struct.clock);
        }
        display_player(fight->players->charachter, &main_struct, "ressources/stance_naruto.png");
        sfRenderWindow_display(main_struct.window);
    }
    sfRenderWindow_destroy(main_struct.window);
    return (0);
}