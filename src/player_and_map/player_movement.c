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

void player_move(main_t *main_struct)
{
    sfVector2f pos;

    if (main_struct->story->show_window == 1)
        return;
    if (sfKeyboard_isKeyPressed(sfKeyRight) && main_struct->pm.player.pos.x < 1870) {
        if (check_cols_right(main_struct, pos) == 0)
            main_struct->pm.player.pos.x += 3;
    }
    if (sfKeyboard_isKeyPressed(sfKeyUp) && main_struct->pm.player.pos.y > 100) {
        if (check_cols_up(main_struct, pos) == 0)
            main_struct->pm.player.pos.y -= 3;
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft) && main_struct->pm.player.pos.x > 0) {
        if (check_cols_left(main_struct, pos) == 0)
            main_struct->pm.player.pos.x -= 3;
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown) && main_struct->pm.player.pos.y < 1000) {
        if (check_cols_down(main_struct, pos) == 0)
            main_struct->pm.player.pos.y += 3;
    }
    change_map(main_struct);
}