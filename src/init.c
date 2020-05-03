
/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** init.c
*/

#include "init.h"
#include "particule.h"

void init(main_t *main_struct)
{
    for (int i = 0; init_funcs[i].ptr != NULL; i++)
        init_funcs[i].ptr(main_struct);
    main_struct->part1 = create_particle((V2I){76, 76}, sfWhite);
    main_struct->part2 = create_particle((V2I){76, 76}, sfRed);
    create_sound(main_struct);
    init_cred(main_struct);
    init_option(main_struct);
    init_screen_menu(main_struct);
}