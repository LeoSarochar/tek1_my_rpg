/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** basing_functions
*/

#ifndef BASING_FUNCTIONS_H_
#define BASING_FUNCTIONS_H_
#include "../fight.h"

void add_element_char(list_t **list, character_t *character);
void remove_element_char(list_t **list, int position);
void insert_element_char(list_t **list, int position, character_t *character);
#endif /* !BASING_FUNCTIONS_H_ */
