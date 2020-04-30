/*
** EPITECH PROJECT, 2020
** test_fight_rpg
** File description:
** player_list
*/

#ifndef PLAYER_LIST_H_
#define PLAYER_LIST_H_
#include "../init_attribute.h"

typedef struct player_s player_t;
typedef struct player_list_s player_list_t;
void add_element_pl(player_list_t **list, player_t *pl);
void remove_element_pl(player_list_t **list, int position);
void insert_element_pl(player_list_t **list, int position, player_t *pl);
int get_size_pl(player_list_t *list);
#endif /* !PLAYER_LIST_H_ */
