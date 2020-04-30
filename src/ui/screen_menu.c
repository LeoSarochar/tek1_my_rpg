/*
** EPITECH PROJECT, 2020
** main screen menu
** File description:
** call fonction for go on the menu
*/

#include "screen_menu.h"
#include "main.h"
#include "csfml_binding.h"
#include "first_plan_screen.h"

sfIntRect move_rect_button(sfIntRect spritesheet, int offset, int max_value)
{
    if (spritesheet.left == max_value - offset)
        return (spritesheet);
    else
        spritesheet.left += offset;
    return (spritesheet);
}

void init_button(button_t *butt, char *path, sfVector2f posin)
{
    butt->clock = sfClock_create();
    butt->status = 0;
    butt->texture = CFF(path, NULL);
    butt->sprite = sfSprite_create();
    butt->pos = posin;
    butt->sec = 0;
    butt->rect = (sfIntRect){0, 0, 330, 220};
    sfSprite_setTexture(butt->sprite, butt->texture, sfTrue);
    sfSprite_setTextureRect(butt->sprite, butt->rect);
    sfSprite_setPosition(butt->sprite, butt->pos);
}

void create_text(text_menu_t *actual, char *into, sfVector2f pos, int size)
{
    actual->txt1 = sfText_create();
    sfText_setFont(actual->txt1, sfFont_createFromFile("ressources/ui/other/Pixeled.ttf"));
    sfText_setString(actual->txt1, into);
    sfText_setColor(actual->txt1, sfBlack);
    sfText_setCharacterSize(actual->txt1, size);
    sfText_setPosition(actual->txt1, pos);
}

void find_button(main_t *glob, sfVector2i cursor)
{
    if (cursor.y > 190 && cursor.y < 330)
        glob->s_menu.state_button = 1;
    if (cursor.y > 340 && cursor.y < 480)
        glob->s_menu.state_button = 2;
    if (cursor.y > 490 && cursor.y < 630)
        glob->s_menu.state_button = 3;
    if (cursor.y > 640 && cursor.y < 780)
        glob->s_menu.state_button = 4;
}

void mouse_position(main_t *glob, sfRenderWindow *window)
{
    sfVector2i cursor = sfMouse_getPositionRenderWindow(window);
    if (cursor.x > 1520 && cursor.x < 1800)
    {
        if ((cursor.y > 190 && cursor.y < 330) ||
            (cursor.y > 340 && cursor.y < 480) ||
            (cursor.y > 490 && cursor.y < 630) ||
            (cursor.y > 640 && cursor.y < 780))
            find_button(glob, cursor);
        else
            glob->s_menu.state_button = 0;
    }
    else
        glob->s_menu.state_button = 0;
}

void init_button_menu(main_t *struct_main)
{
    struct_main->s_menu.button = malloc(sizeof(button_t *) * (4));
    for (int j = 0; j < 4; j += 1)
        struct_main->s_menu.button[j] = malloc(sizeof(button_t));
    init_button(struct_main->s_menu.button[0], PATH_BUTTON, VEC(1500, 150));
    init_button(struct_main->s_menu.button[1], PATH_BUTTON, VEC(1500, 300));
    init_button(struct_main->s_menu.button[2], PATH_BUTTON, VEC(1500, 450));
    init_button(struct_main->s_menu.button[3], PATH_BUTTON, VEC(1500, 600));
    struct_main->s_menu.text = malloc(sizeof(text_menu_t *) * (9));
    for (int j = 0; j < 8; j += 1)
        struct_main->s_menu.text[j] = malloc(sizeof(text_menu_t));
    create_text(struct_main->s_menu.text[0], "PLAY", VEC(875, 235), 40);
    create_text(struct_main->s_menu.text[1], "CREDIT", VEC(1580, 400), 30);
    create_text(struct_main->s_menu.text[2], "OPTION", VEC(1580, 550), 30);
    create_text(struct_main->s_menu.text[3], "EXIT", VEC(1585, 690), 40);
    create_text(struct_main->s_menu.text[4], "Volume", VEC(1500, 150), 30);
    create_text(struct_main->s_menu.text[5], "Music", VEC(1500, 250), 30);
    create_text(struct_main->s_menu.text[6], "Press x to close", VEC(1500, 700), 50);
}

void init_button_pause(main_t *struct_main)
{
    struct_main->s_menu.button_pause = malloc(sizeof(button_t *) * (4));
    for (int j = 0; j < 4; j += 1)
        struct_main->s_menu.button_pause[j] = malloc(sizeof(button_t));
    init_button(struct_main->s_menu.button_pause[0], PATH_BUTTON, VEC(795, 150));
    init_button(struct_main->s_menu.button_pause[1], PATH_BUTTON, VEC(795, 300));
    init_button(struct_main->s_menu.button_pause[2], PATH_BUTTON, VEC(795, 450));
    init_button(struct_main->s_menu.button_pause[3], PATH_BUTTON, VEC(795, 600));
    struct_main->s_menu.text_pause = malloc(sizeof(text_menu_t *) * (9));
    for (int j = 0; j < 8; j += 1)
        struct_main->s_menu.text_pause[j] = malloc(sizeof(text_menu_t));
    create_text(struct_main->s_menu.text_pause[0], "RETURN", VEC(875, 235), 30);
    create_text(struct_main->s_menu.text_pause[1], "MENU", VEC(875, 400), 40);
    create_text(struct_main->s_menu.text_pause[2], "OPTION", VEC(875, 550), 30);
    create_text(struct_main->s_menu.text_pause[3], "EXIT", VEC(880, 690), 40);
    create_text(struct_main->s_menu.text_pause[4], "Volume", VEC(795, 150), 30);
    create_text(struct_main->s_menu.text_pause[5], "Music", VEC(795, 250), 30);
    create_text(struct_main->s_menu.text_pause[6], "Press x to close", VEC(795, 700), 50);
}

