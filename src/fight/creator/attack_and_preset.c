/*
** EPITECH PROJECT, 2020
** test_fight_rpg
** File description:
** attack_and_preset
*/

#include "fight/creator/attack_and_preset.h"

void set_int_table(int nb, int tab[], int value[])
{
    for (int i = 0; i < nb; i += 1)
        tab[i] = value[i];
}

preset_t *create_preset(int attrib, char *name)
{
    preset_t *preset = malloc(sizeof(preset_t));

    preset->dam_com = attrib;
    preset->name = name;
    return (preset);
}

attack_t *create_attack(preset_t *preset)
{
    attack_t *attack = malloc(sizeof(attack_t));

    attack->dam_com = preset->dam_com;
    attack->req_intel = 0;
    attack->req_intel = 0;
    attack->name = preset->name;
    return (attack);
}

void adder(attack_list_t **attacks, preset_list_t *pre, const char *name)
{
    preset_list_t *tmp = pre;

    for (; tmp; tmp = tmp->next)
        if (my_strcmp(name, tmp->preset->name) == 0) {
            add_element_att(attacks, create_attack(tmp->preset));
            return;
        }
}