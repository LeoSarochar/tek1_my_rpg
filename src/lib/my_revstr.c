/*
** EPITECH PROJECT, 2019
** CPool_Day06
** File description:
** my_strcmp.c
*/

#include "lib/my.h"

void my_revstr(char *str)
{
    int j = my_strlen(str) - 1;
    char tmp = 0;

    for (int i = 0; i < j; i += 1, j -= 1) {
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
    number = (size == 0) ? malloc(sizeof(char) * 2)
    : malloc(sizeof(char) * (size + 1));
    (size == 0) ? number[0] = '0' : 0;
    for (int i = 0; i < size; i += 1, nb /= 10)
        number[i] = (nb % 10) + 48;
    size = (size == 0) ? size + 1 : size;
    number[size] = '\0';
    my_revstr(number);
    return (number);
}