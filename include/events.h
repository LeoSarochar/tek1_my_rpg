/*
** EPITECH PROJECT, 2019
** MyRPG
** File description:
** events.h
*/

#ifndef MY_EVENTS_H_
#define MY_EVENTS_H_

#include "include_all.h"
#include "main.h"

////////INCLUDES OF FUNCS/////////
#include "./player_and_map/player_movement.h"

////////////////////////////////

typedef struct event_s {
    sfEventType event;
    void (*ptr)(main_t *, sfEvent);
} event_t;

//////////PROTOTYPE//////////
//void func_name(main_t *main, sfEvent event);
void player_move(main_t *main_struct, UNUSED sfEvent);
/////////////////////////////

//////////FUNCS//////////////
event_t events_funcs[] = {
    {sfEvtClosed, close_window},
    // {sfEvtKeyPressed, player_move},
    {sfEvtCount, NULL} //Don't touch, is the mark of the end of the array
};
////////////////////////////

#endif //MY_EVENTS_H_