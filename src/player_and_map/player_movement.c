/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** sm1_init.c
*/

#include "./player_and_map/player_movement.h"
#include "main.h"

void change_map_0(main_t *main_struct)
{
    if (main_struct->pm.player.scene == 0) {
        if (main_struct->pm.player.pos.y <= 130 && main_struct->pm.player.pos.x >= 315 
        && main_struct->pm.player.pos.x <= 354) {
            main_struct->pm.player.scene = 1;
            main_struct->pm.player.pos.y = 900;
            main_struct->pm.player.pos.x = 315;
        }
        if (main_struct->pm.player.pos.y <= 130 && main_struct->pm.player.pos.x >= 1533 
        && main_struct->pm.player.pos.x <= 1578) {
            main_struct->pm.player.scene = 1;
            main_struct->pm.player.pos.y = 900;
            main_struct->pm.player.pos.x = 1497;
        }
    }
}

void change_map_1(main_t *main_struct)
{
    if (main_struct->pm.player.scene == 1) {
        if (main_struct->pm.player.pos.y <= 321 && main_struct->pm.player.pos.x <= 990 
        && main_struct->pm.player.pos.x >= 800) {
            main_struct->pm.player.scene = 2;
            main_struct->pm.player.pos.y = 87;
            main_struct->pm.player.pos.x = 1047;
        }
        if (main_struct->pm.player.pos.y >= 1050 && main_struct->pm.player.pos.x >= 1408 
        && main_struct->pm.player.pos.x <= 1564) {
            main_struct->pm.player.scene = 0;
            main_struct->pm.player.pos.y = 132;
            main_struct->pm.player.pos.x = 1497;
        }
        if (main_struct->pm.player.pos.y >= 1050 && main_struct->pm.player.pos.x >= 289 
        && main_struct->pm.player.pos.x <= 412) {
            main_struct->pm.player.scene = 0;
            main_struct->pm.player.pos.y = 132;
            main_struct->pm.player.pos.x = 315;
        }
    }
}

void change_map_2(main_t *main_struct)
{
    if (main_struct->pm.player.scene == 2) {
        if (main_struct->pm.player.pos.y <= 34 && main_struct->pm.player.pos.x <= 1122 
        && main_struct->pm.player.pos.x >= 990) {
            main_struct->pm.player.scene = 1;
            main_struct->pm.player.pos.y = 342;
            main_struct->pm.player.pos.x = 933;
        }
    }
}

// void map_handler(main_t *main_struct)
// {
//     if (main_struct->pm.player.scene == 0)
//         change_map_0;
//     else if (main_struct->pm.player.scene == 1)
//         change_map_1;
//     else if (main_struct->pm.player.scene == 2)
//         change_map_2;
// }

void player_move(main_t *main_struct)
{
    sfVector2f pos;

    if (main_struct->story->show_window == 1)
        return;
    if (sfKeyboard_isKeyPressed(sfKeyRight) && main_struct->pm.player.pos.x < 1920 - 32) {
        if (check_cols_right(main_struct, pos) == 0)
            main_struct->pm.player.pos.x += 3;
    }
    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        if (check_cols_up(main_struct, pos) == 0)
            main_struct->pm.player.pos.y -= 3;
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft) && main_struct->pm.player.pos.x > 0) {
        if (check_cols_left(main_struct, pos) == 0)
            main_struct->pm.player.pos.x -= 3;
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown) && main_struct->pm.player.pos.y < 1080 - 32) {
        if (check_cols_down(main_struct, pos) == 0)
            main_struct->pm.player.pos.y += 3;
    }
    change_map_0(main_struct);
    change_map_1(main_struct);
    change_map_2(main_struct);
    // change_map_1(main_struct);
}