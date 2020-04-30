/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** render.c
*/

#include "story/story.h"

void draw_text(main_t *main, char *to_write, sfVector2f pos, int size)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("./ressources/BebasNeue-Regular.ttf");

    sfText_setPosition(text, pos);
    sfText_setFont(text, font);
    sfText_setString(text, to_write);
    sfText_setCharacterSize(text, size);
    sfText_setColor(text, sfWhite);
    sfRenderWindow_drawText(main->window, text, NULL);
    sfFont_destroy(font);
    sfText_destroy(text);
}

int check_player_talk(pnj_t pnj, main_t *main)
{
    sfVector2f pos = main->pm.player.pos;
    sfFloatRect bounds = sfSprite_getGlobalBounds(pnj.sprite->sprite);
    sfBool res = sfFloatRect_contains(&bounds, pos.x, pos.y);

    if (res == sfTrue) {
        draw_text(main, "E : interagir", (sfVector2f){pnj.pos.x + 20, pnj.pos.y - 40}, 35);
        return (1);
    } else {
        draw_text(main, pnj.name, (sfVector2f){pnj.pos.x + 50, pnj.pos.y - 40}, 35);
    }
    return (0);
}

void renderPNJWindow(main_t *main)
{
    story_t *story = main->story;
    pnj_t *pnj = story->current_pnj;
    sfVector2f pos_text = (sfVector2f){pnj->pos.x + 280, pnj->pos.y + 20};
    sfVector2f pos = (sfVector2f){pnj->pos.x + 720, pnj->pos.y + 165};
    sfVector2f pos_echap = (sfVector2f){pnj->pos.x + 280, pnj->pos.y + 180};

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

    for (int i = 0; i < main->story->nb_pnjs; i++) {
        cur_pnj = main->story->pnjs[i];
        if (cur_pnj.sprite->visible == sfFalse)
            continue;
        sfSprite_setPosition(cur_pnj.sprite->sprite, cur_pnj.pos);
        RWDS(main->window, cur_pnj.sprite->sprite, NULL);
        check_player_talk(cur_pnj, main);
    }
    if (main->story->show_window == 1)
        renderPNJWindow(main);
}