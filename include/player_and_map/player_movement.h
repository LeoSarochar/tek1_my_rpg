/*
** EPITECH PROJECT, 2020
** MY_RPG
** File description:
** .h for sm1_init.c
*/

#ifndef MY_PLAYER_MOVEMENT_H_
#define MY_PLAYER_MOVEMENT_H_

#include "../include_all.h"
#include "main.h"

void player_move(main_t *main_struct);
int check_cols_right(main_t *main_struct);
int check_cols_left(main_t *main_struct);
int check_cols_down(main_t *main_struct);
int check_cols_up(main_t *main_struct);
char **get_collision(char *filename);
void go_left(main_t *main_struct);
void go_up(main_t *main_struct);
void go_right(main_t *main_struct);
void go_down(main_t *main_struct);
void change_map_3(main_t *main_struct);

#endif //MY_PLAYER_MOVEMENT_H_
