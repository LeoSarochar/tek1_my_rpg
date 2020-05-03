/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** script file
*/

#include "story/story.h"

void pnj_jackette(main_t *main)
{
    story_t *story = main->story;

    create_window_pnj(story, "On m'appel l'Ovni", nothing);
}