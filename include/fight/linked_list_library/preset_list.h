/*
** EPITECH PROJECT, 2020
** test_fight_rpg
** File description:
** preset_list
*/

#ifndef PRESET_LIST_H_
#define PRESET_LIST_H_
#include "../init_attribute.h"

void add_element_pres(preset_list_t **list, preset_t *pres);
void remove_element_pres(preset_list_t **list, int position);
void insert_element_pres(preset_list_t **list, int position, preset_t *pres);
int check_exist(preset_list_t *list, char *name);
int get_size_pres(preset_list_t *list);
#endif /* !PRESET_LIST_H_ */
