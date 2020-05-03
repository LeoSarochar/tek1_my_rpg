/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** sm1_init.c
*/

#include "./player_and_map/player_movement.h"
#include "main.h"

void move_rect_player(main_t *main_struct)
{
    if ( main_struct->pm.player.player_sp->rect->left < 61*2)
        main_struct->pm.player.player_sp->rect->left += 61;
    else
        main_struct->pm.player.player_sp->rect->left = 0;
    sfClock_restart(main_struct->pm.player.clock);
}

void go_right(main_t *main_struct)
{
    float seconds = 0.0;

    if (check_cols_right(main_struct) == 0) {
        seconds = sfClock_getElapsedTime(main_struct
        ->pm.player.clock).microseconds / 1000000.0;
        main_struct->pm.player.pos.x += 3;
        main_struct->pm.player.player_sp->rect->top = 49;
        if (seconds > 0.1) {
            move_rect_player(main_struct);
        }
    }
    sfSprite_setTextureRect(main_struct->pm.player.player_sp->sprite,
    *(main_struct->pm.player.player_sp->rect));
}

void go_up(main_t *main_struct)
{
    float seconds = 0.0;

    if (check_cols_up(main_struct) == 0) {
        seconds = sfClock_getElapsedTime(main_struct
        ->pm.player.clock).microseconds / 1000000.0;
        main_struct->pm.player.pos.y -= 3;
        main_struct->pm.player.player_sp->rect->top = 98;
        if (seconds > 0.1) {
            move_rect_player(main_struct);
        }
    }
    sfSprite_setTextureRect(main_struct->pm.player.player_sp->sprite,
    *(main_struct->pm.player.player_sp->rect));
}

void go_left(main_t *main_struct)
{
    float seconds = 0.0;

    if (check_cols_left(main_struct) == 0) {
        seconds = sfClock_getElapsedTime(main_struct
        ->pm.player.clock).microseconds / 1000000.0;
        main_struct->pm.player.pos.x -= 3;
        main_struct->pm.player.player_sp->rect->top = 145;
        if (seconds > 0.1) {
            move_rect_player(main_struct);
        }
    }
    sfSprite_setTextureRect(main_struct->pm.player.player_sp->sprite,
    *(main_struct->pm.player.player_sp->rect));
}

void go_down(main_t *main_struct)
{
    float seconds = 0.0;

    if (check_cols_down(main_struct) == 0) {
        seconds = sfClock_getElapsedTime(main_struct
        ->pm.player.clock).microseconds / 1000000.0;
        main_struct->pm.player.pos.y += 3;
        main_struct->pm.player.player_sp->rect->top = 0;
        if (seconds > 0.1) {
            move_rect_player(main_struct);
        }
    }
    sfSprite_setTextureRect(main_struct->pm.player.player_sp->sprite,
    *(main_struct->pm.player.player_sp->rect));
}