/*
** EPITECH PROJECT, 2020
** test_fight_rpg
** File description:
** create_char
*/

#ifndef CREATE_CHAR_H_
#define CREATE_CHAR_H_
#include "../init_attribute.h"

enemy_t *create_enemy(preset_t *pre);
preset_list_t *otther_pos(preset_list_t *preset, int xp);
int give_rand(int min, int max);
int percent(int nb, int per);
#endif /* !CREATE_CHAR_H_ */
