/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** render.c
*/

#include "story/story.h"

int check_player_interract(object_t object, main_t *main)
{
    sfVector2f pos = main->pm.player.pos;
    sfFloatRect bounds = sfSprite_getGlobalBounds(object.sprite->sprite);
    sfBool res = sfFloatRect_contains(&bounds, pos.x, pos.y);

    if (res == sfTrue) {
        draw_text(main, "E : prendre", (sfVector2f){object.pos.x + 20, object.pos.y - 40}, 35);
        return (1);
    } else {
        draw_text(main, object.name, (sfVector2f){object.pos.x + 50, object.pos.y - 40}, 35);
    }
    return (0);
}

void render_objects(main_t *main)
{
    object_t cur_object;

    for (int i = 0; i < main->story->nb_objects; i++) {
        cur_object = main->story->objects[i];
        if (cur_object.sprite->visible == sfFalse)
            continue;
        sfSprite_setPosition(cur_object.sprite->sprite, cur_object.pos);
        RWDS(main->window, cur_object.sprite->sprite, NULL);
        check_player_interract(cur_object, main);
    }
}