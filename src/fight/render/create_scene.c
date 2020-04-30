/*
** EPITECH PROJECT, 2020
** test_fight_rpg
** File description:
** create_scene
*/

#include "fight/render/create_scene.h"

void create_enemy_attack(attack_list_t **list, preset_list_t *pre, int xp)
{
    preset_list_t *other = otther_pos(pre, xp);
    preset_list_t *tmp = other;
    preset_t *t = NULL;
    int max = get_size_pres(tmp);
    int nb = 0;

    for (; tmp; tmp = tmp->next) {
        nb = (rand() % max) + 1;
        t = get_element_pre(other, nb);
        add_element_att(list, create_attack(t));
    }
}

preset_list_t *possible(preset_list_t *preset, int xp)
{
    preset_list_t *ret = NULL;
    preset_list_t *tmp = preset;
    int ok = 0;

    for (; tmp && ok == 0; tmp = tmp->next)
        if (tmp->preset->xp <= xp && tmp->preset->fo_alr == 0) {
            add_element_pres(&ret, tmp->preset);
            ok = 1;
        }
    return (ret);
}

void second_wave(preset_list_t **list, int xp, preset_list_t *preset)
{
    preset_list_t *tmp = preset;

    for (; tmp; tmp = tmp->next)
        if (tmp->preset->xp <= xp)
            add_element_pres(list, tmp->preset);
}

void create_all_enemy(enemy_list_t **enemy, preset_list_t *pre, int xp)
{
    preset_list_t *all = possible(pre, xp);
    preset_list_t *tmp = NULL;
    enemy_t *enem = NULL;

    (!all) ? second_wave(&all, xp, pre) : 0;
    tmp = all;
    for (; tmp; tmp = tmp->next) {
        enem = create_enemy(tmp->preset);
        add_element_att(&enem->attacks, create_attack(tmp->preset));
        create_enemy_attack(&enem->attacks, pre, tmp->preset->xp);
        init_state(&enem->state);
        add_element_enem(enemy, enem);
    }
}

void init_scene(main_t *main_struct, int visible, char *name)
{
    fight_scene_t *scene = malloc(sizeof(*scene));

    if (visible != 1)
        return;
    if (name == NULL)
        init_randomn(main_struct);
    else
        init_scene_name(main_struct, name);
}