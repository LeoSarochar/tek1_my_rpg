/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** call all lib
*/

#ifndef MY_MAIN_H_
#define MY_MAIN_H_

#include "include_all.h"
#include "events.h"

#define SFWC(A, B, C, D) sfRenderWindow_create(A, B, C, D)
#define RWPE(A, B) sfRenderWindow_pollEvent(A, B)
#define UNUSED __attribute__((unused))

typedef struct main_s
{
    sfRenderWindow *window;
    sfEvent event;
} main_t;


#endif //MY_MAIN_H_