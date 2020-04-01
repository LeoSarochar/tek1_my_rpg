/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** render.c
*/

#include "story/story.h"

void render_pnjs(main_t *main)
{
    for (int i = 0; i < main->story->nb_pnjs; i++) {
        if (main->story->pnjs[i].sprite->visible == sfTrue) {
            printf("Render %s\n", main->story->pnjs[i].name);
            sfSprite_setPosition(main->story->pnjs[i].sprite->sprite, vec{50, 50});
            RWDS(main->window, main->story->pnjs[i].sprite->sprite, NULL);
        }
    }
}