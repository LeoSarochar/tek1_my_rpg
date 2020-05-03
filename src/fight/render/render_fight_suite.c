/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** render_fight_suite
*/

#include "fight/init_attribute.h"

const char *rimka = "ressources/enemy/rimka/rimka2.png";

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
    (sc->var.scene == -1) ? destroy_fight_scene(main) : 0;
    (sc->var.scene == -1) ? exit_cmb(main) : 0;
}

preset_t *give_where(char *name, main_t *main)
{
    preset_list_t *tmp = main->player->preset;

    for (; tmp; tmp = tmp->next)
        if (my_strcmp(name, tmp->preset->name) == 0)
            return (tmp->preset);
    return (NULL);
}

void win_rimka(main_t *main)
{
    sprite_t *sprite = NULL;

    sfRenderWindow_clear(main->window, sfBlack);
    init_sprite(&sprite, (sfVector2f){900, 100}, rimka);
    draw_sprite(main, sprite);
    draw_text(main, "Bravo, tu as valide la piscine", \
    (sfVector2f){900, 0}, 75);
    sfRenderWindow_display(main->window);
    wait_second(2.0);
    main->player->com_max += main->player->fight_scene->enemies->enemy->com_max;
    main->player->com = main->player->com_max;
    main->player->fight_scene->ptr(main);
    main->player->gpa = (main->player->gpa < 4.0) ?
    main->player->gpa + 0.2 : main->player->gpa;
}