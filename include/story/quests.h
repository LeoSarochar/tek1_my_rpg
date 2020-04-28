/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** story
*/

#ifndef MY_QUESTS_H
#define MY_QUESTS_H

#include "include_all.h"
#include "sprite.h"
#include "main.h"
#include "lib/my.h"

typedef struct quests {
    int show_quests;
    sprite_t *background;
    char *text;
    int quest_id;
} quests_t;

void init_quests(main_t *main_struct);
void render_quests(main_t *main);

#endif //MY_QUESTS_H