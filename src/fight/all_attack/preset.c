/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** preset
*/

#include "main.h"

void preset_cpool(list_attpre_t **list)
{
    add_element_preset(list, create_preset("putchar", 10, 0, 0));
    add_element_preset(list, create_preset("is_neg", 10, 5, 0));
    add_element_preset(list, create_preset("put_nbr", 10, 10, 0));
}

void preset_comp(att_list_t **list)
{
    add_element_attack(list, crte_att((int [4]){5, 0, 25, 0}, "array", 0));
    add_element_attack(list, crte_att((int [4]){10, 0, 25, 0}, "stack", 0));
}

void init_preset(preset_t *preset)
{
    preset->attack = NULL;
    preset->comp = NULL;
    preset_cpool(&preset->attack);
    preset_comp(&preset->comp);
}