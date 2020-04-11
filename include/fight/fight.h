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

typedef enum {
    BOSS,
    ENEMY,
    ALLIES
}TYPE;

typedef struct list_s {
    character_t *charachter;
    struct list_s *next;
}list_t;

typedef struct att_list_s {
    attack_t attack;
    struct att_list_s *next;
}att_list_t;

void fight(main_t *main);
#endif /* !FIGHT_H_ */
