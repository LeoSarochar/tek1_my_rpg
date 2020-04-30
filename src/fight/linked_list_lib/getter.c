/*
** EPITECH PROJECT, 2020
** test_fight_rpg
** File description:
** getter
*/

#include "fight/init_attribute.h"

attack_t *get_element_att(attack_list_t *list, int pos)
{
    for (int i = 1; list && i < pos; i += 1, list = list->next);
    return (list->attack);
}

enemy_t *get_element_enem(enemy_list_t *list, int pos)
{
    for (int i = 1; list && i < pos; i += 1, list = list->next);
    return (list->enemy);
}

player_t *get_element_player(player_list_t *list, int pos)
{
    for (int i = 1; list && i < pos; i += 1, list = list->next);
    return (list->player);
}

preset_t *get_element_pre(preset_list_t *list, int pos)
{
    for (int i = 1; list && i < pos; i += 1, list = list->next);
    return (list->preset);
}