void create_sound(main_t *struct_main)
{
    struct_main->sound.button_sound = sfSound_create();
    struct_main->sound.menu_music = sfMusic_createFromFile("ressources/ui/sound/menu.ogg");
    struct_main->sound.buffer_button = sfSoundBuffer_createFromFile("ressources/ui/sound/button.mp3");
    sfSound_setBuffer(struct_main->sound.button_sound, struct_main->sound.buffer_button);
    struct_main->sound.bol_menu_music = 0;
}

void init_screen_menu(main_t *struct_main)
{
    char *name = my_strdup("ressources/ui/menu_b/menu_b01.jpg");

    struct_main->s_menu.bgt_menu = malloc(sizeof(sfTexture *) * 11);
    struct_main->s_menu.bgt_menu[10] = NULL;
    struct_main->s_menu.bgs_menu = sfSprite_create();
    struct_main->s_menu.clock_menu = sfClock_create();
    struct_main->s_menu.sec_menu = 9;
    for (int i = 0; i < 10; i++){
        struct_main->s_menu.bgt_menu[i] = CFF(name, NULL);
        (name[28] < '9') ? name[28]++ : (name[28] = '0', name[27]++);
    }
    struct_main->sound.button_sound = sfSound_create();
    struct_main->sound.menu_music = sfMusic_createFromFile("ressources/ui/sound/menu.ogg");
    struct_main->sound.buffer_button = sfSoundBuffer_createFromFile("ressources/ui/sound/button.ogg");
    sfSound_setBuffer(struct_main->sound.button_sound, struct_main->sound.buffer_button);
    struct_main->sound.bol_menu_music = 0;
    init_button_menu(struct_main);
    init_button_pause(struct_main);
    struct_main->s_menu.bol_menu = 1;
    struct_main->s_menu.bol_pause = 0;
    free(name);
}

void play_music(main_t *struct_main)
{
    if (struct_main->sound.bol_menu_music == 0)
    {
        sfMusic_play(struct_main->sound.menu_music);
        sfMusic_setLoop(struct_main->sound.menu_music, sfTrue);
        sfMusic_setVolume(struct_main->sound.menu_music, 15);
        struct_main->sound.bol_menu_music = 1;
    }
}

void disp_menu(main_t *struct_main)
{
    static int i = 0;

    if (struct_main->s_menu.bgt_menu[i + 1] == NULL)
        i = 0;
    struct_main->s_menu.time_menu = sfClock_getElapsedTime(struct_main->s_menu.clock_menu);
    struct_main->s_menu.sec_menu = struct_main->s_menu.time_menu.microseconds / 100000.0;
    if (struct_main->s_menu.sec_menu > 1)
    {
        sfRenderWindow_clear(struct_main->window, sfBlack);
        SST(struct_main->s_menu.bgs_menu, (struct_main->s_menu.bgt_menu[i]), sfTrue);
        sfClock_restart(struct_main->s_menu.clock_menu);
        i++;
        sfRenderWindow_drawSprite(struct_main->window, struct_main->s_menu.bgs_menu, NULL);
        for (int i = 0; i < 4; i++)
        {
            sfRenderWindow_drawSprite(struct_main->window, struct_main->s_menu.button[i]->sprite, NULL);
            sfRenderWindow_drawText(struct_main->window, struct_main->s_menu.text[i]->txt1, NULL);
        }
        sfRenderWindow_display(struct_main->window);
    }
}

void disp_pause(main_t *struct_main)
{
    struct_main->s_menu.time_menu = sfClock_getElapsedTime(struct_main->s_menu.clock_menu);
    struct_main->s_menu.sec_menu = struct_main->s_menu.time_menu.microseconds / 100000.0;
    if (struct_main->s_menu.sec_menu > 1)
    {
            sfRenderWindow_clear(struct_main->window, sfBlack);
        for (int i = 0; i < 4; i++) {
            sfRenderWindow_drawSprite(struct_main->window, struct_main->s_menu.button_pause[i]->sprite, NULL);
            sfRenderWindow_drawText(struct_main->window, struct_main->s_menu.text_pause[i]->txt1, NULL);
        }
    }
}

