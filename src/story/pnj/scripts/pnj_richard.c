/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** script file
*/

#include "story/story.h"

void pnj_richard(main_t *main)
{
    story_t *story = main->story;

    create_window_pnj(story, "Je suis ton super delegue", nothing);
}