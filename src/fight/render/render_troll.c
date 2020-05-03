/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** render_troll
*/

#include "fight/init_attribute.h"

const char *biensur = "ressources/enemy/troll/biensur.jpg";
const char *honte = "ressources/enemy/troll/honte.jpg";
const char *rafik = "ressources/enemy/loic/win.png";

void render_biensur(main_t *main_struct)
{
    sprite_t *sprite = NULL;

    init_sprite(&sprite, (sfVector2f){400, 0}, biensur);
    draw_sprite(main_struct, sprite);
    draw_text(main_struct, \
    "Bien sur que tu vas github my_putstr\n", (sfVector2f){400, 700}, 75);
    draw_text(main_struct, \
    "Et j'ai mes papiers aussi\n", (sfVector2f){400, 790}, 75);
    sfRenderWindow_display(main_struct->window);
    wait_second(2.0);
    main_struct->player->fight_scene->var.scene = 0;
}

void render_honte(main_t *main_struct)
{
    sprite_t *sprite = NULL;

    sfRenderWindow_clear(main_struct->window, sfBlack);
    init_sprite(&sprite, (sfVector2f){400, 100}, honte);
    draw_text(main_struct, "Eh narvallo, tu perds, contre ", \
    (sfVector2f){400, 0}, 75);
    draw_text(main_struct, \
    main_struct->player->fight_scene->enemies->enemy->name, \
    (sfVector2f){1200, 0}, 75);
    draw_sprite(main_struct, sprite);
    sfRenderWindow_display(main_struct->window);
    wait_second(2.0);
    main_struct->player->com = main_struct->player->com_max;
    main_struct->player->gpa = (main_struct->player->gpa > 0.0) ?
    main_struct->player->gpa - 1.0 : main_struct->player->gpa;
}

void win_scene(main_t *main)
{
    sprite_t *sprite = NULL;

    sfRenderWindow_clear(main->window, sfBlack);
    init_sprite(&sprite, (sfVector2f){400, 100}, rafik);
    draw_sprite(main, sprite);
    draw_text(main, "Bravo, tu obtiens 95 a la moulinette", \
    (sfVector2f){400, 0}, 75);
    sfRenderWindow_display(main->window);
    wait_second(2.0);
    main->player->com_max += main->player->fight_scene->enemies->enemy->com_max;
    main->player->com = main->player->com_max;
    main->player->fight_scene->ptr(main);
    main->player->gpa = (main->player->gpa < 4.0) ?
    main->player->gpa + 0.2 : main->player->gpa;
}

void draw_player(main_t *main)
{
    change_position(main->player->fight_scene->red_pl, 885, 550);
    change_position(main->player->fight_scene->black_pl, 885, 550);
    change_lifebar(main->player->com_max, main->player->com, \
    main->player->fight_scene->red_pl);
    draw_sprite(main, main->player->fight_scene->black_pl);
    draw_sprite(main, main->player->fight_scene->red_pl);
    draw_sprite(main, main->player->sprite);
}

void ending_cond(main_t *main)
{
    if (main->player->fight_scene->var.scene == 16) {
        main->player->fight_scene->var.scene = -1;
        (my_strcmp(main->player->fight_scene->enemies->enemy->name, \
        "Karim") != 0) ? win_scene(main) : win_rimka(main);
    }
    if (main->player->fight_scene->var.scene == 15) {
        render_honte(main);
        main->player->fight_scene->var.scene = -1;
    }
}