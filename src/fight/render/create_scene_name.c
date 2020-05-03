/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_scene_name
*/

#include "fight/init_attribute.h"
#include "lib/my.h"

const char *bg = "ressources/scene/test.png";
const char *cursor = "ressources/scene/cursor.png";
const char *menu = "ressources/scene/menu.jpg";
const char *black = "ressources/life/black.png";
const char *red = "ressources/life/red.png";
const char *green = "ressources/scene/green.png";

preset_t *give_preset_name(char *name, preset_list_t *pre)
{
    preset_list_t *tmp  = pre;

    for (; tmp; tmp = tmp->next) {
        if (my_strcmp(name, tmp->preset->name) == 0)
            return (tmp->preset);
    }
    return (NULL);
}

void init_scene_name(main_t *main_struct, char *name, void (*ptr)(main_t *))
{
    fight_scene_t *scene = malloc(sizeof(*scene));

    scene->enemies = NULL;
    scene->var.menu = 0;
    scene->var.scene = 0;
    scene->var.nb = 1;
    scene->ptr = ptr;
    add_element_enem(&scene->enemies, \
    create_enemy(main_struct->player->preset, name));
    init_sprite(&scene->bg, (sfVector2f){0, 0}, bg);
    init_sprite(&scene->cursor, (sfVector2f){100, 800}, cursor);
    init_sprite(&scene->black, (sfVector2f){0, 0}, black);
    init_sprite(&scene->red, (sfVector2f){0, 0}, red);
    init_sprite(&scene->black_pl, (sfVector2f){0, 0}, black);
    init_sprite(&scene->red_pl, (sfVector2f){0, 0}, red);
    init_sprite(&scene->menu, (sfVector2f){0, 0}, menu);
    init_sprite(&scene->green, (sfVector2f){790, 200}, green);
    init_sprite_enem(scene->enemies);
    main_struct->player->fight_scene = scene;
}