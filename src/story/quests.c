/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** story
*/

#include "story/quests.h"

void nothing(main_t *main)
{
    (void)main;
    return;
}

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

void custom_quests_render(main_t *main)
{
    if (main->story->quests->quest_id == 5) {
        if (main->s_menu.item[0]->state == 2) {
            main->story->quests->quest_id = 6;
            main->story->quests->text = "Va voir Nathan, ton super AER TeK2";
        }
    }
}

void render_quests(main_t *main)
{
    quests_t *quests = main->story->quests;

    if (main->player->fight_scene)
        return;
    if (!quests->show_quests)
        return;
    sfView_setSize(main->story->fixed, (sfVector2f){1920, 1080});
    sfView_setCenter(main->story->fixed, (sfVector2f){960, 530});
    sfRenderWindow_setView(main->window, main->story->fixed);
    sfRenderWindow_drawSprite(main->window, quests->background->sprite, NULL);
    draw_text(main, quests->text, (sfVector2f){30, 20}, 25);
    custom_quests_render(main);
}