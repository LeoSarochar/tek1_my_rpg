/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** story
*/

#include "story/story.h"

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

void create_pnjs2(story_t *story)
{
    pnj_t *pnj = NULL;
    char *path = NULL;

    path = "ressources/pnjs/bryan.png";
    pnj = create_pnj(story, (char *[2]){"Bryan", path}, 2, pnj_bryan);
    pnj->pos = (sfVector2f){1700, 306};
    path = "ressources/pnjs/lorenzo.png";
    pnj = create_pnj(story, (char *[2]){"Lorenzo", path}, 0, pnj_lorenzo);
    pnj->pos = (sfVector2f){759, 985};
    path = "ressources/pnjs/lajackette.png";
    pnj = create_pnj(story, (char *[2]){"La Jackette", path}, 0, pnj_jackette);
    pnj->pos = (sfVector2f){760, 590};
    path = "ressources/pnjs/richard.png";
    pnj = create_pnj(story, (char *[2]){"Uichard", path}, 0, pnj_richard);
    pnj->pos = (sfVector2f){1110, 603};
    path = "ressources/pnjs/sophie.png";
    pnj = create_pnj(story, (char *[2]){"Toffle", path}, 0, pnj_sophie);
    pnj->pos = (sfVector2f){890, 570};
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
    pnj->pos = (sfVector2f){795, 627};
    path = "ressources/pnjs/loic.png";
    pnj = create_pnj(story, (char *[2]){"Loic", path}, 0, pnj_loic);
    pnj->pos = (sfVector2f){1500, 232};
    create_pnjs2(story);
}

void create_objects(story_t *story)
{
    object_t *obj = NULL;
    char *path = NULL;

    story->objects_clock = sfClock_create();

    path = "ressources/objects/air.png";
    obj = create_object(story, (char *[2]){"Airpods", path}, 0, after_airpods);
    obj->pos = (sfVector2f){550, 768};
    path = "ressources/objects/pull.png";
    obj = create_object(story, (char *[2]){"Pull Epi", path}, 2, after_pull);
    obj->pos = (sfVector2f){670, 957};
    path = "ressources/objects/ttb.png";
    obj = create_object(story, (char *[2]){"ThaiToBox", path}, 2, after_ttb);
    obj->pos = (sfVector2f){520, 440};
    path = "ressources/objects/esc.png";
    obj = create_object(story, (char *[2]){"Arnet", path}, 2, after_arnet);
    obj->pos = (sfVector2f){1600, 520};
    path = "ressources/objects/trot.png";
    obj = create_object(story, (char *[2]){"Trotinette", path},\
    1, after_trotinette);
    obj->pos = (sfVector2f){402, 765};
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