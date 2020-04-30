/*
** EPITECH PROJECT, 2020
** test_fight_rpg
** File description:
** attack_and_preset
*/

#ifndef ATTACK_AND_PRESET_H_
#define ATTACK_AND_PRESET_H_
#include "../init_attribute.h"

void set_int_table(int nb, int tab[], int value[]);
preset_t *create_preset(int attrib[4], char *name);
attack_t *create_attack(preset_t *preset);
#endif /* !ATTACK_AND_PRESET_H_ */
