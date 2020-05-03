/*
** EPITECH PROJECT, 2020
** MY_RPG
** File description:
** .h for sm1_init.c
*/

#ifndef MY_SM1_INIT_H_
#define MY_SM1_INIT_H_

#include "../include_all.h"
#include "main.h"

void put_map_sm1(main_t *main_struct);
void put_corridor(main_t *main_struct);
void put_player(main_t *main_struct);
void init_perso(main_t *main_struct);
void init_map(main_t *main_struct);
void init_corridor(main_t *main_struct);
char **get_collision(char *filename);
sprite_t *load_sprite_player(char const *file_name);
sfIntRect set_king(void);
sfIntRect set_queen(void);
sfIntRect set_bishop(void);
sfIntRect set_knight(void);
sfIntRect set_rook(void);
sfIntRect set_pawn(void);
void render_rook(main_t *main_struct, sfIntRect rect, int y, int x);
void render_pawn(main_t *main_struct, sfIntRect rect, int y, int x);
void put_pieces(main_t *main_struct);
void putblack_pieces(main_t *main_struct);
sfIntRect setblack_king(void);
sfIntRect setblack_queen(void);
sfIntRect setblack_bishop(void);
sfIntRect setblack_knight(void);
sfIntRect setblack_rook(void);
sfIntRect setblack_pawn(void);
void renderblack_rook(main_t *main_struct, sfIntRect rect, int y, int x);
void renderblack_pawn(main_t *main_struct, sfIntRect rect, int y, int x);


#endif //MY_SM1_INIT_H_