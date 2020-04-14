/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** preset_list
*/

#include "main.h"

void add_element_preset(list_attpre_t **list, attpre_t attack)
{
    list_attpre_t *elem = malloc(sizeof(*elem));
    list_attpre_t *tmp = (*list);

    elem->attack = attack;
    elem->next = NULL;
    if (!(*list)) {
        *list = elem;
        return;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = elem;
}

void remove_element_preset(list_attpre_t **list, int position)
{
    list_attpre_t *tmp1 = NULL;
    list_attpre_t *tmp2 = (*list);
    list_attpre_t *tmp_to_free = NULL;

    if (position == 1) {
        tmp1 = (*list);
        (*list) = (*list)->next;
        free(tmp1);
        return;
    }
    for (int i = 0; i < position - 2; i += 1)
        tmp2 = tmp2->next;
    tmp1 = tmp2->next->next;
    tmp_to_free = tmp2->next;
    tmp2->next = tmp1;
    free(tmp_to_free);
}

void insert_element_preset(list_attpre_t **list, int pos, attpre_t attack)
{
    list_attpre_t *elem = malloc(sizeof(*elem));
    list_attpre_t *tmp1 = (*list);
    list_attpre_t *tmp2 = (*list);

    elem->attack = attack;
    if (pos == 1) {
        elem->next = (*list);
        (*list) = elem;
        return;
    }
    for (int i = 0; i < pos - 2; i += 1)
        tmp1 = tmp1->next;
    for (int i = 0; i < pos - 1; i += 1) {
        tmp2 = tmp2->next;
        if (i < pos - 2 && tmp2 == NULL)
            exit(84);
    }
    tmp1->next = elem;
    elem->next = tmp2;
}