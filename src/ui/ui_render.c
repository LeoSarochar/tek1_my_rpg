/*
** EPITECH PROJECT, 2020
** all_renderfonc_ui
** File description:
** rpg
*/

#include "screen_menu.h"
#include "main.h"
#include "csfml_binding.h"
#include "first_plan_screen.h"


void disp_pause(main_t *struct_main)
{
    struct_main->s_menu.time_menu = sfClock_getElapsedTime(struct_main->s_menu.clock_menu);
    struct_main->s_menu.sec_menu = struct_main->s_menu.time_menu.microseconds / 100000.0;
    if (struct_main->s_menu.sec_menu > 1) {
        sfRenderWindow_clear(struct_main->window, sfBlack);
        sfView_setSize(struct_main->story->fixed, (sfVector2f){1920, 1080});
        sfView_setCenter(struct_main->story->fixed, (sfVector2f){960, 530});
        sfRenderWindow_setView(struct_main->window, struct_main->story->fixed);
        for (int i = 0; i < 4; i++) {
            sfRenderWindow_drawSprite(struct_main->window, struct_main->s_menu.button_pause[i]->sprite, NULL);
            sfRenderWindow_drawText(struct_main->window, struct_main->s_menu.text_pause[i]->txt1, NULL);
        }
        sfRenderWindow_display(struct_main->window);
    }
}

void render_inv(main_t *structm)
{
    sfView_setSize(structm->story->fixed, (sfVector2f){1920, 1080});
    sfView_setCenter(structm->story->fixed, (sfVector2f){960, 530});
    sfRenderWindow_setView(structm->window, structm->story->fixed);
    sfRenderWindow_drawSprite(structm->window, structm->s_menu.inv.sprite, NULL);
    get_mouse(structm);
    for (int i = 0; i < 6; i++) {
        if (structm->s_menu.item[i]->state == 1) {
            (structm->s_menu.item[i]->num == 0) ? sfSprite_setPosition(structm->s_menu.item[i]->sprite, (sfVector2f){722, 415}) : 0;
            (structm->s_menu.item[i]->num == 1) ? sfSprite_setPosition(structm->s_menu.item[i]->sprite, (sfVector2f){800, 415}) : 0;
            (structm->s_menu.item[i]->num == 2) ? sfSprite_setPosition(structm->s_menu.item[i]->sprite, (sfVector2f){722, 487}) : 0;
            (structm->s_menu.item[i]->num == 3) ? sfSprite_setPosition(structm->s_menu.item[i]->sprite, (sfVector2f){800, 487}) : 0;
            (structm->s_menu.item[i]->num == 4) ? sfSprite_setPosition(structm->s_menu.item[i]->sprite, (sfVector2f){800, 560}) : 0;
            (structm->s_menu.item[i]->num == 5) ? sfSprite_setPosition(structm->s_menu.item[i]->sprite, (sfVector2f){722, 560}) : 0;
            sfRenderWindow_drawSprite(structm->window, structm->s_menu.item[i]->sprite, NULL);
        }
        if (structm->s_menu.item[i]->state == 2)
            wear_stuff(structm->s_menu.item[i], structm);
    }
}

void disp_menu(main_t *struct_main)
{
    static int i = 0;

    if (struct_main->s_menu.bgt_menu[i + 1] == NULL)
        i = 0;
    struct_main->s_menu.time_menu = sfClock_getElapsedTime(struct_main->s_menu.clock_menu);
    struct_main->s_menu.sec_menu = struct_main->s_menu.time_menu.microseconds / 100000.0;
    if (struct_main->s_menu.sec_menu > 1) {
        sfRenderWindow_clear(struct_main->window, sfBlack);
        SST(struct_main->s_menu.bgs_menu, (struct_main->s_menu.bgt_menu[i]), sfTrue);
        sfClock_restart(struct_main->s_menu.clock_menu);
        i++;
        sfRenderWindow_drawSprite(struct_main->window, struct_main->s_menu.bgs_menu, NULL);
        for (int i = 0; i < 4; i++) {
            sfRenderWindow_drawSprite(struct_main->window, struct_main->s_menu.button[i]->sprite, NULL);
            sfRenderWindow_drawText(struct_main->window, struct_main->s_menu.text[i]->txt1, NULL);
        }
        sfRenderWindow_display(struct_main->window);
    }
}

void handle_pause_menu(main_t *main, sfEvent event)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyP)
        main->s_menu.bol_pause = !(main->s_menu.bol_pause);
}

void handle_inv(main_t *main, sfEvent event)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyI)
        main->s_menu.inv.disp = !(main->s_menu.inv.disp);
}