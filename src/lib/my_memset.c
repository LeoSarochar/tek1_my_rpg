/*
** EPITECH PROJECT, 2019
** my_memset
** File description:
** Memset
*/

#include "lib/my.h"

void    *my_memset(void *s, int c, size_t n)
{
    for (size_t i = 0; i != n; i++)
        ((__uint8_t *)s)[i] = c;
    return (s);
}