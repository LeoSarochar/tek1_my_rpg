/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** sm1_init.c
*/

#include "./player_and_map/player_movement.h"
#include "main.h"

void go_right(main_t *main_struct)
{
    sfClock *clock = sfClock_create();
    float seconds = 0.0;

    if (check_cols_right(main_struct) == 0) {
        seconds = sfClock_getElapsedTime(clock).microseconds / 1000000.0;
        // if (seconds < 0.2) {
        //     printf("fuckoff");
        //     return;
        // }
        main_struct->pm.player.player_sp->rect->top = 60;
        // if ( main_struct->pm.player.player_sp->rect->left < 78*3)
        //     main_struct->pm.player.player_sp->rect->left += 78;
        // else
        //     main_struct->pm.player.player_sp->rect->left = 0;
        main_struct->pm.player.pos.x += 3;

    }
    sfSprite_setTextureRect(main_struct->pm.player.player_sp->sprite, 
    *(main_struct->pm.player.player_sp->rect));
    sfClock_restart(clock);

}

void go_up(main_t *main_struct)
{
    sfClock *clock = malloc(sizeof(clock));
    float seconds = 0.0;

    if (check_cols_right(main_struct) == 0) {
        seconds = sfClock_getElapsedTime(clock).microseconds / 1000000.0;
        // if (seconds < 0.2)
        //     return;
        main_struct->pm.player.player_sp->rect->top = 122;
        // if ( main_struct->pm.player.player_sp->rect->left < 78*3)
        //     main_struct->pm.player.player_sp->rect->left += 78;
        // else
        //     main_struct->pm.player.player_sp->rect->left = 0;
        main_struct->pm.player.pos.y -= 3;

    }
    sfSprite_setTextureRect(main_struct->pm.player.player_sp->sprite, 
    *(main_struct->pm.player.player_sp->rect));
    sfClock_restart(clock);
}

void go_left(main_t *main_struct)
{
    sfClock *clock = malloc(sizeof(clock));
    float seconds = 0.0;

    if (check_cols_right(main_struct) == 0) {
        seconds = sfClock_getElapsedTime(clock).microseconds / 1000000.0;
        // if (seconds < 0.2)
        //     return;
        main_struct->pm.player.player_sp->rect->top = 182;
        // if ( main_struct->pm.player.player_sp->rect->left < 78*3)
        //     main_struct->pm.player.player_sp->rect->left += 78;
        // else
        //     main_struct->pm.player.player_sp->rect->left = 0;
        main_struct->pm.player.pos.x -= 3;

    }
    sfSprite_setTextureRect(main_struct->pm.player.player_sp->sprite, 
    *(main_struct->pm.player.player_sp->rect));
    sfClock_restart(clock);
}

void go_down(main_t *main_struct)
{
    sfClock *clock = malloc(sizeof(clock));
    float seconds = 0.0;

    if (check_cols_right(main_struct) == 0) {
        seconds = sfClock_getElapsedTime(clock).microseconds / 1000000.0;
        // if (seconds < 0.2)
        //     return;
        main_struct->pm.player.player_sp->rect->top = 2;
        // if ( main_struct->pm.player.player_sp->rect->left < 78*3)
        //     main_struct->pm.player.player_sp->rect->left += 78;
        // else
        //     main_struct->pm.player.player_sp->rect->left = 0;
        main_struct->pm.player.pos.y += 3;

    }
    sfSprite_setTextureRect(main_struct->pm.player.player_sp->sprite, 
    *(main_struct->pm.player.player_sp->rect));
    sfClock_restart(clock);
}