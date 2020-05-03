/*
** EPITECH PROJECT, 2020
** test_fight_rpg
** File description:
** analyse_position
*/

#include "fight/render/analyse_position.h"
#include "lib/my.h"

void analyse_enter_bg(fight_scene_t *scene)
{
    if (scene->cursor->pos.x == 100 && scene->cursor->pos.y == 800)
        scene->var.menu = 1;
    if (scene->cursor->pos.x == 1500 && scene->cursor->pos.y == 800)
        scene->var.menu = 2;
    if (scene->cursor->pos.x == 100 && scene->cursor->pos.y == 900) {
        scene->var.scene = 1;
        scene->var.menu = 0;
    }
    if (scene->cursor->pos.x == 1500 && scene->cursor->pos.y == 900)
        scene->var.scene = -1;
}

void draw_stat_attack(int nb, main_t *main, int tab[4])
{
    attack_list_t *tmp = main->player->attacks;
    attack_t *to_draw = NULL;
    int max = get_size_att(tmp);
    int y = 200;
    int ind = 0;

    for (int i = nb; i < nb + 4 && i <= max; i += 1, y += 100, ind += 1) {
        to_draw = get_element_att(tmp, i);
        draw_text(main, to_draw->name, (sfVector2f){800, y}, 75);
        tab[ind] = (i <= max) ? i : -1;
    }
}

void analyse_enter_menu(fight_scene_t *scene)
{
    int y = scene->green->pos.y;

    if (scene->var.menu == 0) {
        if (y == 200) {
            y = 200;
            scene->var.menu = 1;
        }
        (y == 300) ? scene->var.menu = 3 : 0;
    }
    else if (scene->var.menu == 1) {
        (y == 200) ? scene->var.to_print = scene->var.tab[0] : 0;
        (y == 300) ? scene->var.to_print = scene->var.tab[1] : 0;
        (y == 400) ? scene->var.to_print = scene->var.tab[2] : 0;
        (y == 500) ? scene->var.to_print = scene->var.tab[3] : 0;
        scene->var.menu = (scene->var.to_print != -1) ? 2 : 1;
    }
    (scene->var.menu == 0 && y == 400) ? scene->var.scene = 0 : 0;
    (scene->var.menu == 0 && y == 500) ? scene->var.scene = -1 : 0;
}

void printer(attack_t *attack, main_t *main)
{
    draw_text(main, "NOM:", (sfVector2f){500, 200}, 75);
    draw_text(main, attack->name, (sfVector2f){700, 200}, 75);
    draw_text(main, "PUISSANCE:", (sfVector2f){500, 300}, 75);
    draw_text(main, my_itoa(attack->dam_com), (sfVector2f){770, 300}, 75);
    draw_text(main, "COUT INTELLIGENCE:", (sfVector2f){500, 400}, 75);
    draw_text(main, my_itoa(attack->req_intel), (sfVector2f){1000, 400}, 75);
    draw_text(main, "COUT RAM:", (sfVector2f){500, 500}, 75);
    draw_text(main, my_itoa(attack->req_intel), (sfVector2f){800, 500}, 75);
}

void draw_stat_player(player_t *player, main_t *main)
{
    char *tmp = my_strcat(my_itoa(player->com), "/");

    draw_text(main, "NOM:", (sfVector2f){500, 200}, 60);
    draw_text(main, player->name, (sfVector2f){700, 200}, 60);
    tmp = my_strcat(tmp, my_itoa(player->com_max));
    draw_text(main, "ENGAGEMENT:", (sfVector2f){500, 270}, 60);
    draw_text(main, tmp, (sfVector2f){850, 270}, 60);
    draw_text(main, "FORCE:", (sfVector2f){500, 340}, 60);
    draw_text(main, my_itoa(player->force), (sfVector2f){700, 340}, 60);
    draw_text(main, "DEFENSE:", (sfVector2f){500, 410}, 60);
    draw_text(main, my_itoa(player->defence), (sfVector2f){750, 410}, 60);
    draw_text(main, "GPA:", (sfVector2f){500, 480}, 60);
    draw_text(main, my_ftostr(player->gpa, 2), (sfVector2f){650, 480}, 60);
    draw_text(main, "INTELLIGENCE:", (sfVector2f){500, 550}, 60);
    draw_text(main, my_itoa(player->intel), (sfVector2f){850, 550}, 60);
    draw_text(main, "RAPIDITE:", (sfVector2f){500, 620}, 60);
    draw_text(main, my_itoa(player->speed), (sfVector2f){700, 620}, 60);
}