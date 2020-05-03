/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** sm1_init.c
*/

#include "player_and_map/sm1_init.h"
#include "main.h"

void render_king(main_t *main_struct, sfIntRect rect, int y, int x)
{
    sfVector2f pos;

    pos.x = x * 64;
    pos.y = y * 64;
    if (main_struct->pm.chess.map[y][x] == 'k') {
        rect = set_king();
        sfSprite_setTextureRect(main_struct->pm.chess.chess_board->sprite,
        rect);
        sfSprite_setPosition(main_struct->pm.chess.chess_board->sprite, pos);
        sfRenderWindow_drawSprite(main_struct->window,
        main_struct->pm.chess.chess_board->sprite, NULL);
    }
}

void render_queen(main_t *main_struct, sfIntRect rect, int y, int x)
{
    sfVector2f pos;

    pos.x = x * 64;
    pos.y = y * 64;
    if (main_struct->pm.chess.map[y][x] == 'q') {
        rect = set_queen();
        sfSprite_setTextureRect(main_struct->pm.chess.chess_board->sprite,
        rect);
        sfSprite_setPosition(main_struct->pm.chess.chess_board->sprite, pos);
        sfRenderWindow_drawSprite(main_struct->window,
        main_struct->pm.chess.chess_board->sprite, NULL);
    }
}

void render_bishop(main_t *main_struct, sfIntRect rect, int y, int x)
{
    sfVector2f pos;

    pos.x = x * 64;
    pos.y = y * 64;
    if (main_struct->pm.chess.map[y][x] == 'b') {
        rect = set_bishop();
        sfSprite_setTextureRect(main_struct->pm.chess.chess_board->sprite,
        rect);
        sfSprite_setPosition(main_struct->pm.chess.chess_board->sprite, pos);
        sfRenderWindow_drawSprite(main_struct->window,
        main_struct->pm.chess.chess_board->sprite, NULL);
    }
}

void render_knight(main_t *main_struct, sfIntRect rect, int y, int x)
{
    sfVector2f pos;

    pos.x = x * 64;
    pos.y = y * 64;
    if (main_struct->pm.chess.map[y][x] == 'c') {
        rect = set_knight();
        sfSprite_setTextureRect(main_struct->pm.chess.chess_board->sprite,
        rect);
        sfSprite_setPosition(main_struct->pm.chess.chess_board->sprite, pos);
        sfRenderWindow_drawSprite(main_struct->window,
        main_struct->pm.chess.chess_board->sprite, NULL);
    }
}

void put_pieces(main_t *main_struct)
{
    sfIntRect rect;

    for (int y = 0; y < 8; y += 1) {
        for (int x = 0; x < 8; x += 1) {
            render_king(main_struct, rect, y, x);
            render_queen(main_struct, rect, y, x);
            render_bishop(main_struct, rect, y, x);
            render_knight(main_struct, rect, y, x);
            render_rook(main_struct, rect, y, x);
            render_pawn(main_struct, rect, y, x);
        }
    }
}