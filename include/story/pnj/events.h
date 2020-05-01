/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** story
*/

#ifndef MY_PNJ_EVENTS_H_
#define MY_PNJ_EVENTS_H_

#include "include_all.h"
#include "main.h"

void handle_object_event(main_t *main, sfEvent event);
void create_window_pnj(story_t *story, char *text, void (*ptr)(story_t *));

#endif //MY_PNJ_EVENTS_H_
