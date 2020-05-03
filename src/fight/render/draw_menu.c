/*
** EPITECH PROJECT, 2020
** test_fight_rpg
** File description:
** draw_menu
*/

#include "fight/render/draw_menu.h"

void analyse_stat_attack(attack_list_t *attack, fight_scene_t *scene, int to_do)
{
    int max = get_size_att(attack);

    if (to_do == 1) {
        if (scene->green->pos.y == 200 && scene->var.nb >= 1)
            scene->var.nb -= 1;
        else if (scene->green->pos.y > 200)
            scene->green->pos.y -= 100;
    }
    if (to_do == 0) {
        if (scene->green->pos.y == 500 && scene->var.nb < max)
            scene->var.nb += 1;
        else if (scene->green->pos.y < 500)
            scene->green->pos.y += 100;
    }
    scene->var.nb = (to_do == 1 && scene->var.nb < 1) ? 1 : scene->var.nb;
    scene->var.nb = (to_do == 0 && scene->var.nb > max) ? max : scene->var.nb;
}

void draw_option(main_t *main_struct)
{
    draw_text(main_struct, "attaques", (sfVector2f){870, 200}, 75);
    draw_text(main_struct, "stats", (sfVector2f){890, 300}, 75);
    draw_text(main_struct, "retourner", (sfVector2f){880, 400}, 75);
}

void pos_cursor(sprite_t *sprite, int dir)
{
    if (dir == 0) {
        if (sprite->pos.y >= 400)
            sprite->pos.y = 200;
        else
            sprite->pos.y += 100;
    }
    if (dir == 1) {
        if (sprite->pos.y <= 200)
            sprite->pos.y = 400;
        else
            sprite->pos.y -= 100;
    }
}

void analyse_event_menu(main_t *main, fight_scene_t *scene)
{
    if (main->event.type == sfEvtClosed)
        sfRenderWindow_close(main->window);
    if (scene->var.menu == 0 && main->event.type == sfEvtKeyPressed) {
        if (main->event.key.code == sfKeyUp)
            pos_cursor(scene->green, 1);
        if (main->event.key.code == sfKeyDown)
            pos_cursor(scene->green, 0);
        if (main->event.key.code == 58)
            analyse_enter_menu(scene);
    } else if (scene->var.menu == 1 && main->event.type == sfEvtKeyPressed) {
        if (main->event.key.code == sfKeyUp)
            analyse_stat_attack(main->player->attacks, scene, 1);
        if (main->event.key.code == sfKeyDown)
            analyse_stat_attack(main->player->attacks, scene, 0);
        if (main->event.key.code == 58)
            analyse_enter_menu(scene);
    }
    if (main->event.type == sfEvtKeyPressed \
    && main->event.key.code == sfKeySpace)
        analyse_suite(scene);
}

void drawer_menu_char(main_t *main_struct, fight_scene_t *scene)
{
    draw_sprite(main_struct, scene->menu);
    (scene->var.menu == 0 || scene->var.menu == 1) \
    ? draw_sprite(main_struct, scene->green) : 0;
    (scene->var.menu == 0) ? draw_option(main_struct) : 0;
    (scene->var.menu == 1) ? draw_stat_attack(scene->var.nb, \
    main_struct, scene->var.tab) : 0;
    (scene->var.menu == 2) ? \
    printer(get_element_att(main_struct->player->attacks, \
    scene->var.to_print), main_struct) : 0;
    (scene->var.menu == 3) ? \
    draw_stat_player(main_struct->player, main_struct) : 0;
}