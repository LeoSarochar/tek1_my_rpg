/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** create.c
*/

#include "story/story.h"

object_t *get_object_by_name(story_t *story, char *name)
{
    for (int i = 0; i < story->nb_objects; i++)
        if (!my_strcmp(story->objects[i].name, name))
            return (&(story->objects[i]));
    return (NULL);
}

object_t *create_object(story_t *story, char *name, char *path, STRY_PTR)
{
    int prec_size = sizeof(object_t) * (story->nb_objects);
    int new_size =  sizeof(object_t) * (story->nb_objects + 1);

    story->nb_objects++;
    story->objects = my_realloc(story->objects, prec_size, new_size);
    CUR_OBJ.name = name;
    CUR_OBJ.sprite = load_sprite(path);
    CUR_OBJ.onclick = ptr;
    CUR_OBJ.path = path;
    printf("[DEBUG] Creating object : %s\n", CUR_OBJ.name);
    return (&(CUR_OBJ));
}