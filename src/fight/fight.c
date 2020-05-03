/*
** EPITECH PROJECT, 2020
** test_fight_rpg
** File description:
** fight
*/

#include "main.h"

void set_attrib(main_t *main, int att, int def, int life)
{
    attack_list_t *tmp = main->player->attacks;

    main->player->defence += def;
    for (; tmp; tmp = tmp->next)
        tmp->attack->dam_com += att;
    main->player->com_max += life;
}