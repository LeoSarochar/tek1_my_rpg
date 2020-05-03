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
    if (main_struct->pm.player.scene == 3 && sfKeyboard_isKeyPressed(sfKeyQ)) {
        main_struct->pm.player.scene = 1;
        main_struct->pm.player.pos.x = 350;
        main_struct->pm.player.pos.y = 933;
    }
}