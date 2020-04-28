/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** create.c
*/

#include "story/story.h"

pnj_t *create_pnj(story_t *story, char *name, char *path, void (*ptr)(story_t *))
{
    int prec_size = sizeof(pnj_t) * (story->nb_pnjs);
    int new_size =  sizeof(pnj_t) * (story->nb_pnjs + 1);

    story->nb_pnjs++;
    story->pnjs = my_realloc(story->pnjs, prec_size, new_size);
    CUR_PNJ.name = name;
    CUR_PNJ.sprite = load_sprite(path);
    CUR_PNJ.onclick = ptr;
    CUR_PNJ.path = path;
    printf("[DEBUG] Creating pnj : %s\n", CUR_PNJ.name);
    return (&(CUR_PNJ));
}