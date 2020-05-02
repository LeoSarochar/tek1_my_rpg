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
    for (int i = 0; i < 6; i++)
    {
        if (cursor.x > 730 && cursor.x < 798 && cursor.y > 403 && cursor.y < 469 && glob->s_menu.item[i]->num == 0 && glob->s_menu.item[i]->state == 1)
        {
            glob->s_menu.item[i]->state = 2;
            glob->s_menu.item[i]->num = -1;
        }
        if (cursor.x > 803 && cursor.x < 872 && cursor.y > 406 && cursor.y < 467 && glob->s_menu.item[i]->num == 1 && glob->s_menu.item[i]->state == 1)
        {
            glob->s_menu.item[i]->state = 2;
            glob->s_menu.item[i]->num = -1;
        }
        if (cursor.x > 730 && cursor.x < 798 && cursor.y > 474 && cursor.y < 534 && glob->s_menu.item[i]->num == 2 && glob->s_menu.item[i]->state == 1)
        {
            glob->s_menu.item[i]->state = 2;
            glob->s_menu.item[i]->num = -1;
        }
        if (cursor.x > 803 && cursor.x < 872 && cursor.y > 475 && cursor.y < 538 && glob->s_menu.item[i]->num == 3 && glob->s_menu.item[i]->state == 1)
        {
            glob->s_menu.item[i]->state = 2;
            glob->s_menu.item[i]->num = -1;
        }
        if (cursor.x > 730 && cursor.x < 798 && cursor.y > 541 && cursor.y < 605 && glob->s_menu.item[i]->num == 5 && glob->s_menu.item[i]->state == 1)
        {
            glob->s_menu.item[i]->state = 2;
            glob->s_menu.item[i]->num = -1;
        }
        if (cursor.x > 803 && cursor.x < 870 && cursor.y > 541 && cursor.y < 605 && glob->s_menu.item[i]->num == 4 && glob->s_menu.item[i]->state == 1)
        {
            glob->s_menu.item[i]->state = 2;
            glob->s_menu.item[i]->num = -1;
        }
    }
}

int assign_num(main_t *glob)
{
    int ref = 0;
    int ref2 = 0;
    int n;
    for (n = 0; n < 6 || ref == n; n++) {
        ref = n;
        for(int i = 0; i < 6; i++)
            (glob->s_menu.item[i]->num == n) ? ref++ : 0;
            if(ref == ref2)
                break;
            else
                ref2++;
    }
    return (ref);
}

void find_wear(main_t *glob, sfVector2i cursor)
{
    for (int i = 0; i < 6; i++)
    {
        if (cursor.x > 982 && cursor.x < 1050 && cursor.y > 403 && cursor.y < 466 && glob->s_menu.item[i]->id == 0 && glob->s_menu.item[i]->state == 2)
        {
            glob->s_menu.item[i]->state = 1;
            glob->s_menu.item[i]->num = assign_num(glob);
        }
        if (cursor.x > 909 && cursor.x < 978 && cursor.y > 485 && cursor.y < 549 && glob->s_menu.item[i]->id == 1 && glob->s_menu.item[i]->state == 2)
        {
            glob->s_menu.item[i]->state = 1;
            glob->s_menu.item[i]->num = assign_num(glob);
        }
        if (cursor.x > 964 && cursor.x < 1050 && cursor.y > 484 && cursor.y < 551 && glob->s_menu.item[i]->id == 2 && glob->s_menu.item[i]->state == 2)
        {
            glob->s_menu.item[i]->state = 1;
            glob->s_menu.item[i]->num = assign_num(glob);
        }
        if (cursor.x > 1053 && cursor.x < 1121 && cursor.y > 489 && cursor.y < 548 && glob->s_menu.item[i]->id == 3 && glob->s_menu.item[i]->state == 2)
        {
            glob->s_menu.item[i]->state = 1;
            glob->s_menu.item[i]->num = assign_num(glob);
        }
        if (cursor.x > 983 && cursor.x < 1051 && cursor.y > 555 && cursor.y < 617 && glob->s_menu.item[i]->id == 4 && glob->s_menu.item[i]->state == 2)
        {
            glob->s_menu.item[i]->state = 1;
            glob->s_menu.item[i]->num = assign_num(glob);
        }
        if (cursor.x > 984 && cursor.x < 1052 && cursor.y > 626 && cursor.y < 687 && glob->s_menu.item[i]->id == 5 && glob->s_menu.item[i]->state == 2)
        {
            glob->s_menu.item[i]->state = 1;
            glob->s_menu.item[i]->num = assign_num(glob);
        }
    }
}

void get_mouse(main_t *glob)
{
    sfVector2i cursor = sfMouse_getPositionRenderWindow(glob->window);
    if (cursor.x > 730 && cursor.x < 873 && glob->event.type == sfEvtMouseButtonPressed)
    {
        if (cursor.y > 403 && cursor.y < 607)
            find_item(glob, cursor);
    }
    if (cursor.x > 905 && cursor.x < 1123 && glob->event.type == sfEvtMouseButtonPressed)
        if (cursor.y > 397 && cursor.y < 716)
            find_wear(glob, cursor);
}

void wear_stuff(item_t *item, main_t *glob)
{
    (item->state == 2 && item->id == 0) ? sfSprite_setPosition(item->sprite, (sfVector2f){979, 413}) : 0;
    (item->state == 2 && item->id == 1) ? sfSprite_setPosition(item->sprite, (sfVector2f){906, 497}) : 0;
    (item->state == 2 && item->id == 2) ? sfSprite_setPosition(item->sprite, (sfVector2f){981, 497}) : 0;
    (item->state == 2 && item->id == 3) ? sfSprite_setPosition(item->sprite, (sfVector2f){1044, 497}) : 0;
    (item->state == 2 && item->id == 4) ? sfSprite_setPosition(item->sprite, (sfVector2f){979, 575}) : 0;
    (item->state == 2 && item->id == 5) ? sfSprite_setPosition(item->sprite, (sfVector2f){979, 646}) : 0;
    sfRenderWindow_drawSprite(glob->window, item->sprite, NULL);
}