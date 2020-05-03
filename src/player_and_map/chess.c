/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** sm1_init.c
*/

#include "player_and_map/sm1_init.h"
#include "main.h"

sfIntRect set_king(void)
{
    sfIntRect rect;
    rect.left = 0;
    rect.top = 0;
    rect.width = 64;
    rect.height = 64;
    return (rect);
}

sfIntRect set_queen(void)
{
    sfIntRect rect;
    rect.left = 64;
    rect.top = 0;
    rect.width = 64;
    rect.height = 64;
    return (rect);
}

sfIntRect set_bishop(void)
{
    sfIntRect rect;
    rect.left = 128;
    rect.top = 0;
    rect.width = 64;
    rect.height = 64;
    return (rect);
}

sfIntRect set_knight(void)
{
    sfIntRect rect;
    rect.left = 192;
    rect.top = 0;
    rect.width = 64;
    rect.height = 64;
    return (rect);
}