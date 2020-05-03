/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** sm1_init.c
*/

#include "player_and_map/sm1_init.h"
#include "main.h"

sfIntRect setblack_rook(void)
{
    sfIntRect rect;
    rect.left = 258;
    rect.top = 64;
    rect.width = 64;
    rect.height = 64;
    return (rect);
}

sfIntRect setblack_pawn(void)
{
    sfIntRect rect;
    rect.left = 312;
    rect.top = 64;
    rect.width = 64;
    rect.height = 64;
    return (rect);
}