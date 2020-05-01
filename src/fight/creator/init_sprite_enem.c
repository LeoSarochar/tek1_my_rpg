/*
** EPITECH PROJECT, 2020
** test_fight_rpg
** File description:
** init_sprite_enem
*/

#include "fight/creator/init_sprite_enem.h"
#include "lib/my.h"

const enemy_path_t path[] = {
    {"ressources/enemy/my_putchar/putchar.png", \
    "ressources/enemy/my_putchar/charincomp.png", "my_putchar"},
    {"ressources/enemy/my_putstr/putstr.png", \
    "ressources/enemy/my_putstr/putstrincomp.png", "my_putstr"},
    {NULL}
};

void init_sprite_enem(enemy_list_t *enemies)
{
    enemy_list_t *tmp = enemies;
    int x = 100;
    int y = 200;

    for (; tmp; tmp = tmp->next, x += 200) {
        for (int i = 0; i < 2; i += 1) {
            (my_strcmp(path[i].enemy, tmp->enemy->name) == 0) ? \
            init_sprite(&tmp->enemy->sprite, \
            (sfVector2f){x, y}, path[i].path) : 0;
        }
    }
}

void change_sprite_enem(enemy_t *enem,  int nb)
{
    char *almod = "ressources/enemy/void.png";
    for (int i = 0; i < 2; i += 1)
        if (my_strcmp(path[i].enemy, enem->name) == 0)
            (nb == 0) ? change_sprite(path[i].incomp, &enem->sprite) \
            : change_sprite(almod, &enem->sprite);
}

void echanger(enemy_t *enem)
{
    int nb_incomp = percent(enem->com_max, 75);
    int nb_void = percent(enem->com_max, 33);

    if (enem->com <= nb_incomp && enem->com >= nb_void)
        change_sprite_enem(enem, 0);
    else if (enem->com < nb_void)
        change_sprite_enem(enem, 1);
}