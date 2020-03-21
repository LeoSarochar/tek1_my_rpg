/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** sm1_init.c
*/

#include "./player_and_map/sm1_init.h"
#include "main.h"

void put_map_sm1(main_t *main_struct)
{
    sfRenderWindow_drawSprite(main_struct->window, main_struct->pm.map.map_sp->sprite, NULL);
}

void put_player(main_t *main_struct)
{
    sfSprite_setPosition(main_struct->pm.player.player_sp->sprite, main_struct->pm.player.pos);
    sfRenderWindow_drawSprite(main_struct->window, main_struct->pm.player.player_sp->sprite, NULL);
}

void init_player(main_t *main_struct)
{
    main_struct->pm.player.pos.x = 300;
    main_struct->pm.player.pos.y = 150;
    main_struct->pm.player.player_sp = load_sprite("./ressources/maps/player.png");
}

void init_map(main_t *main_struct) 
{
    main_struct->pm.map.map_sp = load_sprite("./ressources/maps/sm1.png");   
}