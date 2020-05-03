/*
** EPITECH PROJECT, 2019
** MyRPG
** File description:
** create.h
*/

#ifndef MY_CREATE_PNJ_H_
#define MY_CREATE_PNJ_H_

#include "include_all.h"
#include "main.h"

typedef struct main_s main_t;
typedef struct story story_t;
typedef struct pnj pnj_t;

pnj_t *create_pnj(story_t *story, char **conf, int id, void (*ptr)(main_t *));
int player_can_interact_pnj(main_t *main, pnj_t pnj, int radius);

#endif //MY_CREATE_PNJ_H_