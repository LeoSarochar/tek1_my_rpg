
/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** main.c
*/

#include "render.h"

void render(main_t *main_struct)
{
    if (main_struct->s_menu.inv.disp == 1)
        render_inv(main_struct);
    else {
        sfRenderWindow_clear(main_struct->window, sfBlack);
        for (int i = 0; render_funcs[i].ptr != NULL; i++)
            render_funcs[i].ptr(main_struct);
        gest_view(main_struct);
        render_fight(main_struct, main_struct->player->fight_scene);
    }
    sfRenderWindow_display(main_struct->window);
}