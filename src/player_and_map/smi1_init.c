/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** sm1_init.c
*/

#include "player_and_map/sm1_init.h"
#include "main.h"

void put_map_sm1(main_t *main_struct)
{
    if (main_struct->pm.player.scene == 0) {
        sfRenderWindow_drawSprite(main_struct->window, main_struct->pm.map.map_sp->sprite, NULL);
        put_player(main_struct);
    }
}

void put_player(main_t *main_struct)
{
    sfSprite_setPosition(main_struct->pm.player.player_sp->sprite, main_struct->pm.player.pos);
    sfRenderWindow_drawSprite(main_struct->window, main_struct->pm.player.player_sp->sprite, NULL);
}

void init_player(main_t *main_struct)
{
    main_struct->pm.player.pos.x = 315;
    main_struct->pm.player.pos.y = 130;
    main_struct->pm.player.player_sp = load_sprite("./ressources/maps/player.png");
    main_struct->pm.player.scene = 0;
}

void init_map(main_t *main_struct)
{
    main_struct->pm.view = sfView_create();
    main_struct->pm.map.map_sp = load_sprite("./ressources/maps/sm1.png");
}