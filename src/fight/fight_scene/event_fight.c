/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** event_fight
*/

#include "main.h"

void draw_menu(main_t *main_struct)
{
    draw_text(main_struct, "attack", (sfVector2f){100, 800});
    draw_text(main_struct, "guard", (sfVector2f){1500, 800});
    draw_text(main_struct, "menu", (sfVector2f){100, 900});
    draw_text(main_struct, "flee", (sfVector2f){1500, 900});
}

void display_scene(main_t *main, fight_t *fight)
{
    (main->scene == 0) ? draw_menu(main) : 0;
    (main->scene == 1) ? draw_attack(fight->players->charachter, main) : 0;
}

void change_scene(main_t *main, sfVector2f pos)
{
    if (round(pos.x) == 100 && round(pos.y) == 800 && main->scene == 0)
        main->scene = 1;
}

void analyse_fight_event(main_t *main, sprite_t *sprite, fight_t *fight)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp))
        sprite->pos.y = (sprite->pos.y != 800) ? 800 : 900;
    if (sfKeyboard_isKeyPressed(sfKeyDown))
        sprite->pos.y = (sprite->pos.y != 900) ? 900 : 800;
    if (sfKeyboard_isKeyPressed(sfKeyLeft))
        sprite->pos.x = (sprite->pos.x != 100) ? 100 : 1500;
    if (sfKeyboard_isKeyPressed(sfKeyRight))
        sprite->pos.x = (sprite->pos.x != 1500) ? 1500 : 100;
    if (main->event.type == sfEvtClosed)
        sfRenderWindow_close(main->window);
    if (main->player->commitment == 0)
        sfRenderWindow_close(main->window);
    if (fight->enemy->attack.life == 0)
        sfRenderWindow_close(main->window);
    if (main->event.type == sfEvtKeyPressed) {
        if (main->event.key.code == sfKeyEnter && main->scene == 0)
            change_scene(main, sprite->pos);
        else if (main->event.key.code == sfKeyEnter && main->scene == 1)
            give_attack(main->player, sprite->pos, fight, main);
    }
}