/*
** EPITECH PROJECT, 2020
** test_fight_rpg
** File description:
** draw_possib_enem
*/

#include "fight/init_attribute.h"

void draw_pos_menu(enemy_list_t *list, main_t *main_struct)
{
    int nb = 0;
    enemy_list_t *tmp = list;

    for (int y = 800; tmp && y <= 900; y += 100) {
        for (int x = 100; x <= 1500 && tmp; x += 1400, tmp = tmp->next)
            draw_text(main_struct, tmp->enemy->name, (sfVector2f){x, y}, 75);
    }
}