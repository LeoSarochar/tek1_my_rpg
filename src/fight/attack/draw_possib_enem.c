/*
** EPITECH PROJECT, 2020
** test_fight_rpg
** File description:
** draw_possib_enem
*/

#include "fight/init_attribute.h"

void is_dead(enemy_list_t *enemy, fight_scene_t *scene)
{
    enemy_list_t *tmp = enemy;
    int i = 0;
    int max = get_size_enem(tmp);

    for (; tmp; tmp = tmp->next)
        if (tmp->enemy->com <= 0)
            i += 1;
    if (max == i)
        scene->var.scene = 16;
}

void draw_pos_menu(enemy_list_t *list, main_t *main_struct)
{
    enemy_list_t *tmp = list;

    for (int y = 800; tmp && y <= 900; y += 100)
        for (int x = 100; x <= 1500 && tmp; x += 1400, tmp = tmp->next)
            draw_text(main_struct, tmp->enemy->name, (sfVector2f){x, y}, 75);
}