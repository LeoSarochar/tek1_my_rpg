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

preset_t *create_preset(int attrib[4], char *name)
{
    preset_t *preset = malloc(sizeof(preset_t));

    preset->dam_com = attrib[0];
    preset->fo_alr = 0;
    preset->req_intel = attrib[1];
    preset->req_ram = attrib[2];
    preset->xp = attrib[3];
    preset->name = name;
    return (preset);
}

attack_t *create_attack(preset_t *preset)
{
    attack_t *attack = malloc(sizeof(attack_t));

    attack->dam_com = preset->dam_com;
    attack->name = preset->name;
    attack->req_intel = preset->req_intel;
    attack->req_ram = preset->req_ram;
    return (attack);
}