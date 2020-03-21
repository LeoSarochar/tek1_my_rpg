
/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** main.c
*/

#include "render.h"

void render(main_t *main_struct)
{
    sfRenderWindow_clear(main_struct->window, sfBlack);
    for (int i = 0; render_funcs[i].ptr != NULL; i++)
        render_funcs[i].ptr(main_struct);
    sfRenderWindow_display(main_struct->window);
}