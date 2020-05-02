/*
** EPITECH PROJECT, 2020
** test_fight_rpg
** File description:
** create_char
*/

#ifndef CREATE_CHAR_H_
#define CREATE_CHAR_H_
#include "../init_attribute.h"

enemy_t *create_enemy(preset_list_t *pre, char *name);
void other_pos(attack_list_t **attack, preset_list_t *pre, char *name);
int give_rand(int min, int max);
int percent(int nb, int per);
#endif /* !CREATE_CHAR_H_ */
