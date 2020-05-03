/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** pnj events
*/

#include "story/story.h"

void create_window_pnj(story_t *story, char *text, void (*ptr)(main_t *))
{
    sfVector2f pos = (sfVector2f){750, 180};
    sfVector2f pos_avatar = (sfVector2f){1190, 210};
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
    pnj_t cur_pnj;
    int cur_scene = main->pm.player.scene;

    if (event.key.code == sfKeyEscape && main->story->show_window) {
        main->story->show_window = 0;
        main->story->onclose(main);
        main->story->current_pnj = NULL;
    }
    if (event.key.code != sfKeyE)
        return;
    for (int i = 0; i < main->story->nb_pnjs; i++) {
        cur_pnj = main->story->pnjs[i];
        if (!cur_pnj.sprite->visible || cur_pnj.map_scene != cur_scene)
            continue;
        if (player_can_interact_pnj(main, main->story->pnjs[i], 80)) {
            main->story->current_pnj = &(main->story->pnjs[i]);
            main->story->pnjs[i].onclick(main);
        }
    }
}