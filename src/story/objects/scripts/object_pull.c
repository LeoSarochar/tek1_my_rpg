/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** script file
*/

#include "story/story.h"

void after_pull(main_t *main)
{
    story_t *story = main->story;

    set_attrib(main, 10, 5, 0);
    story->current_object->sprite->visible = 0;
    main->s_menu.item[2]->num = assign_num(main);
    main->s_menu.item[2]->state = 1;
}