/*
** EPITECH PROJECT, 2020
** test_fight_rpg
** File description:
** my
*/

#ifndef MY_H
#define MY_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void    *my_memset(void *, int, size_t);
void *my_realloc(void *, size_t, size_t);
void *my_memcpy(void *, void *, size_t);
size_t my_memcmp(void *, void *, size_t);
int my_strcmp(char *s1, char *s2);
char *my_itoa(int nb);
char *my_strcat (char *dest , char *src);
char *my_ftostr(float nb, int prec);
void my_revstr(char *str);
#endif //MY_H