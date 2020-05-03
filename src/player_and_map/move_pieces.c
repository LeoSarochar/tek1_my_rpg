/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** sm1_init.c
*/

#include "player_and_map/sm1_init.h"
#include "main.h"

void move_pieces(main_t *main, sfEvent event)
{
    int x = 0;
    int y = 0;
    sfVector2i cursor = sfMouse_getPositionRenderWindow(main->window);
    if (main->pm.player.scene == 3) {
        x = cursor.x / 64;
        y = cursor.y / 64;
        if (x <= 7 && y <= 7)
            main->pm.chess.map[y][x] = '0';
    }
}