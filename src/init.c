
/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** init.c
*/

#include "init.h"

void init(main_t *main_struct)
{
    for (int i = 0; init_funcs[i].ptr != NULL; i++)
        init_funcs[i].ptr(main_struct);
    init_screen_menu(main_struct);
}