/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** sm1_init.c part 2
*/

#include "player_and_map/sm1_init.h"
#include "main.h"

sprite_t *load_sprite_player(char const *file_name);

void init_perso(main_t *main_struct)
{

    main_struct->pm.player.pos.x = 96;
    main_struct->pm.player.pos.y = 681;
    main_struct->pm.player.player_sp = 
    load_sprite_player("./ressources/maps/player.png");
    main_struct->pm.player.scene = 2;
    sfSprite_setTextureRect(main_struct->pm.player.player_sp->sprite, 
    *(main_struct->pm.player.player_sp->rect));
    main_struct->pm.player.clock = sfClock_create();
}

void init_map(main_t *main_struct)
{
    main_struct->pm.view = sfView_create();
    sfView_setSize(main_struct->pm.view, (sfVector2f){960, 540});
    main_struct->pm.map.map_sp = load_sprite("./ressources/maps/sm1.png");
    main_struct->pm.map_3D.map_sp = 
    load_sprite("./ressources/maps/sm1_3d.png");
}