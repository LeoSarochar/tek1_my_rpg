/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** event_fight
*/

#include "main.h"

void analyse_fight_event(main_t *main, sprite_t *sprite, fight_t *fight)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp))
        sprite->pos.y = (sprite->pos.y != 800) ? 800 : 900;
    if (sfKeyboard_isKeyPressed(sfKeyDown))
        sprite->pos.y = (sprite->pos.y != 900) ? 900 : 800;
    if (sfKeyboard_isKeyPressed(sfKeyLeft))
        sprite->pos.x = (sprite->pos.x != 100) ? 100 : 1500;
    if (sfKeyboard_isKeyPressed(sfKeyRight))
        sprite->pos.x = (sprite->pos.x != 1500) ? 1500 : 100;
    if (main->event.type == sfEvtClosed)
        sfRenderWindow_close(main->window);
}