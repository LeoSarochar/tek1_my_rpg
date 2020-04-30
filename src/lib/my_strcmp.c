/*
** EPITECH PROJECT, 2019
** CPool_Day06
** File description:
** my_strcmp.c
*/

#include "lib/my.h"

int my_strlen(char *str)
{
    int i = 0;

    for (; str[i]; i += 1);
    return (i);
}

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

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    for (; s1[i] && s2[i] && s1[i] == s2[i]; i += 1);
    return (s1[i] - s2[i]);
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

char *my_strcat (char *dest , char *src)
{
    int size = my_strlen(dest) + my_strlen(src) + 1;
    char *str = malloc(sizeof(char) * size);
    int i = 0;
    int j = 0;

    for (; dest[i]; i += 1)
        str[i] = dest[i];
    for (; src[j]; j += 1)
        str[i + j] = src[j];
    str[i + j] = '\0';
    return (str);
}