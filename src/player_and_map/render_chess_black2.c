/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** sm1_init.c
*/

#include "player_and_map/sm1_init.h"
#include "main.h"

void renderblack_rook(main_t *main_struct, sfIntRect rect, int y, int x)
{
    sfVector2f pos;

    pos.x = x * 64;
    pos.y = y * 64;
    if (main_struct->pm.chess.map[y][x] == '6') {
        rect = setblack_rook();
        sfSprite_setTextureRect(main_struct->pm.chess.chess_board->sprite,
        rect);
        sfSprite_setPosition(main_struct->pm.chess.chess_board->sprite, pos);
        sfRenderWindow_drawSprite(main_struct->window,
        main_struct->pm.chess.chess_board->sprite, NULL);
    }
}

void renderblack_pawn(main_t *main_struct, sfIntRect rect, int y, int x)
{
    sfVector2f pos;

    pos.x = x * 64;
    pos.y = y * 64;
    if (main_struct->pm.chess.map[y][x] == '1') {
        rect = setblack_pawn();
        sfSprite_setTextureRect(main_struct->pm.chess.chess_board->sprite,
        rect);
        sfSprite_setPosition(main_struct->pm.chess.chess_board->sprite, pos);
        sfRenderWindow_drawSprite(main_struct->window,
        main_struct->pm.chess.chess_board->sprite, NULL);
    }
}