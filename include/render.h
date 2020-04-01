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
#include "story/story.h"

////////INCLUDES OF FUNCS/////////


////////////////////////////////

typedef struct render_s {
    void (*ptr)(main_t *);
} render_t;

//////////PROTOTYPE//////////
//void func_name(main_t *main);
/////////////////////////////

//////////FUNCS//////////////
render_t render_funcs[] = {
    {render_pnjs},
    {NULL} //Don't touch, is the mark of the end of the array
};
////////////////////////////

void render(main_t *main_struct);

#endif //MY_RENDER_H_