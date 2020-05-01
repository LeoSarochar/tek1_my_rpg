/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** destroyer
*/

#ifndef DESTROYER_H_
#define DESTROYER_H_
#include "../init_attribute.h"

void destroy_attack(attack_list_t **attack);
void free_enem(enemy_list_t **enemy);
void destroy_fight_scene(main_t *main_struct);
#endif /* !DESTROYER_H_ */
