/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** story
*/

#include "story/quests.h"

void init_quests(main_t *main)
{
    quests_t *quests = malloc(sizeof(quests_t));
    char *bg_path = "ressources/quests/quest_background.png";

    main->story->quests = quests;
    quests->quest_id = 1;
    quests->show_quests = 1;
    quests->background = load_sprite(bg_path);
    sfSprite_setScale(quests->background->sprite, (sfVector2f){0.5, 0.5});
    quests->text = "Aller voir Lucas, votre AER";
}

void render_quests(main_t *main)
{
    quests_t *quests = main->story->quests;

    if (!quests->show_quests)
        return;
    sfRenderWindow_drawSprite(main->window, quests->background->sprite, NULL);
    draw_text(main, quests->text, (sfVector2f){30, 20}, 25);
}