/*
** EPITECH PROJECT, 2020
** main screen menu
** File description:
** call fonction for go on the menu
*/

#include "screen_menu.h"
#include "main.h"
#include "csfml_binding.h"
#include "first_plan_screen.h"

void find_button(main_t *glob, sfVector2i cursor)
{
    if (cursor.y > 190 && cursor.y < 330)
        glob->s_menu.state_button = 1;
    if (cursor.y > 340 && cursor.y < 480)
        glob->s_menu.state_button = 2;
    if (cursor.y > 490 && cursor.y < 630)
        glob->s_menu.state_button = 3;
    if (cursor.y > 640 && cursor.y < 780)
        glob->s_menu.state_button = 4;
}

void mouse_position(main_t *glob, sfRenderWindow *window)
{
    sfVector2i cursor = sfMouse_getPositionRenderWindow(window);
    if (cursor.x > 1520 && cursor.x < 1800) {
        if ((cursor.y > 190 && cursor.y < 330) ||
            (cursor.y > 340 && cursor.y < 480) ||
            (cursor.y > 490 && cursor.y < 630) ||
            (cursor.y > 640 && cursor.y < 780))
            find_button(glob, cursor);
        else
            glob->s_menu.state_button = 0;
    }
    else
        glob->s_menu.state_button = 0;
}

void screen_menu_order(main_t *glob)
{
    static int realesed = 0;
    static int bol = 0;

    mouse_position(glob, glob->window);
    if (glob->s_menu.state_button != 0) {
        (bol == 0) ? sfSound_play(glob->sound.button_sound), bol++ : 0;
        button_effect(glob);
        if (glob->event.type == sfEvtMouseButtonPressed && realesed == 0){
            modif_statement(glob);
            realesed = 1;
            }
    if (glob->event.type == sfEvtMouseButtonReleased)
        realesed = 0;
    } else {
        bol = 0;
        basic_button(glob);
    }
}

void modif_statement_pause(main_t *glob)
{
    if (glob->s_menu.state_button == 1)
        glob->s_menu.bol_pause = 0;
    if (glob->s_menu.state_button == 2)
        glob->s_menu.bol_menu = 1;
    if (glob->s_menu.state_button == 3) {
        if (glob->s_menu.bol_c_o == 0)
            glob->s_menu.bol_c_o = 2;
        else
            glob->s_menu.bol_c_o = 0;
    }
    if (glob->s_menu.state_button == 4)
        close_window(glob, glob->event);
}

void mouse_position_pause(main_t *glob, sfRenderWindow *window)
{
    sfVector2i cursor = sfMouse_getPositionRenderWindow(window);
    if (cursor.x > 815 && cursor.x < 1095) {
        if ((cursor.y > 190 && cursor.y < 330) ||
            (cursor.y > 340 && cursor.y < 480) ||
            (cursor.y > 490 && cursor.y < 630) ||
            (cursor.y > 640 && cursor.y < 780))
            find_button(glob, cursor);
        else
            glob->s_menu.state_button = 0;
    }
    else
        glob->s_menu.state_button = 0;
}