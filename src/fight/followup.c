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
    draw_sprite(main_struct, enemy->attack.sprite);
}

void display_player(character_t *player, main_t *main_struct, char *path)
{
    set_position(&player->sprite->pos, 100, 400);
    edit_rect(player->sprite, 57, path);
    draw_sprite(main_struct, player->sprite);
}

void enemy_turn(character_t *player, attack_t *enemy)
{
    int damage = 0;

    is_good(&enemy->state);
    damage = (enemy->state.can_attack == 0)  \
    ? to_inflict(enemy->dama_com, 5, enemy->speed) : 0;
    to_reduce(&damage, player->guard, player->speed);
    damage = (damage < 0) ? rand() % 21 : damage;
    player->commitment -= damage;
    player->commitment = (player->commitment < 0) ? 0 : player->commitment;
}

void player_turn(character_t *pla, attack_t pl, attack_t *enem, state_t state)
{
    int damage = 0;

    is_good(&pla->state);
    damage = (pla->state.can_attack == 0) \
    ? to_inflict(pl.dama_com, pla->intellect, pla->speed) : 0;
    to_reduce(&damage, enem->defen, enem->speed);
    enem->life -= damage;
    enem->life = (enem->life < 0) ? 0 : enem->life;
}