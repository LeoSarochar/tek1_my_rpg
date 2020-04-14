/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** object
*/

#include "include_all.h"

typedef struct sprite
{
    sfSprite *sprite;
    sfIntRect *rect;
    int visible;
    int offset;
} sprite_t;


//Create a sprite_object with a filename
sprite_t *load_sprite(char const *file_name);