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
    main_t main_struct;
    sfVideoMode mode = {1920, 1080, 32};

    main_struct.window = SFWC(mode, "Road 4 GPA", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(main_struct.window, 64);
    init(&main_struct);
    sfVector2f size = {960, 540};
    sfView *View = sfView_create();
    sfView_setSize(View, size);
    while (sfRenderWindow_isOpen(main_struct.window)) {
        while (RWPE(main_struct.window, &main_struct.event))
            game_event(&main_struct);
        render(&main_struct);
        sfVector2f center = {main_struct.pm.player.pos.x + 32, main_struct.pm.player.pos.y + 33};
        sfRenderWindow_setView(main_struct.window, View);
        sfView_setCenter(View, center);
    }
    return (0);
}