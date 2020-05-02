/*
** EPITECH PROJECT, 2020
** management button
** File description:
** rpg
*/

#include "screen_menu.h"
#include "main.h"
#include "csfml_binding.h"
#include "first_plan_screen.h"

void basic_button(main_t *glob)
{
    for (int i = 0; i < 4; i++){
        glob->s_menu.button[i]->rect = (sfIntRect){0, 0, 330, 220};
        sfSprite_setTextureRect(glob->s_menu.button[i]->sprite, glob->s_menu.button[i]->rect);
    }
}

void basic_button_pause(main_t *glob)
{
    for (int i = 0; i < 4; i++){
        glob->s_menu.button_pause[i]->rect = (sfIntRect){0, 0, 330, 220};
        sfSprite_setTextureRect(glob->s_menu.button_pause[i]->sprite, glob->s_menu.button_pause[i]->rect);
    }
}

void button_effect(main_t *glob)
{
    glob->s_menu.button[glob->s_menu.state_button - 1]->time_butt = sfClock_getElapsedTime(glob->s_menu.button[glob->s_menu.state_button - 1]->clock);
    glob->s_menu.button[glob->s_menu.state_button - 1]->sec = glob->s_menu.button[glob->s_menu.state_button - 1]->time_butt.microseconds / 10000000.0;
    if (glob->s_menu.button[glob->s_menu.state_button - 1]->sec > 0.015) {
        if (glob->s_menu.button[glob->s_menu.state_button - 1]->rect.left < 700) {
            glob->s_menu.button[glob->s_menu.state_button - 1]->rect = move_rect_button(glob->s_menu.button[glob->s_menu.state_button - 1]->rect, 330, 990);
            sfSprite_setTextureRect(glob->s_menu.button[glob->s_menu.state_button - 1]->sprite, glob->s_menu.button[glob->s_menu.state_button - 1]->rect);
        }
        sfClock_restart(glob->s_menu.button[glob->s_menu.state_button - 1]->clock);
    }
}

void button_effect_pause(main_t *glob)
{
    glob->s_menu.button_pause[glob->s_menu.state_button - 1]->time_butt = sfClock_getElapsedTime(glob->s_menu.button_pause[glob->s_menu.state_button - 1]->clock);
    glob->s_menu.button_pause[glob->s_menu.state_button - 1]->sec = glob->s_menu.button_pause[glob->s_menu.state_button - 1]->time_butt.microseconds / 10000000.0;
    if (glob->s_menu.button_pause[glob->s_menu.state_button - 1]->sec > 0.015) {
        if (glob->s_menu.button_pause[glob->s_menu.state_button - 1]->rect.left < 700) {
            glob->s_menu.button_pause[glob->s_menu.state_button - 1]->rect = move_rect_button(glob->s_menu.button_pause[glob->s_menu.state_button - 1]->rect, 330, 990);
            sfSprite_setTextureRect(glob->s_menu.button_pause[glob->s_menu.state_button - 1]->sprite, glob->s_menu.button_pause[glob->s_menu.state_button - 1]->rect);
        }
        sfClock_restart(glob->s_menu.button[glob->s_menu.state_button - 1]->clock);
    }
}
