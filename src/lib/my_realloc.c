/*
** EPITECH PROJECT, 2019
** my_realloc
** File description:
** Realloc
*/

#include "lib/my.h"

void    *my_realloc(void *p, size_t prec_size, size_t size)
{
    void *p2 = malloc(size);

    my_memset(p2, 0, size);
    my_memcpy(p2, p, prec_size);
    return (p2);
}