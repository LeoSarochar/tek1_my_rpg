/*
** EPITECH PROJECT, 2020
** disp credit
** File description:
** rpg
*/

#include "screen_menu.h"
#include "main.h"
#include "csfml_binding.h"
#include "first_plan_screen.h"

void create_cred(text_menu_t *actual, char *into, sfVector2f pos, int size)
{
    actual->txt1 = sfText_create();
    sfText_setFont(actual->txt1, FCFF("ressources/ui/other/Pixeled.ttf"));
    sfText_setString(actual->txt1, into);
    sfText_setColor(actual->txt1, sfMagenta);
    sfText_setCharacterSize(actual->txt1, size);
    sfText_setPosition(actual->txt1, pos);
}

void init_cred(main_t *glob)
{
    glob->s_menu.cred = malloc(sizeof(text_menu_t *) * (4));
    for (int j = 0; j < 4; j += 1)
        glob->s_menu.cred[j] = malloc(sizeof(text_menu_t));
    create_cred(glob->s_menu.cred[0], "Leo Sarochar", VEC(480, 300), 33);
    create_cred(glob->s_menu.cred[1], "Cedrick Kakou", VEC(480, 375), 33);
    create_cred(glob->s_menu.cred[2], "Louis Boulet", VEC(480, 450), 33);
    create_cred(glob->s_menu.cred[3], "Jose Fernan", VEC(480, 525), 33);
}

void disp_cred(main_t *glob)
{
    if (glob->s_menu.bol_c_o == 1)
        for (int j = 0; j < 4; j += 1)
            RWT(glob->window, glob->s_menu.cred[j]->txt1, NULL);
    if (glob->s_menu.bol_c_o == 2)
        disp_option(glob);
}
