/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** second
*/

#include "fight/init_attribute.h"

void set_table(int tab[], int size, int todo)
{
    int y = 450;

    if (todo != 0)
        return;
    for (int i = 0; i < size; i += 1, y += 50)
        tab[i] = y;
}

void drawer(main_t *main, char letter, int y)
{
    char tmp = letter;

    if (y > 450)
        return;
    draw_text(main, &tmp, (sfVector2f){1100, y}, 50);
}

void wait_second(float to_wait)
{
    sfClock *clock = sfClock_create();
    float seconds = 0.0;

    do {
        seconds = sfClock_getElapsedTime(clock).microseconds / 1000000.0;
    } while (seconds < to_wait);
    sfClock_destroy(clock);
}

int to_end(int tab[], int size, main_t *main)
{
    for (int i = 0; i < size; i += 1)
        if (tab[i] != -1)
            return (1);
    main->player->fight_scene->var.menu = 10;
    return (0);
}

void second_anim(main_t *main, Rect_t rect1, char *attack)
{
    static int tab[34];
    static int todo = 0;
    int i = my_strlen(attack);

    draw_text(main, "player a code: ", (sfVector2f){100, 800}, 75);
    draw_text(main, attack, (sfVector2f){1000, 800}, 75);
    set_table(tab, my_strlen(attack), todo);
    for (int k = 0; k < i; k += 1) {
        tab[k] = (tab[k] != -1) ? tab[k] - 50 : tab[k];
        if (is_collision(rect1, (Rect_t){1025, tab[k], 50, 50}) == 1)
            tab[k] = -1;
        (tab[k] != -1) ? drawer(main, attack[k], tab[k]) : 0;
    }
    todo = to_end(tab, i, main);
    (todo == 1) ? wait_second(0.05) : 0;
}