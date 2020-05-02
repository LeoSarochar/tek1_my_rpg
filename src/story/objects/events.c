/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** objects events
*/

#include "story/story.h"

void handle_object_event(main_t *main, sfEvent event)
{
    sfVector2f pos = main->pm.player.pos;
    sfFloatRect bds;

    if (event.key.code != sfKeyE)
        return;
    for (int i = 0; i < main->story->nb_objects; i++) {
        if (main->story->objects[i].sprite->visible == sfFalse)
            continue;
        bds = sfSprite_getGlobalBounds(main->story->objects[i].sprite->sprite);
        bds.top -= 20;
        bds.left -= 20;
        bds.height += 40;
        bds.width += 40;
        if (sfFloatRect_contains(&bds, pos.x, pos.y)) {
            main->story->current_object = &(main->story->objects[i]);
            main->story->objects[i].onclick(main);
        }
    }
}