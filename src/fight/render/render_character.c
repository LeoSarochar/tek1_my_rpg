/*
** EPITECH PROJECT, 2020
** test_fight_rpg
** File description:
** render_character
*/

#include "fight/render/render_character.h"

void edit_rect(sprite_t *sprite, int offset, char *path)
{
    sfTexture *texture = sfTexture_createFromFile(path, NULL);

    sfSprite_destroy(sprite->sprite);
    sprite->offset = offset;
    sprite->rect->left = 0;
    sprite->rect->top = 0;
    sprite->rect->width = offset;
    sprite->sprite = sfSprite_create();
    sfSprite_setTexture(sprite->sprite, texture, sfFalse);
    sfSprite_setTextureRect(sprite->sprite, *(sprite->rect));
}

void change_position(sprite_t *sprite, int x, int y)
{
    sprite->pos.x = x;
    sprite->pos.y = y;
}

void draw_enemy(main_t *main_struct, fight_scene_t *scene)
{
    enemy_list_t *tmp = scene->enemies;

    for (; tmp; tmp = tmp->next) {
        echanger(tmp->enemy);
        draw_sprite(main_struct, tmp->enemy->sprite);
    }
}

void change_lifebar(int life, int new_life, sprite_t *red)
{
    int offset = (new_life * 100) / life;

    if (new_life < 0) {
        edit_rect(red, 0, "ressources/life/red.png");
        return;
    }
    edit_rect(red, offset, "ressources/life/red.png");
}

void draw_bar(main_t *main_struct, fight_scene_t *scene)
{
    enemy_list_t *tmp = scene->enemies;

    for (; tmp; tmp = tmp->next) {
        change_position(scene->red, tmp->enemy->sprite->pos.x + 50, \
        tmp->enemy->sprite->pos.y - 25);
        change_position(scene->black, tmp->enemy->sprite->pos.x + 50, \
        tmp->enemy->sprite->pos.y - 25);
        change_lifebar(tmp->enemy->com_max, tmp->enemy->com, scene->red);
        draw_sprite(main_struct, scene->black);
        draw_sprite(main_struct, scene->red);
    }
}