/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** pnj events
*/

#include "story/story.h"

void create_window_pnj(story_t *story, char *text, void (*ptr)(story_t *))
{
    pnj_t *pnj = story->current_pnj;
    sfVector2f pos = (sfVector2f){pnj->pos.x + 250, pnj->pos.y};
    sfVector2f pos_avatar = (sfVector2f){pnj->pos.x + 690, pnj->pos.y + 30};
    story->w_avatar = load_sprite(story->current_pnj->path);

    story->w_background = load_sprite("ressources/pnjs/pnj_background.png");
    sfSprite_setScale(story->w_background->sprite, (sfVector2f){0.5, 0.5});
    sfSprite_setPosition(story->w_background->sprite, pos);
    sfSprite_setScale(story->w_avatar->sprite, (sfVector2f){0.8, 0.8});
    sfSprite_setPosition(story->w_avatar->sprite, pos_avatar);
    story->w_text = text;
    story->onclose = ptr;
    story->show_window = 1;
}

void handle_pnj_event(main_t *main, sfEvent event)
{
    sfVector2f pos = main->pm.player.pos;
    sfFloatRect bounds;

    if (event.key.code == sfKeyEscape && main->story->show_window) {
        main->story->show_window = 0;
        main->story->onclose(main);
        main->story->current_pnj = NULL;
    }
    if (event.key.code != sfKeyE)
        return;
    for (int i = 0; i < main->story->nb_pnjs; i++) {
        if (main->story->pnjs[i].sprite->visible == sfFalse)
            continue;
        bounds = sfSprite_getGlobalBounds(main->story->pnjs[i].sprite->sprite);
        if (sfFloatRect_contains(&bounds, pos.x, pos.y)) {
            main->story->current_pnj = &(main->story->pnjs[i]);
            main->story->pnjs[i].onclick(main);
        }
    }
}