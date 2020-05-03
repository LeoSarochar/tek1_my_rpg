/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** destroyer
*/

#include "fight/linked_list_library/destroyer.h"

void destroy_sprite(sprite_t **sprite)
{
    free((*sprite)->rect);
    sfSprite_destroy((*sprite)->sprite);
    free((*sprite));
}

void destroy_attack(attack_list_t **attack)
{
    attack_list_t *tmp = (*attack);

    for (; (*attack); tmp = (*attack)) {
        (*attack) = (*attack)->next;
        free(tmp->attack);
        free(tmp);
    }
}

void free_enem(enemy_list_t **enemy)
{
    enemy_list_t *tmp = (*enemy);

    for (; (*enemy); tmp = (*enemy)) {
        (*enemy) = (*enemy)->next;
        destroy_attack(&tmp->enemy->attacks);
        destroy_sprite(&tmp->enemy->sprite);
        free(tmp->enemy);
        free(tmp);
    }
}

void destroy_fight_scene(main_t *main_struct)
{
    destroy_sprite(&main_struct->player->fight_scene->bg);
    destroy_sprite(&main_struct->player->fight_scene->black);
    destroy_sprite(&main_struct->player->fight_scene->cursor);
    destroy_sprite(&main_struct->player->fight_scene->green);
    destroy_sprite(&main_struct->player->fight_scene->menu);
    destroy_sprite(&main_struct->player->fight_scene->red);
    destroy_sprite(&main_struct->player->fight_scene->black_pl);
    destroy_sprite(&main_struct->player->fight_scene->red_pl);
    free_enem(&main_struct->player->fight_scene->enemies);
    free(main_struct->player->fight_scene);
    main_struct->player->fight_scene = NULL;
}