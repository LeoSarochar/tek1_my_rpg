/*
** EPITECH PROJECT, 2019
** MyRPG
** File description:
** create.h
*/

#ifndef MY_PNJ_FUNCS_H_
#define MY_PNJ_FUNCS_H_

#include "include_all.h"
#include "main.h"
#include "story/story.h"
#include "fight/init_attribute.h"

typedef struct main_s main_t;
typedef struct story story_t;
typedef struct object object_t;

void pnj_sanchez(main_t *main);
void after_sanchez(main_t *main);
void after_my_putstr(main_t *main);
void after_sanchez_putstr(main_t *main);

void pnj_mathilde(main_t *main);
void after_mathilde(main_t *main);
void after_my_strlen(main_t *main);

void pnj_jordan(main_t *main);
void after_jordan(main_t *main);
void the_end(main_t *main);

void pnj_nathan(main_t *main);
void after_nathan(main_t *main);

void pnj_loic(main_t *main);
void after_loic(main_t *main);

void pnj_bryan(main_t *main);

void pnj_lorenzo(main_t *main);

void pnj_jackette(main_t *main);

void pnj_richard(main_t *main);

void pnj_sophie(main_t *main);

#endif //MY_CREATE_OBJECT_H_