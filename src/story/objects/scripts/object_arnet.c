/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** script file
*/

#include "story/story.h"

void after_arnet(main_t *main)
{
    story_t *story = main->story;

    story->current_object->sprite->visible = 0;
    main->s_menu.item[4]->num = assign_num(main);
    main->s_menu.item[4]->state = 1;
}