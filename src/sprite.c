/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** object.c
*/

#include "sprite.h"

sfIntRect *init_rect(sfTexture *texture)
{
    sfIntRect *rect = malloc(sizeof(sfIntRect));
    rect->top = 0;
    rect->left = 0;
    rect->height = sfTexture_getSize(texture).y;
    rect->width = sfTexture_getSize(texture).x;
    return (rect);
}

sprite_t *load_sprite(char const *file_name)
{
    sprite_t *item = malloc(sizeof(sprite_t));
    sfSprite *sprite = NULL;
    sfTexture *texture = sfTexture_createFromFile(file_name, NULL);

    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    item->sprite = sprite;
    item->rect = malloc(sizeof(sfIntRect));
    item->rect = init_rect(texture);
    item->visible = sfTrue;
    return (item);
}