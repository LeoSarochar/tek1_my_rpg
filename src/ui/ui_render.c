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
    struct_main->s_menu.time_menu = CET(struct_main->s_menu.clock_menu);
    struct_main->s_menu.sec_menu = DIV_SEC;
    if (struct_main->s_menu.sec_menu > 1) {
        sfRenderWindow_clear(struct_main->window, sfBlack);
        sfView_setSize(struct_main->story->fixed, (sfVector2f){1920, 1080});
        sfView_setCenter(struct_main->story->fixed, (sfVector2f){960, 530});
        sfRenderWindow_setView(struct_main->window, struct_main->story->fixed);
        for (int i = 0; i < 4; i++) {
            RWDS(WIN, struct_main->s_menu.button_pause[i]->sprite, NULL);
            RWT(WIN, struct_main->s_menu.text_pause[i]->txt1, NULL);
        }
        disp_option_pause(struct_main);
        cond_disp_part(struct_main);
        sfRenderWindow_display(struct_main->window);
    }
}

void render_inv(main_t *structm)
{
    sfView_setSize(structm->story->fixed, (sfVector2f){1920, 1080});
    sfView_setCenter(structm->story->fixed, (sfVector2f){960, 530});
    sfRenderWindow_setView(structm->window, structm->story->fixed);
    RWDS(structm->window, structm->s_menu.inv.sprite, NULL);
    get_mouse(structm);
    for (int i = 0; i < 6; i++) {
        if (structm->s_menu.item[i]->state == 1) {
            (NUM(i) == 0) ? SP(MIS(i), VEC(722, 415)) : 0;
            (NUM(i) == 1) ? SP(MIS(i), VEC(800, 415)) : 0;
            (NUM(i) == 2) ? SP(MIS(i), VEC(722, 487)) : 0;
            (NUM(i) == 3) ? SP(MIS(i), VEC(800, 487)) : 0;
            (NUM(i) == 4) ? SP(MIS(i), VEC(800, 560)) : 0;
            (NUM(i) == 5) ? SP(MIS(i), VEC(722, 560)) : 0;
            RWDS(structm->window, structm->s_menu.item[i]->sprite, NULL);
        }
        if (structm->s_menu.item[i]->state == 2)
            wear_stuff(structm->s_menu.item[i], structm);
    }
}

void disp_menu(main_t *struct_main)
{
    static int i = 0;

    if (i == 10)
        i = 0;
    struct_main->s_menu.time_menu = CET(struct_main->s_menu.clock_menu);
    struct_main->s_menu.sec_menu = DIVSEC;
    if (struct_main->s_menu.sec_menu > 1) {
        sfRenderWindow_clear(struct_main->window, sfBlack);
        SST(SM, (struct_main->s_menu.bgt_menu[i]), sfTrue);
        sfClock_restart(struct_main->s_menu.clock_menu);
        i++;
        RWDS(struct_main->window, struct_main->s_menu.bgs_menu, NULL);
        for (int i = 0; i < 4; i++) {
            RWDS(WIN, struct_main->s_menu.button[i]->sprite, NULL);
            RWT(struct_main->window, struct_main->s_menu.text[i]->txt1, NULL);
        }
    }
    disp_cred(struct_main);
    cond_disp_part(struct_main);
    sfRenderWindow_display(struct_main->window);
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