/*
** EPITECH PROJECT, 2020
** test_fight_rpg
** File description:
** drawer_function
*/

#ifndef DRAWER_FUNCTION_H_
#define DRAWER_FUNCTION_H_
#include "fight/init_attribute.h"

void draw_text(main_t *main, char *to_write, sfVector2f pos, int size);
void init_sprite(sprite_t **sprite, sfVector2f pos, const char *path);
void draw_sprite(main_t *main, sprite_t *sprite);
void change_sprite(char *filepath, sprite_t **sprite);
#endif /* !DRAWER_FUNCTION_H_ */
