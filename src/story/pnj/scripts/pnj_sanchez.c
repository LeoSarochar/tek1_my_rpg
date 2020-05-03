/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** script file
*/

#include "story/story.h"

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
    add_element_att(&main->player->attacks, \
    create_attack(give_where("My_putstr", main)));
    main->story->quests->quest_id = 3;
    main->story->quests->text = "Demander de l'aide a Mathilde\npour\
 le my_strlen";
}

void after_sanchez_putstr(main_t *main)
{
    init_scene_name(main, "my_putstr", after_my_putstr);
    // after_my_putstr(main);
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
            add_element_att(&main->player->attacks, \
            create_attack(main->player->preset->preset));
            add_element_att(&main->player->attacks, \
            create_attack(create_preset(90, "github")));
            create_window_pnj(story, "Bravo ! Maintenant recode\nmy_putstr",\
            after_sanchez_putstr);
            break;
        default:
            create_window_pnj(story, "Trouve le document de\nla\
 norme ou lis le man !", nothing);
            break;
    }
}