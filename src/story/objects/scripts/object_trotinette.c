/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** script file
*/

#include "story/story.h"

void after_trotinette(main_t *main)
{
    story_t *story = main->story;

    set_attrib(main, 40, 0, 0);
    story->current_object->sprite->visible = 0;
    main->s_menu.item[5]->num = assign_num(main);
    main->s_menu.item[5]->state = 1;
}