/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** destroyer
*/

#include "fight/linked_list_library/destroyer.h"

void destroy_attack(attack_list_t *attack)
{
    attack_list_t *tmp = attack;

    for(; attack; tmp = attack) {
        attack = attack->next;
        free(tmp->attack);
        free(tmp);
    }
}

void free_enem(enemy_list_t *enemy)
{
    enemy_list_t *tmp = enemy;

    for (; enemy; tmp = enemy) {
        enemy = enemy->next;
        destroy_attack(tmp->enemy->attacks);
        free(tmp->enemy->sprite->rect);
        sfSprite_destroy(tmp->enemy->sprite->sprite);
        free(tmp->enemy->sprite);
        free(tmp->enemy);
        free(tmp);
    }
}