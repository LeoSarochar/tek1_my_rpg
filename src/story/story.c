/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** story
*/

#include "story/story.h"

void handle_pnj_event(main_t *main, sfEvent event)
{
    sfVector2f pos = main->pm.player.pos;
    sfFloatRect bounds;

    if (event.key.code == sfKeyEscape) {
        main->story->current_pnj = NULL;
        main->story->show_window = 0;
    }
    if (event.key.code != sfKeyE)
        return;
    for (int i = 0; i < main->story->nb_pnjs; i++) {
        if (main->story->pnjs[i].sprite->visible == sfFalse)
            continue;
        bounds = sfSprite_getGlobalBounds(main->story->pnjs[i].sprite->sprite);
        if (sfFloatRect_contains(&bounds, pos.x, pos.y)) {
            main->story->current_pnj = &(main->story->pnjs[i]);
            main->story->pnjs[i].onclick(main->story);
        }
    }
}

void create_window(story_t *story, char *text, void (*ptr)(story_t *))
{
    pnj_t *pnj = story->current_pnj;
    sfVector2f pos = (sfVector2f){pnj->pos.x + 250, pnj->pos.y};
    sfVector2f pos_avatar = (sfVector2f){pnj->pos.x + 680, pnj->pos.y + 30};
    story->w_avatar = load_sprite(story->current_pnj->path);

    story->w_background = load_sprite("ressources/pnjs/pnj_background.png");
    sfSprite_setScale(story->w_background->sprite, (sfVector2f){0.5, 0.5});
    sfSprite_setPosition(story->w_background->sprite, pos);
    sfSprite_setScale(story->w_avatar->sprite, (sfVector2f){0.8, 0.8});
    sfSprite_setPosition(story->w_avatar->sprite, pos_avatar);
    story->w_text = text;
    story->show_window = 1;
}

void test(story_t *story)
{
    printf("Test\n");
    create_window(story, "J'aime les fraises\nA la moutarde !", NULL);
}

void init_story(main_t *main)
{
    story_t *story = malloc(sizeof(story_t));
    pnj_t *pnj = NULL;

    story->pnjs = NULL;
    story->current_pnj = NULL;
    story->nb_pnjs = 0;
    main->story = story;
    main->story->show_window = 0;

    pnj = create_pnj(main->story, "Louis", "ressources/pnjs/boulet.jpg", test);
    pnj->pos = (sfVector2f){500, 500};
    pnj = create_pnj(main->story, "Lucas", "ressources/pnjs/sanchez.png", test);
    pnj->pos = (sfVector2f){50, 100};
}