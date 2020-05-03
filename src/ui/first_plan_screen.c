/*
** EPITECH PROJECT, 2020
** first shoot screen
** File description:
** init display and destroy
*/

#include "first_plan_screen.h"

char *my_strdup(char *src)
{
    char *dest;
    int length;

    length = my_strlen(src);
    dest = malloc(length + 1);
    length = 0;
    while (src[length] != '\0'){
        dest[length] = src[length];
        length = length + 1;
    }
    dest[length] = '\0';
    return (dest);
}

void init_all_first(UNUSED main_t *struct_main, init_pop_t *pop)
{
    char *name = my_strdup("ressources/ui/unlock/unlock01.jpg");

    pop->Tfirst_display = malloc(sizeof(sfTexture *) * 86);
    pop->Tfirst_display[85] = NULL;
    pop->Sfirst_display = sfSprite_create();
    pop->clock = sfClock_create();
    pop->sec = 0;
    for (int i = 0; i < 85; i++) {
        pop->Tfirst_display[i] = CFF(name, NULL);
        (name[28] < '9') ? name[28]++ : (name[28] = '0', name[27]++);
    }
    free(name);
}

void first_display(main_t *struct_main, init_pop_t *pop)
{
    static int bol = 0;

    for (int i = 0; (pop->Tfirst_display[i] != NULL) && bol == 0;) {
        (RWPE(WIN, &struct_main->event)) ? game_event(struct_main) : 0;
        (struct_main->event.type == sfEvtKeyPressed) ? bol = 1 : 0;
        pop->time_swap = sfClock_getElapsedTime(pop->clock);
        pop->sec = pop->time_swap.microseconds / 1000000.0;
        if (pop->sec > 0.05) {
            sfRenderWindow_clear(struct_main->window, sfBlack);
            SST(pop->Sfirst_display, (pop->Tfirst_display[i]), sfTrue);
            sfSprite_setPosition(pop->Sfirst_display, (sfVector2f){600, 200});
            sfClock_restart(pop->clock);
            i++;
            RWDS(struct_main->window, pop->Sfirst_display, NULL);
        }
        sfRenderWindow_display(struct_main->window);
    }
}

void first_destroy(UNUSED main_t *struct_main, init_pop_t *pop)
{
    sfClock_destroy(pop->clock);
    sfSprite_destroy(pop->Sfirst_display);
    for (int i = 0; pop->Tfirst_display[i] != NULL; i++)
        sfTexture_destroy(pop->Tfirst_display[i]);
}

void first_process(main_t *struct_main)
{
    init_pop_t pop;

    init_all_first(struct_main, &pop);
    first_display(struct_main, &pop);
    first_destroy(struct_main, &pop);
}