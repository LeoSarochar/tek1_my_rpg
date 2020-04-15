/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** render.c
*/

#include "story/story.h"

void check_player_talk(pnj_t pnj, main_t *main)
{
    sfVector2f pos = main->pm.player.pos;
    sfFloatRect bounds = sfSprite_getGlobalBounds(pnj.sprite->sprite);
    sfBool res = sfFloatRect_contains(&bounds, pos.x, pos.y);

    if (res == sfTrue && main->story->current_pnj == NULL) {
        main->story->current_pnj = &(pnj);
        printf("Player On : %s\n", pnj.name);
        pnj.onclick(main->story);
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