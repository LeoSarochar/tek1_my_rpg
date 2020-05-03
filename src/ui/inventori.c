/*
** EPITECH PROJECT, 2020
** inventori
** File description:
** rpg
*/

#include "screen_menu.h"
#include "main.h"
#include "csfml_binding.h"
#include "first_plan_screen.h"

void find_item(main_t *glob, sfVector2i cursor)
{
    for (int i = 0; i < 6; i++) {
        if (cursor.x > 730 && cursor.x < 798 && cursor.y > 403 &&
            cursor.y < 469 && glob->s_menu.item[i]->num == 0 &&
            glob->s_menu.item[i]->state == 1) {
            glob->s_menu.item[i]->state = 2;
            glob->s_menu.item[i]->num = -1;
        }
        if (cursor.x > 803 && cursor.x < 872 && cursor.y > 406 &&
            cursor.y < 467 && glob->s_menu.item[i]->num == 1 &&
            glob->s_menu.item[i]->state == 1) {
            glob->s_menu.item[i]->state = 2;
            glob->s_menu.item[i]->num = -1;
        }
        find_item2(glob, cursor, i);
    }
}

int assign_num(main_t *glob)
{
    int ref = 0;
    int ref2 = 0;
    int n;

    for (n = 0; n < 6 || ref == n; n++) {
        ref = n;
        for (int i = 0; i < 6; i++)
            (glob->s_menu.item[i]->num == n) ? (ref++) : 0;
        if (ref == ref2)
            break;
        else
            ref2++;
    }
    return (ref);
}

void find_wear(main_t *glob, sfVector2i cursor)
{
    for (int i = 0; i < 6; i++) {
        if (cursor.x > 982 && cursor.x < 1050 && cursor.y > 403 &&
            cursor.y < 466 && glob->s_menu.item[i]->id == 0 &&
            glob->s_menu.item[i]->state == 2) {
            glob->s_menu.item[i]->state = 1;
            glob->s_menu.item[i]->num = assign_num(glob);
        }
        if (cursor.x > 909 && cursor.x < 978 && cursor.y > 485 &&
            cursor.y < 549 && glob->s_menu.item[i]->id == 1 &&
            glob->s_menu.item[i]->state == 2) {
            glob->s_menu.item[i]->state = 1;
            glob->s_menu.item[i]->num = assign_num(glob);
        }
        find_wear2(glob, cursor, i);
    }
}

void get_mouse(main_t *glob)
{
    sfVector2i cursor = sfMouse_getPositionRenderWindow(glob->window);

    if (cursor.x > 730 && cursor.x < 873 && glob->event.type == PRESS)
        if (cursor.y > 403 && cursor.y < 607)
            find_item(glob, cursor);
    if (cursor.x > 905 && cursor.x < 1123 && glob->event.type == PRESS)
        if (cursor.y > 397 && cursor.y < 716)
            find_wear(glob, cursor);
}

void wear_stuff(item_t *item, main_t *glob)
{
    (item->state == 2 && item->id == 0) ? SP(item->sprite, VEC(979, 413)) : 0;
    (item->state == 2 && item->id == 1) ? SP(item->sprite, VEC(906, 497)) : 0;
    (item->state == 2 && item->id == 2) ? SP(item->sprite, VEC(981, 497)) : 0;
    (item->state == 2 && item->id == 3) ? SP(item->sprite, VEC(1044, 497)) : 0;
    (item->state == 2 && item->id == 4) ? SP(item->sprite, VEC(979, 575)) : 0;
    (item->state == 2 && item->id == 5) ? SP(item->sprite, VEC(979, 646)) : 0;
    sfRenderWindow_drawSprite(glob->window, item->sprite, NULL);
}