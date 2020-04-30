/*
** EPITECH PROJECT, 2020
** test_fight_rpg
** File description:
** analyse_position
*/

#ifndef ANALYSE_POSITION_H_
#define ANALYSE_POSITION_H_
#include "../init_attribute.h"

void analyse_enter_bg(fight_scene_t *scene);
void draw_stat_attack(int nb, main_t *main, int tab[4]);
void analyse_enter_menu(fight_scene_t *scene);
void printer(attack_t *attack, main_t *main);
void draw_stat_player(player_t *player, main_t *main);
#endif /* !ANALYSE_POSITION_H_ */
