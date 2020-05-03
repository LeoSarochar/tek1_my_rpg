/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** rect_function
*/

#ifndef RECT_FUNCTION_H_
#define RECT_FUNCTION_H_
#include "../init_attribute.h"

void set_rect_sprite(Rect_t *rect, sprite_t *sprite);
void set_rect_letter(Rect_t *rect, int size, sfVector2f pos);
int is_collision(Rect_t rect1, Rect_t rect2);
void check_continue(int *tab, int *ind, int check, char *name);
void waiter_anim(int tab[4], float to_wait, main_t *main_struct, int *ind);
#endif /* !RECT_FUNCTION_H_ */
