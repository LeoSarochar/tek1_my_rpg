/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** objects events
*/

#include "story/story.h"

void handle_object_event(main_t *main, sfEvent event)
{
    if (event.key.code != sfKeyE)
        return;
    for (int i = 0; i < main->story->nb_objects; i++) {
        if (main->story->objects[i].sprite->visible == sfFalse)
            continue;
        if (player_can_interact_object(main, main->story->objects[i], 120)) {
            main->story->current_object = &(main->story->objects[i]);
            main->story->objects[i].onclick(main);
        }
    }
}