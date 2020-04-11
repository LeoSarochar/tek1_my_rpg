/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** att_list
*/

#ifndef ATT_LIST_H_
#define ATT_LIST_H_
#include "../fight.h"

void add_element_attack(att_list_t **list, attack_t attack);
void remove_element_attack(att_list_t **list, int position);
void insert_element_attack(att_list_t **list, int pos, attack_t attack);
#endif /* !ATT_LIST_H_ */
