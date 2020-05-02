/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** script file
*/

#include "story/story.h"

void after_jordan(main_t *main)
{
    main->story->quests->quest_id = 5;
    main->story->quests->text = "Relire la norme pour s'ameliorer";
}

void pnj_jordan(main_t *main)
{
    story_t *story = main->story;

    if (story->quests->quest_id == 4) {
        create_window_pnj(story, "T'es claqué au sol, t'as\n\
obtenu grade D", after_jordan);
    } else
        create_window_pnj(story, "Tu veux quoi enfaite ?", nothing);
}