/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** render.c
*/

#include "story/story.h"

void draw_text(main_t *main, char *to_write, sfVector2f pos)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("./ressources/BebasNeue-Regular.ttf");

    sfText_setPosition(text, pos);
    sfText_setFont(text, font);
    sfText_setString(text, to_write);
    sfText_setCharacterSize(text, 35);
    sfText_setColor(text, sfWhite);
    sfRenderWindow_drawText(main->window, text, NULL);
    sfFont_destroy(font);
    sfText_destroy(text);
}

void check_player_talk(pnj_t pnj, main_t *main)
{
    sfVector2f pos = main->pm.player.pos;
    sfFloatRect bounds = sfSprite_getGlobalBounds(pnj.sprite->sprite);
    sfBool res = sfFloatRect_contains(&bounds, pos.x, pos.y);

    if (res == sfTrue) {
        if (!main->story->current_pnj)
            main->story->current_pnj = &(pnj);
        draw_text(main, "E : interagir", (sfVector2f){pnj.pos.x + 60, pnj.pos.y});
        if (sfKeyboard_isKeyPressed(sfKeyE))
            main->story->current_pnj->sprite->visible = 0;
    } else {
        draw_text(main, pnj.name, (sfVector2f){pnj.pos.x + 100, pnj.pos.y});
    }
    if (main->story->show_window) {
        sfRectangleShape_setPosition(main->story->shape, (sfVector2f){pnj.pos.x + 100, pnj.pos.y});
        sfRenderWindow_drawRectangleShape(main->window, main->story->shape, NULL);
        draw_text(main, "Salut, Je suis Louis, voilà voilà", (sfVector2f){pnj.pos.x + 100, pnj.pos.y});
    }
}

void render_pnjs(main_t *main)
{
    for (int i = 0; i < main->story->nb_pnjs; i++) {
        if (main->story->pnjs[i].sprite->visible == sfTrue) {
            sfSprite_setPosition(main->story->pnjs[i].sprite->sprite, vec{50, 50});
            RWDS(main->window, main->story->pnjs[i].sprite->sprite, NULL);
            check_player_talk(main->story->pnjs[i], main);
        }
    }
}