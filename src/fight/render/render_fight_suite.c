/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** render_fight_suite
*/

#include "fight/init_attribute.h"

void render_fight2(main_t *main, fight_scene_t *sc)
{
    (sc->var.scene == 3) ? render_biensur(main) : 0;
    (sc->var.menu == 7) ? square_anim(main, \
    sc->enemies->enemy, main->player->last_attack) : 0;
    (sc->var.menu == 8) ? second_anim(main, sc->enemies->enemy->rect, \
    main->player->last_attack) : 0;
    is_dead(sc->enemies, sc);
    sc->var.scene = (main->player->com <= 0) ? 15 : sc->var.scene;
    ending_cond(main);
    (sc->var.scene == -1) ? main->player->fight_scene->ptr(main) : 0;
    (sc->var.scene == -1) ? destroy_fight_scene(main) : 0;
}

preset_t *give_where(char *name, main_t *main)
{
    preset_list_t *tmp = main->player->preset;

    for (; tmp; tmp = tmp->next)
        if (my_strcmp(name, tmp->preset->name) == 0)
            return (tmp->preset);
    return (NULL);
}