/*
** EPITECH PROJECT, 2019
** my_memcmp
** File description:
** Memcmp
*/

#include "lib/my.h"

size_t my_memcmp(void *ptr1, void *ptr2, size_t len)
{
    for (size_t i = 0; len > 0; i++) {
        if (((__uint8_t *)ptr1)[i] != ((__uint8_t *)ptr2)[i])
            return (((__uint8_t *)ptr1)[i] - ((__uint8_t *)ptr2)[i]);
    }
    return (0);
}