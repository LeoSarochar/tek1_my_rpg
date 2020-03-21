/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** fight
*/

#include "main.h"

character_t *load_enemy(main_t *main)
{
    character_t *player = malloc(sizeof(*player));
    int speed = (rand() % (10 - main->player->speed)) + main->player->speed;

    player->commitment = 100;
    player->gpa = 0.0;
    player->guard = (rand() % ((main->player->guard + 5) \
    - (main->player->guard - 5) + 1)) + (main->player->guard - 5);
    player->height = 64;
    player->width = 64;
    player->intellect = (rand() % ((main->player->intellect + 5) \
    - (main->player->intellect - 5) + 1)) + (main->player->intellect - 5);
    player->posiion = (sfVector2f){0, 0};
    player->speed = (speed > main->player->speed) ? 10 : 0;
    player->xp = 0;
    return (player);
}

void init_enemy(main_t *main, list_t **enemy)
{
    int nb_enem = rand() % (4) + 1;
    character_t *enem = NULL;

    for (int i = 0; i < nb_enem; i += 1) {
        enem = load_enemy(main);
        add_element(enemy, enem);
    }
}

void print_attributes(list_t *enemy)
{
    for (int i = 1; enemy; enemy = enemy->next, i += 1) {
        printf("i = %d\n", i);
        printf("commitment  = %d\n", enemy->charachter->commitment);
        printf("gpa = %.1f\n", enemy->charachter->gpa);
        printf("guard = %d\n", enemy->charachter->guard);
        printf("intellect = %d\n", enemy->charachter->intellect);
        printf("speed = %d\n\n", enemy->charachter->speed);
    }
}

void fight(main_t *main)
{
    srand(time(NULL));
    list_t *enemy = NULL;

    init_enemy(main, &enemy);
    print_attributes(enemy);
}