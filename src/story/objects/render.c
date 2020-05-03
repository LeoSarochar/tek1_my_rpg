/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** render.c
*/

#include "story/story.h"

int check_player_interract(object_t object, main_t *main)
{
    sfBool res = player_can_interact_object(main, object, 120);
    sfVector2f take_text_pos = {object.pos.x - 10, object.pos.y - 20};
    sfVector2f text_pos = {object.pos.x, object.pos.y - 20};

    if (res == sfTrue) {
        draw_text(main, "E : prendre", take_text_pos, 15);
        return (1);
    } else {
        draw_text(main, object.name, text_pos, 15);
    }
    return (0);
}

void    gest_norm_book_clock(story_t *story)
{
    sfClock *clock = story->objects_clock;
    object_t *book = get_object_by_name(story, "Norme");
    float seconds = 0.0;

    if (!book)
        return;
    seconds = sfClock_getElapsedTime(clock).microseconds / 1000000.0;
    if (seconds < 0.2)
        return;
    if (book->sprite->rect->left < 141)
        book->sprite->rect->left += 28.5;
    else
        book->sprite->rect->left = 0;
    sfSprite_setTextureRect(book->sprite->sprite, *(book->sprite->rect));
    sfClock_restart(clock);
}

void render_objects(main_t *main)
{
    object_t cur_object;
    int cur_scene = main->pm.player.scene;

    if (main->player->fight_scene)
        return;
    gest_norm_book_clock(main->story);
    for (int i = 0; i < main->story->nb_objects; i++) {
        cur_object = main->story->objects[i];
        if (!cur_object.sprite->visible || cur_object.map_scene != cur_scene)
            continue;
        sfSprite_setPosition(cur_object.sprite->sprite, cur_object.pos);
        RWDS(main->window, cur_object.sprite->sprite, NULL);
        check_player_interract(cur_object, main);
    }
}