/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player_list
*/

#include "fight/linked_list_library/player_list.h"

void add_element_pl(player_list_t **list, player_t *pl)
{
    player_list_t *elem = malloc(sizeof(*elem));
    player_list_t *tmp = (*list);

    elem->player = pl;
    elem->next = NULL;
    if (!(*list)) {
        *list = elem;
        return;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = elem;
}

void remove_element_pl(player_list_t **list, int position)
{
    player_list_t *tmp1 = NULL;
    player_list_t *tmp2 = (*list);
    player_list_t *tmp_to_free = NULL;

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

void insert_element_pl(player_list_t **list, int position, player_t *pl)
{
    player_list_t *elem = malloc(sizeof(*elem));
    player_list_t *tmp1 = (*list);
    player_list_t *tmp2 = (*list);

    elem->player = pl;
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

int get_size_pl(player_list_t *list)
{
    int i = 0;

    for (; list; list = list->next, i += 1);
    return (i);
}