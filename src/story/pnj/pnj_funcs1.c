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
    story->quests->text = "Retourner voir Sanchez pour\napprendre a coder my_putchar";
    story->quests->quest_id = 3;
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

void after_my_putstr(main_t *main)
{
    main->story->quests->quest_id = 3;
    main->story->quests->text = "Demander de l'aide à Rafik\npour le my_strlen";
}

void after_sanchez_putstr(main_t *main)
{
    init_scene(main, 1, NULL); // my_putstr check return
    after_my_putstr(main);
}

void pnj_sanchez(main_t *main)
{
    story_t *story = main->story;

    switch (story->quests->quest_id) {
        case 1:
            create_window_pnj(story, "Bienvenue a la Piscine !\nVa falloir\
            t'accrocher\nOn compte sur toi !", after_sanchez);
            break;
        case 3:
            create_window_pnj(story, "Bravo ! Maintenant recode my_putstr", after_sanchez_putstr);
            break;
        default:
            create_window_pnj(story, "Trouve le document de\nla norme ou lis le man !", nothing);
            break;
    }
}

void after_my_strlen(main_t *main)
{
    main->story->quests->quest_id = 4;
    main->story->quests->text = "Demande son grade à Jordan";
}

void after_rafik(main_t *main)
{
    init_scene(main, 1, NULL); // my_strlen check return
    after_my_strlen(main);
}

void pnj_rafik(main_t *main)
{
    story_t *story = main->story;

    if (story->quests->quest_id == 3) {
        create_window_pnj(story, "Je te conseille de Github,\n\
        c'est un bon moyen de réussir", after_rafik);
    } else
        create_window_pnj(story, "Laisse moi bosser !", nothing);
}