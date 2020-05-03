/*
** EPITECH PROJECT, 2020
** first_plan
** File description:
** rpg
*/

#ifndef MY_FIRST_PLAN_SCREEN_H_
#define MY_FIRST_PLAN_SCREEN_H_

#include "main.h"
#include "csfml_binding.h"
#include "fonction_attribute.h"

typedef struct init_pop_s
{
    sfClock *clock;
    float sec;
    sfTime time_swap;
    sfTexture **Tfirst_display;
    sfSprite *Sfirst_display;
} init_pop_t;

char *my_strdup(char *src);

#endif //MY_FIRST_PLAN_SCREEN_H_