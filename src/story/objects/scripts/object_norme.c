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
    story->quests->text = "Retourner voir Sanchez pour\n
apprendre a coder my_putchar";
    story->quests->quest_id = 3;
}

void after_norme_book_again(main_t *main)
{
    main->story->quests->quest_id = 5;
    main->story->quests->text = "Retourner voir Sanchez";
}