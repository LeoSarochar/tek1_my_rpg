/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** story
*/

#include "story/story.h"

void init_story(main_t *main)
{
    story_t *story = malloc(sizeof(story_t));

    story->pnjs = NULL;
    story->nb_pnjs = 0;
    main->story = story;

    create_pnj(main->story, "Louis", "ressources/test.png", NULL);
}