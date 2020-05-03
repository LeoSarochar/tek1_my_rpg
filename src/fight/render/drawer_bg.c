/*
** EPITECH PROJECT, 2020
** test_fight_rpg
** File description:
** drawer_bg
*/

#include "fight/render/drawer_bg.h"

void analyse_suite(fight_scene_t *scene)
{
    if (scene->var.menu == 0)
        scene->var.scene = 0;
    if (scene->var.menu == 1) {
        scene->green->pos.y = 200;
        scene->var.menu = 0;
    }
    if (scene->var.menu == 2) {
        scene->green->pos.y = 200;
        scene->var.menu = 1;
    }
    if (scene->var.menu == 3)
        scene->var.menu = 0;
}

void drawer_sprite(main_t *main, sprite_t *sprite)
{
    sfSprite_setPosition(sprite->sprite, sprite->pos);
    sfRenderWindow_drawSprite(main->window, sprite->sprite, NULL);
}

void draw_bg(main_t *main_struct, fight_scene_t *scene)
{
    drawer_sprite(main_struct, scene->bg);
    if (scene->var.menu == 0 || scene->var.menu == 1)
        draw_sprite(main_struct, scene->cursor);
}