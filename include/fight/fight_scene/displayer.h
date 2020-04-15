/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** displayer
*/

#ifndef DISPLAYER_H_
#define DISPLAYER_H_
#include "main.h"

void draw_sprite(main_t *main, sprite_t *sprite);
void draw_text(main_t *main, char *to_write, sfVector2f pos);
void set_position(sfVector2f *pos, int pos_x, int pos_y);
void edit_rect(sprite_t *sprite, int offset, char *path);
void move_rect(sprite_t *sprite);
#endif /* !DISPLAYER_H_ */
