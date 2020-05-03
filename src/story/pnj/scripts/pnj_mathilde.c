/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** script file
*/

#include "story/story.h"

void after_my_strlen(main_t *main)
{
    main->story->quests->quest_id = 4;
    main->story->quests->text = "Demander son grade a Jordan";
}

void after_mathilde(main_t *main)
{
    init_scene_name(main, "my_strlen", after_my_strlen); // my_strlen check return
    after_my_strlen(main);
}

void pnj_mathilde(main_t *main)
{
    story_t *story = main->story;

    if (story->quests->quest_id == 3) {
        create_window_pnj(story, "Je te conseille de Github,\n\
c'est un bon moyen de reussir", after_mathilde);
    } else
        create_window_pnj(story, "Laisse moi bosser !", nothing);
}