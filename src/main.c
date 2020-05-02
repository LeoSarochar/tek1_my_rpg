/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** main.c
*/

#include "main.h"
#include "events.h"*

void close_window(main_t *main_struct, UNUSED sfEvent event)
{
    destoy_menu(main_struct);
    sfRenderWindow_close(main_struct->window);
}

void game_event(main_t *main_struct)
{
    if (main_struct->player->fight_scene) {
        if (main_struct->player->fight_scene->var.scene == 0)
            analyse_event_fight(main_struct, main_struct->player->fight_scene);
        else if (main_struct->player->fight_scene->var.scene == 1)
            analyse_event_menu(main_struct, main_struct->player->fight_scene);
    }
    for (int i = 0; events_funcs[i].event != sfEvtCount; i++)
        if (events_funcs[i].event == main_struct->event.type) {
            events_funcs[i].ptr(main_struct, main_struct->event);
        }
}

int main(UNUSED int ac, UNUSED char **av)
{
    int bol = 0;
    main_t main_struct;
    sfVideoMode mode = {1920, 1080, 32};
    for (int i = 0; i < 3; i += 1) {
        main_struct.map[i] = malloc(sizeof(char**) * 3);;
    }
    main_struct.map[1] = get_collision("./ressources/maps/map_cols/sm1_cols.txt");
    main_struct.map[2] = get_collision("./ressources/maps/map_cols/corridor_cols.txt");
    main_struct.map[3] = get_collision("./ressources/maps/map_cols/ground_cols.txt");

    main_struct.window = SFWC(mode, "Road 4 GPA", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(main_struct.window, 64);
    init(&main_struct);
    while (sfRenderWindow_isOpen(main_struct.window)) {
        while (RWPE(main_struct.window, &main_struct.event)) {
            game_event(&main_struct);
        }
        (bol == 0) ? (first_process(&main_struct), bol++): 0;
        if (main_struct.s_menu.bol_menu == 1) {
            exec_menu(&main_struct);
        } else if (main_struct.s_menu.bol_pause == 1) {
            exec_pause(&main_struct);
        } else
            render(&main_struct);
        // printf("x = %f y = %f\n", main_struct.pm.player.pos.x, main_struct.pm.player.pos.y);
    }
    return (0);
}
