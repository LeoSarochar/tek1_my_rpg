/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** script file
*/

#include "story/story.h"

void after_loic_fight(main_t *main)
{
    main->story->quests->quest_id = 8;
    main->story->quests->text = "Retourne voir Jordan pour ton grade";
}

void after_loic(main_t *main)
{
    init_scene_name(main, "Loic", after_loic_fight);
}

void pnj_loic(main_t *main)
{
    story_t *story = main->story;

    if (story->quests->quest_id == 7) {
        create_window_pnj(story, "Les noms de repos,\nc'est la\
 vie d'artiste !", after_loic);
    } else
        create_window_pnj(story, "T'es en roue libre ou quoi ?", nothing);
}