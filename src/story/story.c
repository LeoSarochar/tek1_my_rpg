/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** story
*/

#include "story/story.h"

void nothing(main_t *main)
{
    (void)main;
    return;
}

void init_story_struct(story_t *story)
{
    sfView *view = sfView_create();

    sfView_setSize(view, (sfVector2f){1920, 1080});
    sfView_setCenter(view, (sfVector2f){960, 540});
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
    char *path = NULL;

    path = "ressources/pnjs/sanchez.png";
    pnj = create_pnj(story, (char *[2]){"Lucas", path}, 0, pnj_sanchez);
    pnj->pos = (sfVector2f){727, 241};
    path = "ressources/pnjs/jordan.png";
    pnj = create_pnj(story, (char *[2]){"Jordan", path}, 1, pnj_jordan);
    pnj->pos = (sfVector2f){120, 405};
    path = "ressources/pnjs/mathilde.png";
    pnj = create_pnj(story, (char *[2]){"Mathilde", path}, 0, pnj_mathilde);
    pnj->pos = (sfVector2f){1110, 298};
    path = "ressources/pnjs/nathan.png";
    pnj = create_pnj(story, (char *[2]){"Nathan", path}, 2, pnj_nathan);
    pnj->pos = (sfVector2f){790, 630};
    path = "ressources/pnjs/loic.png";
    pnj = create_pnj(story, (char *[2]){"Loic", path}, 0, pnj_loic);
    pnj->pos = (sfVector2f){1500, 232};
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