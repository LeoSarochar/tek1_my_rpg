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


////////////////////////////////

typedef struct init_s {
    void (*ptr)(main_t *);
} init_t;

//////////PROTOTYPE//////////
//void func_name(main_t *main);
/////////////////////////////

//////////FUNCS//////////////
init_t init_funcs[] = {
    {init_player},
    {NULL} //Don't touch, is the mark of the end of the array
};
////////////////////////////

void init(main_t *main_struct);

#endif //MY_INIT_H_