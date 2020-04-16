/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_attribute
*/

#include "main.h"

static const attack_t attack[4] = {
    {0, 0, 50, 0, 0, 0, "my_printf", NULL, {0}},
    {0, 0, 15, 0, 0, 0, "my_strlen", NULL, {0}},
    {0, 0, 15, 0, 0, 0, "my_putstr", NULL, {0}},
    {0, 0, 100, 0, 0, 0, "github", NULL, {0}},
};

void init_state(state_t *state)
{
    state->is_alive = 1;
    state->is_dem = 0;
    state->is_tired = 0;
    state->can_attack = 0;
}

void init_character(main_t *main)
{
    main->player = malloc(sizeof(character_t));
    main->player->commitment = 500;
    main->player->gpa = 0.0;
    main->player->guard = 10;
    main->player->xp = 0;
    main->player->intellect = 10;
    main->player->speed = 10;
    main->player->posiion = (sfVector2f){0, 0};
    init_state(&main->player->state);
    init_preset(&main->player->preset);
    main->player->sprite = load_sprite("ressources/stance_naruto.png");
    main->player->list = NULL;
    for (int i = 0; i < 4; i += 1)
        add_element_attack(&main->player->list, attack[i]);
}