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


////////////////////////////////

typedef struct event_s {
    sfEventType event;
    void (*ptr)(main_t *, sfEvent);
} event_t;

//////////PROTOTYPE//////////
//void func_name(main_t *main, sfEvent event);
/////////////////////////////

//////////FUNCS//////////////
event_t events_funcs[] = {
    {sfEvtClosed, close_window},
    {sfEvtKeyPressed, handle_pnj_event},
    {sfEvtCount, NULL} //Don't touch, is the mark of the end of the array
};
////////////////////////////

#endif //MY_EVENTS_H_