/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** Strcat
*/

#include "lib/my.h"

char *my_strcat2(char *str, char *str2, int max, int start)
{
    char *ret = NULL;
    int index = 0;
    int len = 0;
    int len2 = 0;

    while (str && str[len])
        len += 1;
    while (str2[len2])
        len2 += 1;
    ret = malloc(sizeof(char) * (len + len2 + 1));
    for (; str && str[index]; index++)
        ret[index] = str[index];
    if (start <= len2) {
        for (int i = start; str2[i] && (i < max || max == -1); i++, index++)
            ret[index] = str2[i];
    }
    ret[index] = '\0';
    return (ret);
}