/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** script file
*/

#include "story/story.h"

void pnj_bryan(main_t *main)
{
    story_t *story = main->story;

    create_window_pnj(story, "React ? C'est nul.\nVive Angular !", nothing);
}