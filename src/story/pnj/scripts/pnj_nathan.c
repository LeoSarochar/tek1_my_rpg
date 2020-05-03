/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** script file
*/

#include "story/story.h"

void after_nathan(main_t *main)
{
    main->story->quests->quest_id = 7;
    main->story->quests->text = "Parler a Loic";
}

void pnj_nathan(main_t *main)
{
    story_t *story = main->story;

    if (story->quests->quest_id == 6) {
        create_window_pnj(story, "Un conseil,\nva voir Loic\npour corriger\
 tes noms de\nrepos", after_nathan);
    } else
        create_window_pnj(story, "Je suis entrain de faire un\n\
garbage collector,\nreviens plus tard", nothing);
}