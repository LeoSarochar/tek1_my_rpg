/*
** EPITECH PROJECT, 2020
** test_fight_rpg
** File description:
** player_turn
*/

#ifndef PLAYER_TURN_H_
#define PLAYER_TURN_H_
#include "../init_attribute.h"

int player_attack_force(player_t *player, int attack);
int player_attack_intel(player_t *player, attack_t *attack);
int player_attack_ram(player_t *player, attack_t *attack);
void player_defense_attack(int dam, player_t *player);
void player_defense_total(player_t *player, int dam);
#endif /* !PLAYER_TURN_H_ */
