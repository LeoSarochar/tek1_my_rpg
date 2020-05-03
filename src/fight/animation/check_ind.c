/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** check_ind
*/

#include "fight/init_attribute.h"

int is_same(int i, int ind, int tab[4])
{
    for (; i < 4; i += 1)
        if (ind == tab[i])
            return (-1);
    return (0);
}