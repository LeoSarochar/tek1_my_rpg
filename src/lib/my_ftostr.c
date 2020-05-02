/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** my_ftostr
*/

#include "include_all.h"
#include "lib/my.h"

int size_nb(int nb)
{
    int ret = 0;

    if (nb == 0)
        return (1);
    for (; nb > 0; nb /= 10, ret += 1);
    return (ret);
}

void give_after(char *str, int nb, int prec)
{
    for (int i = 0; i < prec; i += 1) {
        str[i] += (nb % 10) + '0';
        nb /= 10;
    }
}

char *sign(char *str, float nb)
{
    if (nb < 0)
        return (my_strcat("-", str));
    else
        return (str);
}

char *my_ftostr(float nb, int prec)
{
    int tmp = round(fabs(nb) * pow(10, prec));
    int vir = size_nb(round(fabs(nb)));
    char *str = malloc(sizeof(*str) * (vir + 1));
    char *after = malloc(sizeof(*str) * (prec + 1));
    int be_vir = (int)fabs(nb);

    my_memset(str, 0, vir + 1);
    my_memset(after, 0, prec + 1);
    for (int i = 0; i < vir; be_vir /= 10, i += 1)
        str[i] = (be_vir % 10) + '0';
    my_revstr(str);
    if (prec == 0)
        return (sign(str, nb));
    give_after(after, tmp, prec);
    my_revstr(after);
    str = my_strcat(str, ".");
    str = my_strcat(str, after);
    return (sign(str, nb));
}