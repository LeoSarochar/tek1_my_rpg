/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** story
*/

#include "story/story.h"

void close_pnj_window(main_t *main, sfEvent event)
{
    if (event.key.code == sfKeyEscape)
        main->story->current_pnj = NULL;
}

void test(story_t *story)
{
    printf("Test\n");
}

void init_story(main_t *main)
{
    story_t *story = malloc(sizeof(story_t));

    story->pnjs = NULL;
    story->current_pnj = NULL;
    story->nb_pnjs = 0;
    main->story = story;

    create_pnj(main->story, "Louis", "ressources/pnjs/boulet.jpeg", &test);
}