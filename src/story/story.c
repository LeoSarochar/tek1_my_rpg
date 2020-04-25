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
    if (event.key.code == sfKeyE) {
        printf("Salut\n");
        //main->story->shape = sfRectangleShape_create();
        //sfRectangleShape_setFillColor(main->story->shape, (sfColor){255, 134, 51, 255});
        //sfRectangleShape_setSize(main->story->shape, (sfVector2f){255, 134});
        //main->story->show_window = 1;
        if (main->story->current_pnj != NULL)
            main->story->current_pnj->onclick(main->story);
    }
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
    main->story->shape = NULL;
    main->story->show_window = 0;

    create_pnj(main->story, "Louis", "ressources/pnjs/boulet.jpeg", test);
}