/*
** EPITECH PROJECT, 2020
** test_fight_rpg
** File description:
** turn
*/

#include "fight/attack/turn.h"

int give_best_attack(attack_list_t *attack)
{
    int nb = 1;
    int test = 0;
    attack_list_t *tmp = attack;
    int sauv = tmp->attack->dam_com;

    for (int i = 0; tmp; tmp = tmp->next, i += 1)
        if (tmp->attack->dam_com > sauv) {
            test = give_rand(0, 1);
            sauv = (test == 0) ? tmp->attack->dam_com : sauv;
            nb = (test == 0) ? i : nb;
        }
    return (nb);
}

void enemy_turn_attack(player_t *player, enemy_t *enemy, int todo)
{
    int nb = give_best_attack(player->attacks);
    attack_t *tmp = get_element_att(player->attacks, nb);

    if (tmp->req_intel > 0)
        nb = enem_attack_intel(enemy, tmp);
    else if (tmp->req_ram > 0)
        nb = enem_attack_ram(enemy, tmp);
    else
        nb = enem_attack_force(enemy, tmp->dam_com);
    (todo == 1) ? player_defense_attack(nb, player) \
    : player_defense_total(player, nb);
}

void player_attack_turn(player_t *player, enemy_t *enemy, attack_t *attack)
{
    int nb = 0;

    if (attack->req_intel > 0)
        nb = player_attack_intel(player, attack);
    else if (attack->req_ram > 0)
        nb = player_attack_ram(player, attack);
    else
        nb = player_attack_force(player, attack->dam_com);
    enem_defense_attack(nb, enemy);
}

int pos_attack(sprite_t *cursor)
{
    if (cursor->pos.x == 100 && cursor->pos.y == 800)
        return (1);
    if (cursor->pos.x == 100 && cursor->pos.y == 900)
        return (2);
    if (cursor->pos.x == 1500 && cursor->pos.y == 800)
        return (3);
    if (cursor->pos.x == 1500 && cursor->pos.y == 900)
        return (4);
    return (1);
}

void analyse_attack(main_t *main_struct, fight_scene_t *scene)
{
    int i = 0;

    if (scene->var.menu == 1) {
        i = pos_attack(scene->cursor);
        player_attack_turn(main_struct->player, scene->enemies->enemy, \
        get_element_att(main_struct->player->attacks, i));
        enemy_turn_attack(main_struct->player, scene->enemies->enemy, 0);
        scene->var.menu = 0;
    }
    if (scene->var.menu == 2) {
        enemy_turn_attack(main_struct->player, scene->enemies->enemy, 1);
        scene->var.menu = 0;
    }
}