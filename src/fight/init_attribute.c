/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_attribute
*/

#include "main.h"

void init_character(main_t *main)
{
    main->player = malloc(sizeof(character_t));
    main->player->commitment = 100;
    main->player->gpa = 2.0;
    main->player->guard = 10;
    main->player->xp = 0;
    main->player->intellect = 10;
    main->player->speed = 2;
    main->player->height = 64;
    main->player->width = 64;
    main->player->posiion = (sfVector2f){0, 0};
}