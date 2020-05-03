/*
** EPITECH PROJECT, 2020
** test_fight_rpg
** File description:
** enemy_preset
*/

#include "lib/my.h"
#include "fight/render/enemy_preset.h"

const enemy_preset_t preset_enemy[] = {
    {"My_strlen", "my_strlen", "int", 60, 10, 5, 10, 5, 0},
    {"My_putstr", "my_putstr", "void", 70, 10, 10, 15, 5, 0},
    {"La vie d'artiste", "Loic", "none", 250, 80, 80, 80, 80, 80},
    {"Nuit blanche", "Loic", "none", 250, 80, 80, 80, 80, 80},
    {"Mauvais nom de repo", "Loic", "none", 250, 80, 80, 80, 80, 80},
    {"Trotinette en sm1", "Loic", "none", 250, 80, 80, 80, 80, 80},
    {"Criterion", "Karim", "none", 1000, 95, 95, 95, 95, 95},
    {"Makefile", "Karim", "none", 1000, 95, 95, 95, 95, 95},
    {"8h45", "Karim", "none", 1000, 95, 95, 95, 95, 95},
    {"Je n'arrive pas a clone ton repo", "Karim", "none", \
    1000, 95, 95, 95, 95, 95}
};

enemy_preset_t give_pre(char *name)
{
    for (int i = 0; i < 10; i += 1)
        if (my_strcmp(name, preset_enemy[i].enemy) == 0)
            return (preset_enemy[i]);
    return ((enemy_preset_t){NULL});
}

void other_pos(attack_list_t **attack, preset_list_t *pre, char *name)
{
    for (int i = 0; i < 10; i += 1)
        if (my_strcmp(name, preset_enemy[i].enemy) == 0)
            adder(attack, pre, preset_enemy[i].name);
}

int percent(int nb, int per)
{
    return ((nb * per) / 100);
}

int give_rand(int min, int max)
{
    int ret = (rand() % (max - min + 1)) + min;
    return (ret);
}

enemy_t *create_enemy(preset_list_t *pre, char *name)
{
    enemy_t *enemy = malloc(sizeof(*enemy));
    enemy_preset_t tmp = give_pre(name);

    enemy->attacks = NULL;
    other_pos(&enemy->attacks, pre, name);
    enemy->com = tmp.life_max;
    enemy->com_max = enemy->com;
    enemy->defence = tmp.defence_max;
    enemy->force = tmp.force_max;
    enemy->intel = tmp.intel_max;
    enemy->ram = tmp.ram_max;
    enemy->speed = tmp.speed_max;
    enemy->name = name;
    return (enemy);
}