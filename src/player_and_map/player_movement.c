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
        if (main_struct->pm.player.pos.y <= 130
        && main_struct->pm.player.pos.x >= 315
        && main_struct->pm.player.pos.x <= 354) {
            main_struct->pm.player.scene = 1;
            main_struct->pm.player.pos.y = 900;
            main_struct->pm.player.pos.x = 315;
        }
        if (main_struct->pm.player.pos.y <= 130
        && main_struct->pm.player.pos.x >= 1533
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
        if (main_struct->pm.player.pos.y <= 330
        && main_struct->pm.player.pos.x <= 990
        && main_struct->pm.player.pos.x >= 800) {
            main_struct->pm.player.scene = 2;
            main_struct->pm.player.pos.y = 87;
            main_struct->pm.player.pos.x = 1047;
        }
        if (main_struct->pm.player.pos.y >= 960
        && main_struct->pm.player.pos.x >= 1408
        && main_struct->pm.player.pos.x <= 1564) {
            main_struct->pm.player.scene = 0;
            main_struct->pm.player.pos.y = 132;
            main_struct->pm.player.pos.x = 1497;
        }
    }
}

void change_map_1_2(main_t *main_struct)
{
    if (main_struct->pm.player.scene == 1) {
        if (main_struct->pm.player.pos.y >= 960
        && main_struct->pm.player.pos.x >= 289
        && main_struct->pm.player.pos.x <= 412) {
            main_struct->pm.player.scene = 0;
            main_struct->pm.player.pos.y = 132;
            main_struct->pm.player.pos.x = 315;
        }
    }
    if (main_struct->pm.player.scene == 1) {
        if (main_struct->pm.player.pos.y >= 447
        && main_struct->pm.player.pos.y >= 534
        && main_struct->pm.player.pos.x >= 1713
        && main_struct->pm.player.pos.x <= 1809) {
            main_struct->pm.player.scene = 3;
        }
    }
}

void change_map_2(main_t *main_struct)
{
    if (main_struct->pm.player.scene == 2) {
        if (main_struct->pm.player.pos.y <= 34
        && main_struct->pm.player.pos.x <= 1122
        && main_struct->pm.player.pos.x >= 990) {
            main_struct->pm.player.scene = 1;
            main_struct->pm.player.pos.y = 450;
            main_struct->pm.player.pos.x = 933;
        }
    }
}

void player_move(main_t *main)
{
    if (main->pm.player.scene != 3) {
        if (main->story->show_window == 1)
            return;
        if (sfKeyboard_isKeyPressed(sfKeyRight)
        && main->pm.player.pos.x < 1920 - 50)
            go_right(main);
        if (sfKeyboard_isKeyPressed(sfKeyUp))
            go_up(main);
        if (sfKeyboard_isKeyPressed(sfKeyLeft) && main->pm.player.pos.x > 0)
            go_left(main);
        if (sfKeyboard_isKeyPressed(sfKeyDown)
        && main->pm.player.pos.y < 1080 - 50)
            go_down(main);
        change_map_0(main);
        change_map_1(main);
        change_map_1_2(main);
        change_map_2(main);
    } else if (main->pm.player.scene == 3
    && sfKeyboard_isKeyPressed(sfKeyQ)) {
        change_map_3(main);
    }
}