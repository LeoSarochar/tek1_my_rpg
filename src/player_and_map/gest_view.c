/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** sm1_init.c
*/

#include "player_and_map/sm1_init.h"
#include "main.h"

void gest_view(main_t *main_struct)
{
    sfVector2f center = {main_struct->pm.player.pos.x + 32, main_struct->pm.player.pos.y + 33};

    sfRenderWindow_setView(main_struct->window, main_struct->pm.view);
    sfView_setCenter(main_struct->pm.view, center);
    player_move(main_struct);
}