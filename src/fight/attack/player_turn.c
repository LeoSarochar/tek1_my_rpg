/*
** EPITECH PROJECT, 2020
** test_fight_rpg
** File description:
** turn
*/

#include "fight/attack/player_turn.h"

int player_attack_force(player_t *player, int attack)
{
    int nb = 0;
    int ret = 0;

    ret = give_rand(80, 100);
    nb = percent(player->force, ret);
    nb += attack;
    return (nb);
}

int player_attack_intel(player_t *player, attack_t *attack)
{
    int nb = 0;

    nb = attack->req_intel;
    player->intel -= nb;
    nb += attack->dam_com;
    nb *= 2;
    return (nb);
}

int player_attack_ram(player_t *player, attack_t *attack)
{
    int nb = 0;

    nb = attack->req_ram;
    player->ram -= nb;
    nb += attack->dam_com;
    nb *= 2;
    return (nb);
}

void player_defense_attack(int dam, player_t *player)
{
    int nb = 0;
    int vit = 0;

    vit = percent(player->speed, 40);
    nb = (vit <= player->speed) ? give_rand(1, 20) : give_rand(1, 10);
    dam -= nb;
    player->com -= dam;
}

void player_defense_total(player_t *player, int dam)
{
    int nb = give_rand(80, 100);

    nb = percent(player->defence, nb);
    dam -= nb;
    player->com -= dam;
}