/*
** EPITECH PROJECT, 2020
** test_fight_rpg
** File description:
** init_attribute
*/

#include "fight/init_attribute.h"

void init_state(state_t *state)
{
    state->is_alive = 1;
    state->is_dem = 0;
    state->is_tired = 0;
    state->can_attack = 0;
}

void preset_init(preset_list_t **list)
{
    int tab[4];

    set_int_table(4, tab, (int []){10, 0, 1, 0});
    add_element_pres(list, create_preset(tab, "my_putchar"));
    set_int_table(4, tab, (int []){10, 0, 1, 0});
    add_element_pres(list, create_preset(tab, "my_strlen"));
    set_int_table(4, tab, (int []){15, 0, 1, 5});
    add_element_pres(list, create_preset(tab, "my_putstr"));
}

void init_player(main_t *main_struct)
{
    main_struct->player = malloc(sizeof(player_t));
    main_struct->player->preset = NULL;
    main_struct->player->attacks = NULL;
    main_struct->player->xp = 50;
    main_struct->player->force = 10;
    main_struct->player->com = 100;
    main_struct->player->defence = 10;
    main_struct->player->gpa = 0.0;
    main_struct->player->intel = 10;
    main_struct->player->name = "main player";
    main_struct->player->speed = 10;
    main_struct->player->com_max = 100;
    main_struct->player->sprite = NULL;
    main_struct->player->attacks = NULL;
    init_state(&main_struct->player->state);
    preset_init(&main_struct->player->preset);
    add_element_att(&main_struct->player->attacks, \
    create_attack(main_struct->player->preset->preset));
}