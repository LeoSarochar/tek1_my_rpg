/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** sm1_init.c
*/

#include "./player_and_map/player_movement.h"
#include "main.h"

int check_cols_right(main_t *main_struct)
{
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;

    a = (main_struct->pm.player.pos.y) / 32;
    b = (main_struct->pm.player.pos.x + 47) / 32;
    c = (main_struct->pm.player.pos.y + 47) / 32;
    d = (main_struct->pm.player.pos.x + 47) / 32;
    if (main_struct->map[main_struct->pm.player.scene][a][b] == '1' ||
    main_struct->map[main_struct->pm.player.scene][c][d] == '1') {
        return (-1);
    }
    return (0);
}

int check_cols_left(main_t *main_struct)
{
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;

    a = (main_struct->pm.player.pos.y) / 32;
    b = (main_struct->pm.player.pos.x - 3) / 32;
    c = (main_struct->pm.player.pos.y + 47) / 32;
    d = (main_struct->pm.player.pos.x - 3) / 32;
    if (main_struct->map[main_struct->pm.player.scene][a][b] == '1' ||
    main_struct->map[main_struct->pm.player.scene][c][d] == '1') {
        return (-1);
    }
    return (0);
}

int check_cols_down(main_t *main_struct)
{
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;

    a = (main_struct->pm.player.pos.y + 50) / 32;
    b = (main_struct->pm.player.pos.x + 44) / 32;
    c = (main_struct->pm.player.pos.y + 50) / 32;
    d = (main_struct->pm.player.pos.x ) / 32;
    if (main_struct->map[main_struct->pm.player.scene][a][b] == '1' ||
    main_struct->map[main_struct->pm.player.scene][c][d] == '1') {
        return (-1);
    }
    return (0);
}

int check_cols_up(main_t *main_struct)
{
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;

    a = (main_struct->pm.player.pos.y - 3) / 32;
    b = (main_struct->pm.player.pos.x) / 32;
    c = (main_struct->pm.player.pos.y - 3) / 32;
    d = (main_struct->pm.player.pos.x + 44) / 32;
    if (main_struct->map[main_struct->pm.player.scene][a][b] == '1' ||
    main_struct->map[main_struct->pm.player.scene][c][d] == '1') {
        return (-1);
    }
    return (0);
}