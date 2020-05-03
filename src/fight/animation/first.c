/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** first
*/

#include "fight/init_attribute.h"

int anim_fsquare_letter(main_t *main, enemy_t *enemy, char *att, int ind)
{
    static int x = 1100;
    static int y = 120;
    static int previous = -1;
    int check = is_collision(enemy->rect, (Rect_t){x, y, 50, 50});
    char tmp = att[ind];

    if (previous == ind) {
        previous = -1;
        return (-1);
    }
    if (check) {
        x = 1100;
        y = 120;
        previous = ind;
        return (ind);
    }
    y += 1;
    draw_text(main, &tmp, (sfVector2f){x, y}, 50);
    return (-2);
}

int anim_ssquare_letter(main_t *main, enemy_t *enemy, char *att, int ind)
{
    static int x = 900;
    static int y = 200;
    static int previous = -1;
    int check = is_collision(enemy->rect, (Rect_t){x, y, 50, 50});
    char tmp = att[ind];

    if (previous == ind) {
        previous = -1;
        return (-1);
    }
    if (check) {
        x = 930;
        y = 200;
        previous = ind;
        return (ind);
    }
    x += 1;
    draw_text(main, &tmp, (sfVector2f){x, y}, 50);
    return (-2);
}

int anim_tsquare_letter(main_t *main, enemy_t *enemy, char *att, int ind)
{
    static int x = 1100;
    static int y = 600;
    static int previous = -1;
    int check = is_collision(enemy->rect, (Rect_t){x, y, 50, 50});
    char tmp = att[ind];

    if (previous == ind) {
        previous = -1;
        return (-1);
    }
    if (check) {
        x = 1100;
        y = 600;
        previous = ind;
        return (ind);
    }
    y -= 2;
    draw_text(main, &tmp, (sfVector2f){x, y}, 50);
    return (-2);
}

int anim_fosquare_letter(main_t *main, enemy_t *enemy, char *att, int ind)
{
    static int x = 1500;
    static int y = 200;
    static int previous = -1;
    int check = is_collision(enemy->rect, (Rect_t){x, y, 50, 50});
    char tmp = att[ind];

    if (previous == ind) {
        previous = -1;
        return (-1);
    }
    if (check == 1) {
        x = 1500;
        y = 200;
        previous = ind;
        return (ind);
    }
    x -= 2;
    draw_text(main, &tmp, (sfVector2f){x, y}, 50);
    return (-2);
}

void square_anim(main_t *main, enemy_t *enemy, char *name)
{
    static int ind = 0;
    static int tab[4] = {-1, -1, -1, -1};
    int check = 0;

    tab[0] = (name[ind] && is_same(0, ind, tab) == 0) ? ind++ : tab[0];
    tab[1] = (name[ind] && is_same(1, ind, tab) == 0) ? ind++ : tab[1];
    tab[2] = (name[ind] && is_same(2, ind, tab) == 0) ? ind++ : tab[2];
    tab[3] = (name[ind] && is_same(3, ind, tab) == 0) ? ind : tab[3];

    draw_text(main, "player a code: ", (sfVector2f){100, 800}, 75);
    draw_text(main, name, (sfVector2f){1000, 800}, 75);
    check = anim_fsquare_letter(main, enemy, name, tab[0]);
    check_continue(&tab[0], &ind, check, name);
    check = anim_ssquare_letter(main, enemy, name, tab[1]);
    check_continue(&tab[1], &ind, check, name);
    check = anim_tsquare_letter(main, enemy, name, tab[2]);
    check_continue(&tab[2], &ind, check, name);
    check = anim_fosquare_letter(main, enemy, name, tab[3]);
    check_continue(&tab[3], &ind, check, name);
    waiter_anim(tab, 0.0005, main, &ind);
}