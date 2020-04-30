/*
** EPITECH PROJECT, 2020
** test_fight_rpg
** File description:
** render_fight
*/

#include "fight/render/render_fight.h"

void draw_first_menu(main_t *main_struct)
{
    draw_text(main_struct, "ATTACK", (sfVector2f){100, 800}, 75);
    draw_text(main_struct, "GUARD", (sfVector2f){1500, 800}, 75);
    draw_text(main_struct, "MENU", (sfVector2f){100, 900}, 75);
    draw_text(main_struct, "FLEE", (sfVector2f){1500, 900}, 75);
}

void draw_attack_menu(main_t *main_struct)
{
    int nb = 0;
    attack_list_t *tmp = main_struct->player->attacks;

    for (int y = 800; tmp && y <= 900; y += 100) {
        for (int x = 100; x <= 1500 && tmp; x += 1400, tmp = tmp->next)
            draw_text(main_struct, tmp->attack->name, (sfVector2f){x, y}, 75);
    }
}

void draw_menu(int menu, main_t *main_struct)
{
    (menu == 0) ? draw_first_menu(main_struct) : 0;
    (menu == 1) ? draw_attack_menu(main_struct) : 0;
}

void analyse_event_fight(main_t *main, fight_scene_t *sc)
{
    if (main->event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape))
        sfRenderWindow_close(main->window);
    if (sc->var.scene == 0 && sfKeyboard_isKeyPressed(sfKeyUp))
        sc->cursor->pos.y = (sc->cursor->pos.y != 800) ? 800 : 900;
    if (sc->var.scene == 0 && sfKeyboard_isKeyPressed(sfKeyDown))
        sc->cursor->pos.y = (sc->cursor->pos.y != 900) ? 900 : 800;
    if (sc->var.scene == 0 && sfKeyboard_isKeyPressed(sfKeyLeft))
        sc->cursor->pos.x = (sc->cursor->pos.x != 100) ? 100 : 1500;
    if (sc->var.scene == 0 && sfKeyboard_isKeyPressed(sfKeyRight))
        sc->cursor->pos.x = (sc->cursor->pos.x != 1500) ? 1500 : 100;
    if (main->event.type == sfEvtKeyPressed) {
        if (sc->var.menu == 0 && main->event.key.code == sfKeyEnter)
            analyse_enter_bg(sc);
        else if (sc->var.menu == 1 && main->event.key.code == sfKeyEnter)
            analyse_attack(main, sc);
    }
}

void render_fight(main_t *main_struct, fight_scene_t *scene)
{
    while (sfRenderWindow_isOpen(main_struct->window)) {
        while (RWPE(main_struct->window, &main_struct->event)) {
            if (scene->var.scene == 0)
                analyse_event_fight(main_struct, scene);
            else if (scene->var.scene == 1)
                analyse_event_menu(main_struct, scene);
        }
        sfRenderWindow_clear(main_struct->window, sfBlack);
        (scene->var.scene == 0) ? draw_bg(main_struct, scene) : 0;
        (scene->var.scene == 0) ? draw_menu(scene->var.menu, main_struct) : 0;
        (scene->var.scene == 0) ? draw_enemy(main_struct, scene) : 0;
        (scene->var.scene == 0) ? draw_bar(main_struct, scene) : 0;
        (scene->var.scene == 1) ? drawer_menu_char(main_struct, scene) : 0;
        (scene->var.scene == -1) ? sfRenderWindow_close(main_struct->window) : 0;
        scene->var.menu = (scene->player->com <= 0) ? -1 : scene->var.menu;
        is_dead(scene->enemies, scene);
        sfRenderWindow_display(main_struct->window);
    }
}