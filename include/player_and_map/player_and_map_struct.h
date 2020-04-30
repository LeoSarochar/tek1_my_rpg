/*
** EPITECH PROJECT, 2020
** MY_RPG
** File description:
** .h for sm1_init.c
*/

#include "include_all.h"
#include "sprite.h"
#include "main.h"

#ifndef MY_PLAYER_AND_MAP_STRUCT_H_
#define MY_PLAYER_AND_MAP_STRUCT_H_

typedef struct main_s main_t;

typedef struct cam_s {
    sfView *view;
    sfFloatRect rect;
    sfVector2f pos;
    float zoom;
    float rota;
} cam_t;

typedef struct perso_s {
    sfVector2f pos;
    sprite_t *player_sp;
    sfIntRect rect;
    int scene;
    char **map[3];
} perso_t;

typedef struct map_s {
    int **map;
    sprite_t *map_sp;
} map_t;

typedef struct playmap_s {
    sfView *view;
    cam_t cam;
    map_t map;
    map_t corridor;
    perso_t player;
    int map_scene;
} playmap_t;

void gest_view(main_t *main_struct);

#endif //MY_PLAYER_AND_MAP_STRUCT_H_