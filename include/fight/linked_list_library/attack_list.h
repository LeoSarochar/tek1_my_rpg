/*
** EPITECH PROJECT, 2020
** test_fight_rpg
** File description:
** attack_list
*/

#ifndef ATTACK_LIST_H_
#define ATTACK_LIST_H_
#include "../init_attribute.h"

typedef struct attack_s attack_t;
typedef struct attack_list_s attack_list_t;
void add_element_att(attack_list_t **list, attack_t *att);
void remove_element_att(attack_list_t **list, int position);
void insert_element_att(attack_list_t **list, int position, attack_t *att);
int get_size_att(attack_list_t *list);
#endif /* !ATTACK_LIST_H_ */
