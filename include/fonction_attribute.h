/*
** EPITECH PROJECT, 2019
** bsq .h
** File description:
** bsq.h
*/

#ifndef H_ATTRIBUTE_
#define H_ATTRIBUTE_

#include "include_all.h"

#define UNUSED __attribute__((unused))
#define CONST __attribute__((const))
#define VOID __attribute__((noreturn))
#define STR char *__attribute__((__cleanup__(destroy_str)))
#define ARRAY char **__attribute__((__cleanup__(destroy_array)))
#define INTAB int **__attribute__((__cleanup__(destroy_intab)))

void destroy_intab(int ***array);
void destroy_array(char ***array);
void destroy_str(char **str);

#endif // !H_ATTRIBUTE_