void basic_button(main_t *glob)
{
    for (int i = 0; i < 4; i++){
        glob->s_menu.button[i]->rect = (sfIntRect){0, 0, 330, 220};
        sfSprite_setTextureRect(glob->s_menu.button[i]->sprite, glob->s_menu.button[i]->rect);
    }
}

void basic_button_pause(main_t *glob)
{
    for (int i = 0; i < 4; i++){
        glob->s_menu.button_pause[i]->rect = (sfIntRect){0, 0, 330, 220};
        sfSprite_setTextureRect(glob->s_menu.button_pause[i]->sprite, glob->s_menu.button_pause[i]->rect);
    }
}

void button_effect(main_t *glob)
{
    glob->s_menu.button[glob->s_menu.state_button - 1]->time_butt = sfClock_getElapsedTime(glob->s_menu.button[glob->s_menu.state_button - 1]->clock);
    glob->s_menu.button[glob->s_menu.state_button - 1]->sec = glob->s_menu.button[glob->s_menu.state_button - 1]->time_butt.microseconds / 10000000.0;
    if (glob->s_menu.button[glob->s_menu.state_button - 1]->sec > 0.015) {
        if (glob->s_menu.button[glob->s_menu.state_button - 1]->rect.left < 700) {
            glob->s_menu.button[glob->s_menu.state_button - 1]->rect = move_rect_button(glob->s_menu.button[glob->s_menu.state_button - 1]->rect, 330, 990);
            sfSprite_setTextureRect(glob->s_menu.button[glob->s_menu.state_button - 1]->sprite, glob->s_menu.button[glob->s_menu.state_button - 1]->rect);
        }
        sfClock_restart(glob->s_menu.button[glob->s_menu.state_button - 1]->clock);
    }
}

void button_effect_pause(main_t *glob)
{
    glob->s_menu.button_pause[glob->s_menu.state_button - 1]->time_butt = sfClock_getElapsedTime(glob->s_menu.button_pause[glob->s_menu.state_button - 1]->clock);
    glob->s_menu.button_pause[glob->s_menu.state_button - 1]->sec = glob->s_menu.button_pause[glob->s_menu.state_button - 1]->time_butt.microseconds / 10000000.0;
    if (glob->s_menu.button_pause[glob->s_menu.state_button - 1]->sec > 0.015) {
        if (glob->s_menu.button_pause[glob->s_menu.state_button - 1]->rect.left < 700) {
            glob->s_menu.button_pause[glob->s_menu.state_button - 1]->rect = move_rect_button(glob->s_menu.button_pause[glob->s_menu.state_button - 1]->rect, 330, 990);
            sfSprite_setTextureRect(glob->s_menu.button_pause[glob->s_menu.state_button - 1]->sprite, glob->s_menu.button_pause[glob->s_menu.state_button - 1]->rect);
        }
        sfClock_restart(glob->s_menu.button[glob->s_menu.state_button - 1]->clock);
    }
}

void modif_statement(main_t *glob)
{
    if(glob->s_menu.state_button == 1)
        glob->s_menu.bol_menu = 0;
    if(glob->s_menu.state_button == 4)
        close_window(glob, glob->event);
}

void screen_menu_order(main_t *glob)
{
    static int bol = 0;
    mouse_position(glob, glob->window);
    if (glob->s_menu.state_button != 0) {
        (bol == 0) ? sfSound_play(glob->sound.button_sound), bol++ : 0;
        button_effect(glob);
        if(glob->event.type == sfEvtMouseButtonPressed)
            modif_statement(glob);
    }
    else {
        bol = 0;
        basic_button(glob);
    }
}

void modif_statement_pause(main_t *glob)
{
    if(glob->s_menu.state_button == 1)
        glob->s_menu.bol_pause = 0;
    if(glob->s_menu.state_button == 2)
        glob->s_menu.bol_menu = 1;
    if(glob->s_menu.state_button == 4)
        close_window(glob, glob->event);
}

void mouse_position_pause(main_t *glob, sfRenderWindow *window)
{
    sfVector2i cursor = sfMouse_getPositionRenderWindow(window);
    if (cursor.x > 815 && cursor.x < 1095)
    {
        if ((cursor.y > 190 && cursor.y < 330) ||
            (cursor.y > 340 && cursor.y < 480) ||
            (cursor.y > 490 && cursor.y < 630) ||
            (cursor.y > 640 && cursor.y < 780))
            find_button(glob, cursor);
        else
            glob->s_menu.state_button = 0;
    }
    else
        glob->s_menu.state_button = 0;
}

void exec_pause(main_t *struct_main)
{
    static int bol = 0;
    mouse_position_pause(struct_main, struct_main->window);
    if (struct_main->s_menu.state_button != 0) {
        (bol == 0) ? sfSound_play(struct_main->sound.button_sound), bol++ : 0;
        button_effect_pause(struct_main);
        if(struct_main->event.type == sfEvtMouseButtonPressed)
            modif_statement(struct_main);
    }
    else {
        bol = 0;
        basic_button_pause(struct_main);
    }
    disp_pause(struct_main);

}

void exec_menu(main_t *struct_main)
{
    play_music(struct_main);
    screen_menu_order(struct_main);
    disp_menu(struct_main);
}