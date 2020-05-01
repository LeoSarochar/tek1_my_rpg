/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** create.c
*/

#include "story/story.h"

pnj_t *create_pnj(story_t *story, char **conf, int id, STRY_PTR)
{
    char *name = conf[0];
    char *path = conf[1];
    int prec_size = sizeof(pnj_t) * (story->nb_pnjs);
    int new_size =  sizeof(pnj_t) * (story->nb_pnjs + 1);

    story->nb_pnjs++;
    story->pnjs = my_realloc(story->pnjs, prec_size, new_size);
    CUR_PNJ.name = name;
    CUR_PNJ.sprite = load_sprite(path);
    sfSprite_setScale(CUR_PNJ.sprite->sprite, (sfVector2f){0.3, 0.3});
    CUR_PNJ.map_scene = id;
    CUR_PNJ.onclick = ptr;
    CUR_PNJ.path = path;
    return (&(CUR_PNJ));
}