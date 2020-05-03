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
    for (int i = 0; i < 4; i++) {
        glob->s_menu.button[i]->rect = (sfIntRect){0, 0, 330, 220};
        SSTR(glob->s_menu.button[i]->sprite, glob->s_menu.button[i]->rect);
    }
}

void basic_button_pause(main_t *glob)
{
    for (int i = 0; i < 4; i++) {
        glob->s_menu.button_pause[i]->rect = (sfIntRect){0, 0, 330, 220};
        SSTR(GBPS, glob->s_menu.button_pause[i]->rect);
    }
}

void button_effect(main_t *glob)
{
    PAT1->time_butt = CET(PAT1->clock);
    PAT1->sec = PAT1->time_butt.microseconds / 10000000.0;
    if (PAT1->sec > 0.015) {
        if (PAT1->rect.left < 700) {
            PAT1->rect = move_rect_button(PAT1->rect, 330, 990);
            sfSprite_setTextureRect(PAT1->sprite, PAT1->rect);
        }
        CR(PAT1->clock);
    }
}

void button_effect_pause(main_t *glob)
{
    PAT2->time_butt = sfClock_getElapsedTime(PAT2->clock);
    PAT2->sec = PAT2->time_butt.microseconds / 10000000.0;
    if (PAT2->sec > 0.015) {
        if (PAT2->rect.left < 700) {
            PAT2->rect = move_rect_button(PAT2->rect, 330, 990);
            sfSprite_setTextureRect(PAT2->sprite, PAT2->rect);
        }
        CR(glob->s_menu.button[glob->s_menu.state_button - 1]->clock);
    }
}
