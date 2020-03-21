/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** story
*/

#include "story/story.h"

void init_story(main_t *main_struct)
{
    story_t story;

    story.pnjs = NULL;
    story.nb_pnjs = 0;
    main_struct->story = &story;

    create_pnj(main_struct->story, "Louis", "ressources/test.png", NULL);
}