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
    add_element_pres(list, create_preset(25, "My_strlen"));
    add_element_pres(list, create_preset(35, "My_putstr"));
    add_element_pres(list, create_preset(65, "La vie d'artiste"));
    add_element_pres(list, create_preset(60, "Nuit blanche"));
    add_element_pres(list, create_preset(80, "Mauvais nom de repo"));
    add_element_pres(list, create_preset(55, "Trotinnette en sm1"));
    add_element_pres(list, create_preset(95, "Criterion"));
    add_element_pres(list, create_preset(85, "Makefile"));
    add_element_pres(list, create_preset(90, "8h45"));
    add_element_pres(list, create_preset(87, \
    "Je n'arrive pas à clone ton repo"));
}

void init_player(main_t *main_struct)
{
    srand(time(NULL));
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
    main_struct->player->fight_scene = NULL;
    init_state(&main_struct->player->state);
    preset_init(&main_struct->player->preset);
    add_element_att(&main_struct->player->attacks, \
    create_attack(main_struct->player->preset->preset));
}