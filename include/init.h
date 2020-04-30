/*
** EPITECH PROJECT, 2019
** MyRPG
** File description:
** init.h
*/

#ifndef MY_INIT_H_
#define MY_INIT_H_

#include "include_all.h"
#include "main.h"

////////INCLUDES OF FUNCS/////////
#include "sprite.h"

////////////////////////////////

typedef struct init_s {
    void (*ptr)(main_t *);
} init_t;

//////////PROTOTYPE//////////
void init_player(main_t *main_struct);
void init_map(main_t *main_struct);
void init_corridor(main_t *main_struct);
/////////////////////////////

//////////FUNCS//////////////
init_t init_funcs[] = {
    {init_map},
    {init_player},
    {init_corridor},
    {NULL} //Don't touch, is the mark of the end of the array
};
////////////////////////////

void init(main_t *main_struct);

#endif //MY_INIT_H_