/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_fighter
*/

#include "main.h"

void check_pos_f(character_t *pl, list_attpre_t **ret)
{
    list_attpre_t *tmp = pl->preset.attack;
    int ok = 0;

    for (; tmp && ok != 1; tmp = tmp->next)
        if (pl->xp >= tmp->attack.min_xp) {
            add_element_preset(ret, tmp->attack);
            ok = 1;
        }
}

list_attpre_t *check_pos_notf(character_t *pl)
{
    list_attpre_t *tmp = pl->preset.attack;
    list_attpre_t *ret = NULL;
    int ok = 0;

    for (; tmp && ok != 1; tmp = tmp->next)
        if (tmp->attack.fought_already == 0 && pl->xp >= tmp->attack.min_xp) {
            add_element_preset(&ret, tmp->attack);
            ok = 1;
        }
    (!ret) ? check_pos_f(pl, &ret) : 0;
    return (ret);
}

attack_t create_preattack(attpre_t pre)
{
    attack_t attack;

    attack.dama_com = pre.max_deg;
    attack.life = pre.min_xp * 20;
    attack.defen = pre.min_xp * 2;
    attack.name = pre.name;
    attack.req_intel = 0;
    attack.req_logi = 0;
    attack.speed = pre.min_xp * 10;
    attack.sprite = load_sprite("ressources/stance.png");
    init_state(&attack.state);
    return (attack);
}

att_list_t *create_enemy(list_attpre_t *ret)
{
    att_list_t *list = NULL;
    for (; ret; ret = ret->next)
        add_element_attack(&list, create_preattack(ret->attack));
    return (list);
}

fight_t *create_scene(main_t *main)
{
    fight_t *scene = malloc(sizeof(*scene));
    list_attpre_t *ret = check_pos_notf(main->player);

    scene->enemy = create_enemy(ret);
    scene->players = NULL;
    add_element_char(&scene->players, main->player);
}