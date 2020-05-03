/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** checkk_github
*/

#include "fight/init_attribute.h"

int check_github(attack_t *attack, char *name, main_t *main)
{
    if (my_strcmp(attack->name, "github") == 0) {
        if (my_strcmp(name, "my_putstr") == 0) {
            main->player->fight_scene->var.scene = 3;
            return (-1);
        }
    }
    return (0);
}

void write_enemy(char *attack, char *name, main_t *main)
{
    draw_text(main, my_strcat(name, " a lance: "), (sfVector2f){100, 800}, 75);
    draw_text(main, attack, (sfVector2f){1000, 800}, 75);
    main->player->fight_scene->var.menu = 0;
    sfRenderWindow_display(main->window);
    wait_second(2.0);
}