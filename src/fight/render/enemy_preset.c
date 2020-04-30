/*
** EPITECH PROJECT, 2020
** test_fight_rpg
** File description:
** enemy_preset
*/

#include "lib/my.h"
#include "fight/render/enemy_preset.h"

const enemy_preset_t preset_enemy[] = {
    {"my_putchar", 50, 5, 5, 10, 5, 0},
    {"my_strlen", 60, 10, 5, 10, 5, 0},
    {"my_putstr", 70, 10, 10, 15, 5, 0},
};

enemy_preset_t give_pre(char *name)
{
    for (int i = 0; i < 3; i += 1)
        if (my_strcmp(name, preset_enemy[i].name) == 0)
            return (preset_enemy[i]);
    return ((enemy_preset_t){NULL});
}

preset_list_t *otther_pos(preset_list_t *preset, int xp)
{
    preset_list_t *ret = NULL;

    for (; preset; preset = preset->next)
        if (preset->preset->xp < xp)
            add_element_pres(&ret, preset->preset);
    return (ret);
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

enemy_t *create_enemy(preset_t *pre)
{
    enemy_t *enemy = malloc(sizeof(*enemy));
    enemy_preset_t tmp = give_pre(pre->name);

    enemy->attacks = NULL;
    enemy->com = give_rand(percent(tmp.life_max, 90), tmp.life_max);
    enemy->com_max = enemy->com;
    enemy->defence = give_rand(percent(tmp.defence_max, 90), tmp.defence_max);
    enemy->force = give_rand(percent(tmp.force_max, 90), tmp.force_max);
    enemy->intel = (tmp.intel_max > 0) ? \
    give_rand(percent(tmp.intel_max, 90), tmp.intel_max) : 0;
    enemy->ram = (tmp.ram_max) ? \
    give_rand(percent(tmp.ram_max, 90), tmp.ram_max) : 0;
    enemy->speed = give_rand(percent(tmp.speed_max, 90), tmp.speed_max);
    enemy->name = pre->name;
    return (enemy);
}