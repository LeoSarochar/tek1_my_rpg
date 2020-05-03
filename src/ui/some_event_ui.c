/*
** EPITECH PROJECT, 2020
** ui_event
** File description:
** rpg
*/

#include "screen_menu.h"
#include "main.h"
#include "csfml_binding.h"
#include "first_plan_screen.h"

void modif_statement2(main_t *glob)
{
    if (glob->s_menu.state_button == 1)
        glob->s_menu.bol_menu = 0;
    if (glob->s_menu.state_button == 2) {
        if (glob->s_menu.bol_c_o == 0)
            glob->s_menu.bol_c_o = 1;
        else
            glob->s_menu.bol_c_o = 0;
    }
}

void modif_statement(main_t *glob)
{
    modif_statement2(glob);
    if (glob->s_menu.state_button == 3) {
        if (glob->s_menu.bol_c_o == 0)
            glob->s_menu.bol_c_o = 2;
        else
            glob->s_menu.bol_c_o = 0;
    }
    if (glob->s_menu.state_button == 4)
        close_window(glob, glob->event);
}