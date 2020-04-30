/*
** EPITECH PROJECT, 2020
** test_fight_rpg
** File description:
** getter
*/

#ifndef GETTER_H_
#define GETTER_H_
#include "../init_attribute.h"

attack_t *get_element_att(attack_list_t *list, int pos);
enemy_t *get_element_enem(enemy_list_t *list, int pos);
player_t *get_element_player(player_list_t *list, int pos);
preset_t *get_element_pre(preset_list_t *list, int pos);
#endif /* !GETTER_H_ */
