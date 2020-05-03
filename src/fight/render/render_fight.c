/*
** EPITECH PROJECT, 2020
** test_fight_rpg
** File description:
** render_fight
*/

#include "fight/render/render_fight.h"

void draw_first_menu(main_t *main_struct)
{
    draw_text(main_struct, "ATTAQUER", (sfVector2f){100, 800}, 75);
    draw_text(main_struct, "DEFENDRE", (sfVector2f){1500, 800}, 75);
    draw_text(main_struct, "MENU", (sfVector2f){100, 900}, 75);
    draw_text(main_struct, "FUIR", (sfVector2f){1500, 900}, 75);
}

void draw_attack_menu(main_t *main_struct)
{
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
    if (main->event.type == sfEvtClosed)
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
        if (sc->var.menu == 0 && main->event.key.code == 58)
            analyse_enter_bg(sc);
        else if ((sc->var.menu == 1 || sc->var.menu == 2) \
        && main->event.key.code == 58)
            analyse_attack(main, sc);
    }
    if (sc->var.menu == 2) {
        enemy_turn_attack(main->player, sc->enemies->enemy, 1);
        sc->var.menu = 0;
    }
}

void render_fight(main_t *main, fight_scene_t *sc)
{
    if (!main->player->fight_scene)
        return;
    sfView_setSize(main->story->fixed, (sfVector2f){1920, 1080});
    sfView_setCenter(main->story->fixed, (sfVector2f){960, 530});
    sfRenderWindow_setView(main->window, main->story->fixed);
    enter_combat(main);
    (sc->var.scene == 0) ? draw_bg(main, sc) : 0;
    (sc->var.scene == 0) ? draw_menu(sc->var.menu, main) : 0;
    (sc->var.scene == 0) ? draw_enemy(main, sc) : 0;
    (sc->var.scene == 0) ? draw_bar(main, sc) : 0;
    (sc->var.scene == 0) ? draw_player(main) : 0;
    (sc->var.menu == 10) ? write_enemy(sc->enemies->enemy->lastattack,
    sc->enemies->enemy->name, main) : 0;
    (sc->var.scene == 1) ? drawer_menu_char(main, sc) : 0;
    render_fight2(main, sc);
}