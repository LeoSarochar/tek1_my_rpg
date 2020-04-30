/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** story
*/

#include "story/story.h"

void nothing(story_t *story)
{
    (void)story;
    return;
}

void init_story_struct(story_t *story)
{
    sfView *view = sfView_create();

    sfView_setSize(view, (sfVector2f){1920, 1080});
    sfView_setCenter(view, (sfVector2f){960, 530});
    story->fixed = view;
    story->pnjs = NULL;
    story->current_pnj = NULL;
    story->nb_pnjs = 0;
    story->objects = NULL;
    story->current_object = NULL;
    story->nb_objects = 0;
}

void create_pnjs(story_t *story)
{
    pnj_t *pnj = NULL;

    pnj = create_pnj(story, "Lucas", "ressources/pnjs/sanchez.png", pnj_sanchez);
    pnj->pos = (sfVector2f){50, 200};
}

void create_objects(story_t *story)
{
    object_t *obj = NULL;

    story->objects_clock = sfClock_create();
}

void init_story(main_t *main)
{
    story_t *story = malloc(sizeof(story_t));

    init_story_struct(story);
    main->story = story;
    main->story->show_window = 0;
    create_pnjs(story);
    create_objects(story);
    init_quests(main);
}