/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** sm1_init.c
*/

#include "./player_and_map/sm1_init.h"
#include "main.h"

void put_corridor(main_t *main_struct)
{
    if (main_struct->player->fight_scene)
        return;
    if (main_struct->pm.player.scene == 1) {
        sfRenderWindow_drawSprite(main_struct->window, main_struct->pm.corridor.map_sp->sprite, NULL);
        put_player(main_struct);
    }
}

void init_corridor(main_t *main_struct)
{
    main_struct->pm.corridor.map_sp = load_sprite("./ressources/maps/corridor.png");
}