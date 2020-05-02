/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** script file
*/

#include "story/story.h"

void after_norme_book(main_t *main)
{
    story_t *story = main->story;

    story->current_object->sprite->visible = 0;
    story->quests->text = "Retourner voir Sanchez pour\napprendre a coder my_putchar";
    story->quests->quest_id = 3;
}
