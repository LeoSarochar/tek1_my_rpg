/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** sm1_init.c
*/

#include "./player_and_map/player_movement.h"
#include "main.h"

void change_map_3(main_t *main_struct)
{
    main_struct->pm.player.scene = 1;
    main_struct->pm.player.pos.x = 1644;
    main_struct->pm.player.pos.y = 486;
}