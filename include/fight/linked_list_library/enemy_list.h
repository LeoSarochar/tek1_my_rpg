/*
** EPITECH PROJECT, 2020
** test_fight_rpg
** File description:
** enemy_list
*/

#ifndef ENEMY_LIST_H_
#define ENEMY_LIST_H_
#include "../init_attribute.h"

typedef struct enemy_s enemy_t;
typedef struct enemy_list_s enemy_list_t;
void add_element_enem(enemy_list_t **list, enemy_t *enem);
void remove_element_enem(enemy_list_t **list, int position);
void insert_element_enem(enemy_list_t **list, int position, enemy_t *enem);
int get_size_enem(enemy_list_t *list);
#endif /* !ENEMY_LIST_H_ */
