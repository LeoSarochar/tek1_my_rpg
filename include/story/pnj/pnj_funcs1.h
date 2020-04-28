/*
** EPITECH PROJECT, 2019
** MyRPG
** File description:
** create.h
*/

#ifndef MY_PNJ_FUNCS_1_H_
#define MY_PNJ_FUNCS_1_H_

#define STRY_PTR void (*ptr)(story_t *)

#include "include_all.h"
#include "main.h"

typedef struct main_s main_t;
typedef struct story story_t;
typedef struct object object_t;

void pnj_sanchez(story_t *story);

#endif //MY_CREATE_OBJECT_H_