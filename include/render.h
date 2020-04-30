/*
** EPITECH PROJECT, 2019
** MyRPG
** File description:
** render.h
*/

#ifndef MY_RENDER_H_
#define MY_RENDER_H_

#include "include_all.h"
#include "main.h"

////////INCLUDES OF FUNCS/////////
#include "sprite.h"
////////////////////////////////

typedef struct render_s {
    void (*ptr)(main_t *);
} render_t;

//////////PROTOTYPE//////////
void put_map_sm1(main_t *main_struct);
void put_player(main_t *main_struct);
void put_corridor(main_t *main_struct);
/////////////////////////////

//////////FUNCS//////////////
render_t render_funcs[] = {
    {put_map_sm1},
    {put_corridor},
    {NULL} //Don't touch, is the mark of the end of the array
};
////////////////////////////

void render(main_t *main_struct);

#endif //MY_RENDER_H_