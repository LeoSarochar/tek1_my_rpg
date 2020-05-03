/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** script file
*/

#include "story/story.h"

void the_end(main_t *main)
{
    main->story->quests->quest_id = 9;
    main->story->quests->text = "THE END";
}

void after_jordan_karim(main_t *main)
{
    init_scene_name(main, "Karim", the_end);
}

void after_jordan(main_t *main)
{
    main->story->quests->quest_id = 5;
    main->story->quests->text = "Relire la norme pour s'ameliorer";
}

void pnj_jordan(main_t *main)
{
    story_t *story = main->story;

    if (story->quests->quest_id == 4) {
        create_window_pnj(story, "T'es claque au sol, t'as\n\
obtenu grade D", after_jordan);
    } else if (story->quests->quest_id == 8) {
        create_window_pnj(story, "Avant d'obtenir tes grades\n\
tu dois 1vs1 avec\nKarim", after_jordan_karim);
    } else
        create_window_pnj(story, "Tu veux quoi enfaite ?", nothing);
}