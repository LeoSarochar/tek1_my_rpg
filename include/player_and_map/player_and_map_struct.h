/*
** EPITECH PROJECT, 2020
** MY_RPG
** File description:
** .h for sm1_init.c
*/

#include "include_all.h"
#include "sprite.h"

#ifndef MY_PLAYER_AND_MAP_STRUCT_H_
#define MY_PLAYER_AND_MAP_STRUCT_H_

typedef struct cam_s {
    sfView *view;
    sfFloatRect rect;
    sfVector2f pos;
    float zoom;
    float rota;
} cam_t;

typedef struct player_s {
    sfVector2f pos;
    sprite_t *player_sp;
} player_t;

typedef struct map_s {
    int **map;
    sprite_t *map_sp;
} map_t;

typedef struct playmap_s {
    cam_t cam;
    map_t map;
    player_t player;
} playmap_t;

#endif //MY_PLAYER_AND_MAP_STRUCT_H_