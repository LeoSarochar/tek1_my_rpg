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

typedef struct fight_s {
    list_t *players;
    att_list_t *enemy;
    int nb_player;
    int nb_enemy;
    int nb_deadpl;
    int nb_deadenem;
}fight_t;

void fight(main_t *main);
void init_sprite(att_list_t *enemy, main_t *main_struct, char *path);
void display_player(character_t *player, main_t *main_struct, char *path);
#endif /* !FIGHT_H_ */
