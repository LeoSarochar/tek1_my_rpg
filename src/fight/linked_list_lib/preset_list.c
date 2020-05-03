/*
** EPITECH PROJECT, 2020
** test_fight_rpg
** File description:
** preset_list
*/

#include "lib/my.h"
#include "fight/linked_list_library/preset_list.h"

void add_element_pres(preset_list_t **list, preset_t *pres)
{
    preset_list_t *elem = malloc(sizeof(*elem));
    preset_list_t *tmp = (*list);

    elem->preset = pres;
    elem->next = NULL;
    if (!(*list)) {
        *list = elem;
        return;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = elem;
}

void remove_element_pres(preset_list_t **list, int position)
{
    preset_list_t *tmp1 = NULL;
    preset_list_t *tmp2 = (*list);
    preset_list_t *tmp_to_free = NULL;

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

void insert_element_pres(preset_list_t **list, int position, preset_t *pres)
{
    preset_list_t *elem = malloc(sizeof(*elem));
    preset_list_t *tmp1 = (*list);
    preset_list_t *tmp2 = (*list);

    elem->preset = pres;
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

int get_size_pres(preset_list_t *list)
{
    int i = 0;

    for (; list; list = list->next, i += 1);
    return (i);
}

int check_exist(preset_list_t *list, char *name)
{
    for (; list; list = list->next)
        if (my_strcmp(list->preset->name, name) == 0)
            return (1);
    return (0);
}