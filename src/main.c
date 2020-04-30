/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** main.c
*/

#include "main.h"
#include "events.h"

void close_window(main_t *main_struct, UNUSED sfEvent event)
{
    destoy_menu(main_struct);
    sfRenderWindow_close(main_struct->window);
    sfRenderWindow_destroy(main_struct->window);
}

void game_event(main_t *main_struct)
{
    for (int i = 0; events_funcs[i].event != sfEvtCount; i++)
        if (events_funcs[i].event == main_struct->event.type) {
            events_funcs[i].ptr(main_struct, main_struct->event);
            break;
        }
}

int main(UNUSED int ac, UNUSED char **av)
{
    int bol = 0;
    main_t main_struct;
    sfVideoMode mode = {1920, 1080, 32};
    sfView *View = sfView_create();

    main_struct.window = SFWC(mode, "Road 4 GPA", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(main_struct.window, 64);
    init(&main_struct);
    sfView_setSize(View, (sfVector2f){960, 540});
    while (sfRenderWindow_isOpen(main_struct.window)) {
        while (RWPE(main_struct.window, &main_struct.event))
            game_event(&main_struct);
        (bol == 0) ? (first_process(&main_struct), bol++): 0;
        (main_struct.s_menu.bol_menu == 1) ? exec_menu(&main_struct) : render(&main_struct);
        render(&main_struct);
        player_move(&main_struct);
        sfVector2f center = {main_struct.pm.player.pos.x + 32, main_struct.pm.player.pos.y + 33};
        sfRenderWindow_setView(main_struct.window, View);
        sfView_setCenter(View, center);
    }
    return (0);
}