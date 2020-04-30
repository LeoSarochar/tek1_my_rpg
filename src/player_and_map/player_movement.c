/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** sm1_init.c
*/

#include "./player_and_map/player_movement.h"
#include "main.h"

void change_map(main_t *main_struct)
{     
    if (main_struct->pm.player.pos.y <= 100 && main_struct->pm.player.pos.x == 315 && main_struct->pm.player.scene == 0) {
        main_struct->pm.player.scene = 1;
        main_struct->pm.player.pos.y = 900;
        main_struct->pm.player.pos.x = 315;
        }
    if (main_struct->pm.player.pos.y <= 100 && main_struct->pm.player.pos.x == 1519 && main_struct->pm.player.scene == 0) {
        main_struct->pm.player.scene = 1;
        main_struct->pm.player.pos.y = 900;
        main_struct->pm.player.pos.x = 1498;
        }
    if (main_struct->pm.player.pos.y >= 1000 && main_struct->pm.player.pos.x == 315 && main_struct->pm.player.scene == 1) {
        main_struct->pm.player.scene = 0;
        main_struct->pm.player.pos.y = 130;
        main_struct->pm.player.pos.x = 315;
        }
    if (main_struct->pm.player.pos.y >= 1000 && main_struct->pm.player.pos.x == 1498 && main_struct->pm.player.scene == 1) {
        main_struct->pm.player.scene = 0;
        main_struct->pm.player.pos.y = 130;
        main_struct->pm.player.pos.x = 1498;
    }
}

// int check_cols(main_t *main_struct, sfVector2f pos, int x, int y)
// {
//     int id = main_struct->pm.player.scene;
//     int a = 0;
//     int b = 0;

//     pos = sfSprite_getPosition(main_struct->pm.player.player_sp->sprite);
//     pos.x += (32 + x);
//     pos.y += (32 + y);
//     a = pos.y/34;
//     b = pos.x/60;
//     if ()
// }

void player_move(main_t *main_struct, UNUSED sfEvent event)
{
    if (sfKeyboard_isKeyPressed(sfKeyRight) && main_struct->pm.player.pos.x < 1870)
        main_struct->pm.player.pos.x += 7;
    if (sfKeyboard_isKeyPressed(sfKeyUp) && main_struct->pm.player.pos.y > 100)
        main_struct->pm.player.pos.y -= 7;
    if (sfKeyboard_isKeyPressed(sfKeyLeft) && main_struct->pm.player.pos.x > 0)
        main_struct->pm.player.pos.x -= 7;
    if (sfKeyboard_isKeyPressed(sfKeyDown) && main_struct->pm.player.pos.y < 1000)
        main_struct->pm.player.pos.y += 7;
    change_map(main_struct);
}