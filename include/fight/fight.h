/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** fight
*/

#ifndef FIGHT_H_
#define FIGHT_H_
#include "init_attribute.h"
#include "main.h"

typedef struct list_s {
    character_t *charachter;
    struct list_s *next;
}list_t;

void fight(main_t *main);
#endif /* !FIGHT_H_ */
