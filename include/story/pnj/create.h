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

void create_pnj(story_t *story, char *name, char *path, void (*ptr)(story_t *));

#endif //MY_CREATE_PNJ_H_