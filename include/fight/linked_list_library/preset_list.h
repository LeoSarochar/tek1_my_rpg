/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** preset_list
*/

#ifndef PRESET_LIST_H_
#define PRESET_LIST_H_
#include "main.h"

void add_element_preset(list_attpre_t **list, attpre_t attack);
void remove_element_preset(list_attpre_t **list, int position);
void insert_element_preset(list_attpre_t **list, int pos, attpre_t attack);
int get_size_preset(list_attpre_t *list);
#endif /* !PRESET_LIST_H_ */
