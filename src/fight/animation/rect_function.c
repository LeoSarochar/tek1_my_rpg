/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** rect_function
*/

#include "fight/init_attribute.h"

void set_rect_sprite(Rect_t *rect, sprite_t *sprite)
{
    rect->height = sprite->rect->height;
    rect->width = sprite->rect->width;
    rect->x = sprite->pos.x;
    rect->y = sprite->pos.y;
}

void set_rect_letter(Rect_t *rect, int size, sfVector2f pos)
{
    rect->height = size;
    rect->width = size;
    rect->x = pos.x;
    rect->y = pos.y;
}

int is_collision(Rect_t rect1, Rect_t rect2)
{
    int xMinA = rect1.x;
    int xMaxA = rect1.x + rect1.width;
    int yMinA = rect1.y;
    int yMaxA = rect1.y + rect1.height;
    int xMinB = rect2.x;
    int xMaxB = rect2.x + rect2.width;
    int yMinB = rect2.y;
    int yMaxB = rect2.y + rect2.height;

    if (xMinA > xMaxB || xMaxA < xMinB || yMinA > yMaxB || yMaxA < yMinB)
        return (0);
    return (1);
}

void check_continue(int *tab, int *ind, int check, char *name)
{
    *tab = (check == -1) ? -1 : *tab;
    if (*tab == -1 || check < 0)
        return;
    *ind = (check + 4 < my_strlen(name)) ? check + 4 : *ind;
    *tab = *ind;
}

void waiter_anim(int tab[4], float to_wait, main_t *main_struct, int *ind)
{
    sfClock *clock = sfClock_create();
    sfTime time;
    float seconds = 0.0;
    int check = 0;

    for (int i = 0; i < 4; i += 1)
        check = (tab[i] == -1) ? check + 1 : check;
    if (check == 4) {
        main_struct->player->fight_scene->var.menu = 10;
        *ind = 0;
        return;
    }
    do {
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 1000000.0;
    } while (seconds < to_wait);
    sfClock_destroy(clock);
}