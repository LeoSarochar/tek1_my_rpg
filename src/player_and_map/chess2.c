/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** sm1_init.c
*/

#include "player_and_map/sm1_init.h"
#include "main.h"

sfIntRect set_rook(void)
{
    sfIntRect rect;
    rect.left = 258;
    rect.top = 0;
    rect.width = 64;
    rect.height = 64;
    return (rect);
}

sfIntRect set_pawn(void)
{
    sfIntRect rect;
    rect.left = 312;
    rect.top = 0;
    rect.width = 64;
    rect.height = 64;
    return (rect);
}