/*
** EPITECH PROJECT, 2020
** test_fight_rpg
** File description:
** create_scene
*/

#include "fight/render/create_scene.h"

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