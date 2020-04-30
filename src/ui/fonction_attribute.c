/*
** EPITECH PROJECT, 2019
** attribute define for free
** File description:
** test
*/

#include "fonction_attribute.h"

void destroy_intab(int ***int_array)
{
    if (*int_array) {
        for (int index = 0; (*int_array)[index] != NULL; index++)
            free((*int_array)[index]);
        free(*int_array);
    }
}

void destroy_array(char ***array)
{
    if (*array) {
        for (size_t index = 0; (*array)[index]; index++)
            free((*array)[index]);
        free(*array);
    }
}

void destroy_str(char **str)
{
    if (*str)
        free(*str);
}