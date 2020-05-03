/*
** EPITECH PROJECT, 2020
** test_fight_rpg
** File description:
** enemy_turn
*/

#include "fight/attack/enemy_turn.h"

int enem_attack_intel(enemy_t *player, attack_t *attack)
{
    int nb = 0;

    nb = attack->req_intel;
    player->intel -= nb;
    nb += attack->dam_com;
    nb *= 2;
    return (nb);
}

int enem_attack_ram(enemy_t *player, attack_t *attack)
{
    int nb = 0;

    nb = attack->req_ram;
    player->ram -= nb;
    nb += attack->dam_com;
    nb *= 2;
    return (nb);
}

void enem_defense_attack(int dam, enemy_t *player)
{
    int nb = give_rand(80, 100);

    dam -= percent(player->defence, nb);
    player->com -= fabs(dam);
}

void enem_defense_total(enemy_t *player, int dam)
{
    int nb = give_rand(80, 100);

    dam -= percent(player->defence, nb);
    player->com -= dam;
}