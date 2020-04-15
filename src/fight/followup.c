/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** followup
*/

#include "main.h"

void init_sprite(att_list_t *enemy, main_t *main_struct, char *path)
{
    set_position(&enemy->attack.sprite->pos, 1500, 400);
    edit_rect(enemy->attack.sprite, 92, path);
    draw_sprite(main_struct, enemy->attack.sprite);
}

void display_player(character_t *player, main_t *main_struct, char *path)
{
    set_position(&player->sprite->pos, 100, 400);
    edit_rect(player->sprite, 57, path);
    draw_sprite(main_struct, player->sprite);
}