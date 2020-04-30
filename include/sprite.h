/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** object
*/

#ifndef MY_SPRITE_H_
#define MY_SPRITE_H_

#include "include_all.h"

typedef struct sprite
{
    sfSprite *sprite;
    sfIntRect *rect;
    int visible;
    int offset;
    sfVector2f pos;
} sprite_t;


//Create a sprite_object with a filename
sprite_t *load_sprite(char const *file_name);

#endif //MY_SPRITE_H_