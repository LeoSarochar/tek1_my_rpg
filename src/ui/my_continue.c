/*
** EPITECH PROJECT, 2020
** following fonction
** File description:
** rpg
*/

#include "screen_menu.h"
#include "main.h"
#include "csfml_binding.h"
#include "first_plan_screen.h"

void find_wear3(main_t *glob, sfVector2i cursor, int i)
{
    if (cursor.x > 984 && cursor.x < 1052 && cursor.y > 626 &&
        cursor.y < 687 && glob->s_menu.item[i]->id == 5 &&
        glob->s_menu.item[i]->state == 2) {
        glob->s_menu.item[i]->state = 1;
        glob->s_menu.item[i]->num = assign_num(glob);
    }
}

void find_wear2(main_t *glob, sfVector2i cursor, int i)
{
    if (cursor.x > 964 && cursor.x < 1050 && cursor.y > 484 &&
        cursor.y < 551 && glob->s_menu.item[i]->id == 2 &&
        glob->s_menu.item[i]->state == 2) {
        glob->s_menu.item[i]->state = 1;
        glob->s_menu.item[i]->num = assign_num(glob);
    }
    if (cursor.x > 1053 && cursor.x < 1121 && cursor.y > 489 &&
        cursor.y < 548 && glob->s_menu.item[i]->id == 3 &&
        glob->s_menu.item[i]->state == 2) {
        glob->s_menu.item[i]->state = 1;
        glob->s_menu.item[i]->num = assign_num(glob);
    }
    if (cursor.x > 983 && cursor.x < 1051 && cursor.y > 555 &&
        cursor.y < 617 && glob->s_menu.item[i]->id == 4 &&
        glob->s_menu.item[i]->state == 2) {
        glob->s_menu.item[i]->state = 1;
        glob->s_menu.item[i]->num = assign_num(glob);
    }
    find_wear3(glob, cursor, i);
}

void find_item3(main_t *glob, sfVector2i cursor, int i)
{
    if (cursor.x > 803 && cursor.x < 870 && cursor.y > 541 &&
        cursor.y < 605 && glob->s_menu.item[i]->num == 4 &&
        glob->s_menu.item[i]->state == 1) {
        glob->s_menu.item[i]->state = 2;
        glob->s_menu.item[i]->num = -1;
    }
}

void find_item2(main_t *glob, sfVector2i cursor, int i)
{
    if (cursor.x > 730 && cursor.x < 798 && cursor.y > 474 &&
        cursor.y < 534 && glob->s_menu.item[i]->num == 2 &&
        glob->s_menu.item[i]->state == 1) {
        glob->s_menu.item[i]->state = 2;
        glob->s_menu.item[i]->num = -1;
    }
    if (cursor.x > 803 && cursor.x < 872 && cursor.y > 475 &&
        cursor.y < 538 && glob->s_menu.item[i]->num == 3 &&
        glob->s_menu.item[i]->state == 1) {
        glob->s_menu.item[i]->state = 2;
        glob->s_menu.item[i]->num = -1;
    }
    if (cursor.x > 730 && cursor.x < 798 && cursor.y > 541 &&
        cursor.y < 605 && glob->s_menu.item[i]->num == 5 &&
        glob->s_menu.item[i]->state == 1) {
        glob->s_menu.item[i]->state = 2;
        glob->s_menu.item[i]->num = -1;
    }
    find_item3(glob, cursor, i);
}

void cond_disp_part(main_t *glob)
{
    if (glob->event.type == PRESS) {
        if (glob->s_menu.state_button == 0 && glob->s_menu.d_p == 0)
            disp_part(glob->part1, glob->window, MOUSE(glob->window), 1);
        else
            disp_part(glob->part2, glob->window, MOUSE(glob->window), 1);
    }
}