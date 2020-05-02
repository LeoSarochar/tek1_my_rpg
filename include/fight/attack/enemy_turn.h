/*
** EPITECH PROJECT, 2020
** test_fight_rpg
** File description:
** enemy_turn
*/

#ifndef ENEMY_TURN_H_
#define ENEMY_TURN_H_
#include "../init_attribute.h"

int enem_attack_intel(enemy_t *player, attack_t *attack);
int enem_attack_ram(enemy_t *player, attack_t *attack);
void enem_defense_attack(int dam, enemy_t *player);
void enem_defense_total(enemy_t *player, int dam);
#endif /* !ENEMY_TURN_H_ */
