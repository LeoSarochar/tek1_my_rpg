/*
** EPITECH PROJECT, 2020
** test_fight_rpg
** File description:
** turn
*/

#include "fight/attack/turn.h"

int give_best_attack(attack_list_t *attack)
{
    int i = give_rand(1, get_size_att(attack));

    return (i);
}

void enemy_turn_attack(player_t *player, enemy_t *enemy, int todo)
{
    int nb = give_best_attack(enemy->attacks);
    attack_t *tmp = get_element_att(enemy->attacks, nb);

    enemy->lastattack = tmp->name;
    nb = tmp->dam_com;
    (todo == 1) ? player_defense_attack(nb, player) \
    : player_defense_total(player, nb);
}

void player_attack_turn(enemy_t *enemy, attack_t *attack)
{
    int nb = 0;

    nb = attack->dam_com;
    enem_defense_attack(nb, enemy);
}

int pos_attack(sprite_t *cursor)
{
    if (cursor->pos.x == 100 && cursor->pos.y == 800)
        return (1);
    if (cursor->pos.x == 1500 && cursor->pos.y == 800)
        return (2);
    if (cursor->pos.x == 100 && cursor->pos.y == 900)
        return (3);
    if (cursor->pos.x == 1500 && cursor->pos.y == 900)
        return (4);
    return (1);
}

void analyse_attack(main_t *main_struct, fight_scene_t *scene)
{
    int i = 0;
    attack_t *tmp = NULL;

    if (scene->var.menu == 1) {
        i = pos_attack(scene->cursor);
        tmp = get_element_att(main_struct->player->attacks, i);
        if (check_github(tmp, scene->enemies->enemy->name, main_struct) == -1)
            return;
        player_attack_turn(scene->enemies->enemy, tmp);
        enemy_turn_attack(main_struct->player, scene->enemies->enemy, 0);
        main_struct->player->last_attack = tmp->name;
        scene->var.menu = give_rand(7, 8);
    }
}