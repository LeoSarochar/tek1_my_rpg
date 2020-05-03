/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** enemy_list
*/

#include "fight/linked_list_library/enemy_list.h"

void add_element_enem(enemy_list_t **list, enemy_t *enem)
{
    enemy_list_t *elem = malloc(sizeof(*elem));
    enemy_list_t *tmp = (*list);

    elem->enemy = enem;
    elem->next = NULL;
    if (!(*list)) {
        *list = elem;
        return;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = elem;
}

void remove_element_enem(enemy_list_t **list, int position)
{
    enemy_list_t *tmp1 = NULL;
    enemy_list_t *tmp2 = (*list);
    enemy_list_t *tmp_to_free = NULL;

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

void insert_element_enem(enemy_list_t **list, int position, enemy_t *enem)
{
    enemy_list_t *elem = malloc(sizeof(*elem));
    enemy_list_t *tmp1 = (*list);
    enemy_list_t *tmp2 = (*list);

    elem->enemy = enem;
    if (position == 1) {
        elem->next = (*list);
        (*list) = elem;
        return;
    }
    for (int i = 0; i < position - 2; i += 1)
        tmp1 = tmp1->next;
    for (int i = 0; i < position - 1; i += 1) {
        tmp2 = tmp2->next;
    }
    tmp1->next = elem;
    elem->next = tmp2;
}

int get_size_enem(enemy_list_t *list)
{
    int i = 0;

    for (; list; list = list->next, i += 1);
    return (i);
}