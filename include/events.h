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
void handle_pause_menu(main_t *main, sfEvent event);
void handle_inv(main_t *main, sfEvent event);
void move_pieces(main_t *main, sfEvent event);

/////////////////////////////

//////////FUNCS//////////////
event_t events_funcs[] = {
    {sfEvtClosed, close_window},
    {sfEvtKeyPressed, handle_pnj_event},
    {sfEvtKeyPressed, handle_object_event},
    {sfEvtKeyPressed, handle_pause_menu},
    {sfEvtKeyPressed, handle_inv},
    {sfEvtMouseButtonPressed, move_pieces},
    {sfEvtCount, NULL} //Don't touch, is the mark of the end of the array
};
////////////////////////////

#endif //MY_EVENTS_H_