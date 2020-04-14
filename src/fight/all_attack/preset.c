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

void print_preset(preset_t *preset)
{
    list_attpre_t *tmp1 = preset->attack;
    att_list_t *tmp2 = preset->comp;
    for (; tmp1; tmp1 = tmp1->next)
        printf("name = %s, max_deg = %d, min_xp = %d, fought_already = %d\n", tmp1->attack.name, tmp1->attack.max_deg, tmp1->attack.min_xp, tmp1->attack.fought_already);
    for (; tmp2; tmp2 = tmp2->next)
        printf("name = %s, req_intel = %d, req_logi = %d, dama_com = %d, life = %d\n", tmp2->attack.name, tmp2->attack.req_intel, tmp2->attack.req_logi, tmp2->attack.dama_com, tmp2->attack.life);
}

void init_preset(preset_t *preset)
{
    preset->attack = NULL;
    preset->comp = NULL;
    preset_cpool(&preset->attack);
    preset_comp(&preset->comp);
}