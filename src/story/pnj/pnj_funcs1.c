/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** misc
*/

#include "story/story.h"

void after_norme_book(main_t *main)
{
    story_t *story = main->story;

    story->current_object->sprite->visible = 0;
    story->quests->text = "Recoder la fonction strlen";
    story->quests->quest_id = 3;
    init_scene(main, 1, NULL);
}

void after_sanchez(main_t *main)
{
    story_t *story = main->story;
    object_t *obj = NULL;
    char *fp = "ressources/objects/book.png";

    obj = create_object(story, (char *[2]){"Norme", fp}, 1, after_norme_book);
    obj->pos = (sfVector2f){100, 500};
    obj->sprite->rect->top = 4;
    obj->sprite->rect->width = 26;
    obj->sprite->rect->height = 30;
    story->quests->text = "Trouver le document de la norme";
    story->quests->quest_id = 2;
    return;
}

void pnj_sanchez(main_t *main)
{
    story_t *story = main->story;

    if (story->quests->quest_id == 1) {
        create_window_pnj(story, "Bienvenue a la Piscine !\nVa falloir\
        t'accrocher\nOn compte sur toi !", after_sanchez);
    } else {
        create_window_pnj(story, "Lis le man !", nothing);
    }
}