/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** fight
*/

#include "main.h"

void is_good(state_t *state)
{
    int tmp = 0;

    if (state->is_dem == 1) {
        tmp = rand() % 4;
        state->can_attack = (tmp < 1) ? 0 : 1;
        return;
    }
    if (state->is_tired == 1) {
        tmp = rand() % 4;
        state->can_attack = (tmp < 1) ? 0 : 2;
        return;
    }
}

int to_inflict(int attack, int intel, int speed)
{
    int damage = attack + (intel * 2);
    int tmp = tmp = (rand() % (speed)) + 1;
    int check = (speed * 75) / 100;

    damage += (tmp >= check) ? 10 : 0;
    return (damage);
}

void to_reduce(int *damage, int defence, int speed)
{
    int tmp = (rand() % (100)) + 1;
    int reducer = (speed * tmp) / 100;

    *damage -= (defence + reducer);
}

void fight(main_t *main)
{
    srand(time(NULL));
    list_t *enemy = NULL;
}