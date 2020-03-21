/*
** EPITECH PROJECT, 2019
** my_memcpy
** File description:
** Memcpy
*/

#include "lib/my.h"

void    *my_memcpy(void *ptr1, void *ptr2, size_t size)
{
    for (size_t i = 0; i != size; i++) {
        ((__uint8_t *)ptr1)[i] = ((__uint8_t *)ptr2)[i];
    }
    return (ptr1);
}