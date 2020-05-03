/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** render.c
*/

#include "story/story.h"

int check_player_talk(pnj_t pnj, main_t *main)
{
    int res = player_can_interact_pnj(main, pnj, 80);

    if (res == sfTrue) {
        draw_text(main, "E : interagir",\
        (sfVector2f){pnj.pos.x - 10, pnj.pos.y - 15}, 15);
        return (1);
    } else {
        draw_text(main, pnj.name,\
        (sfVector2f){pnj.pos.x + 10, pnj.pos.y - 15}, 15);
    }
    return (0);
}

void renderPNJWindow(main_t *main)
{
    story_t *story = main->story;
    sfVector2f pos_text = (sfVector2f){780, 200};
    sfVector2f pos = (sfVector2f){1220, 345};
    sfVector2f pos_echap = (sfVector2f){780, 360};

    sfView_setSize(main->story->fixed, (sfVector2f){1920, 1080});
    sfView_setCenter(main->story->fixed, (sfVector2f){960, 530});
    sfRenderWindow_setView(main->window, main->story->fixed);
    sfRenderWindow_drawSprite(main->window, story->w_background->sprite, NULL);
    sfRenderWindow_drawSprite(main->window, story->w_avatar->sprite, NULL);
    draw_text(main, story->w_text, pos_text, 35);
    draw_text(main, story->current_pnj->name, pos, 35);
    draw_text(main, "(Echap -> Fermer)", pos_echap, 20);
}

void render_pnjs(main_t *main)
{
    pnj_t cur_pnj;
    int cur_scene = main->pm.player.scene;

    if (main->player->fight_scene)
        return;
    for (int i = 0; i < main->story->nb_pnjs; i++) {
        cur_pnj = main->story->pnjs[i];
        if (!cur_pnj.sprite->visible || cur_pnj.map_scene != cur_scene)
            continue;
        sfSprite_setPosition(cur_pnj.sprite->sprite, cur_pnj.pos);
        RWDS(main->window, cur_pnj.sprite->sprite, NULL);
        check_player_talk(cur_pnj, main);
    }
    if (main->story->show_window == 1)
        renderPNJWindow(main);
}