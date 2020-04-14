/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** flistattack
*/

#include "main.h"

attack_t crte_att(int attrib[4], char *name, int is_enemy)
{
    attack_t attack;
    attack.name = name;
    attack.req_intel = attrib[0];
    attack.req_logi = attrib[1];
    attack.dama_com = attrib[2];
    attack.life = attrib[3];
    (is_enemy == 1) ? init_state(&attack.state) : 0;
    attack.sprite = (is_enemy == 1) ? NULL : NULL;
    return (attack);
}

attpre_t create_preset(char *name, int max_deg, int min_xp, int fo_alr)
{
    attpre_t preset;
    preset.fought_already = fo_alr;
    preset.max_deg = max_deg;
    preset.min_xp = min_xp;
    preset.name = name;
    return (preset);
}

int my_strlen(char *str)
{
    int i = 0;

    for (; str[i]; i += 1);
    return (i);
}

void my_revstr(char *str)
{
    char tmp = 0;
    int j = 0;

    for (int i = 0; i <= j; i += 1) {
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
    }
}

char *my_itoa(int nb)
{
    int size = 0;
    char *number = NULL;

    for (int i = nb; i > 0; i /= 10, size += 1);
    number = (size == 0) ? "0" : malloc(sizeof(char) * (size + 1));
    for (int i = 0; i < size; i += 1, nb / 10)
        number[i] = (nb % 10) + 48;
    number[size] = '\0';
    return (number);
}
