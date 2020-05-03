/*
** EPITECH PROJECT, 2020
** order execution management
** File description:
** rpg
*/

#include "screen_menu.h"
#include "main.h"
#include "csfml_binding.h"
#include "first_plan_screen.h"

void exec_pause(main_t *struct_main)
{
    static int bol = 0;
    static int rea = 0;

    mouse_position_pause(struct_main, struct_main->window);
    if (struct_main->s_menu.state_button != 0) {
        (bol == 0) ? sfSound_play(struct_main->sound.button_sound), bol++ : 0;
        button_effect_pause(struct_main);
        if (struct_main->event.type == sfEvtMouseButtonPressed && rea == 0) {
            modif_statement_pause(struct_main);
            rea = 1;
            }
    } else {
        bol = 0;
        basic_button_pause(struct_main);
    }
    disp_pause(struct_main);
    if (struct_main->event.type == sfEvtMouseButtonReleased)
        rea = 0;
}

void exec_menu(main_t *struct_main)
{
    play_music(struct_main);
    screen_menu_order(struct_main);
    disp_menu(struct_main);
}