/*
** EPITECH PROJECT, 2020
** init fonction menu
** File description:
** rpg
*/

#include "screen_menu.h"
#include "main.h"
#include "csfml_binding.h"
#include "first_plan_screen.h"

void init_button_pause(main_t *glob)
{
    glob->s_menu.button_pause = malloc(sizeof(button_t *) * (4));
    for (int j = 0; j < 4; j += 1)
        glob->s_menu.button_pause[j] = malloc(sizeof(button_t));
    init_button(glob->s_menu.button_pause[0], PATH_BUTTON, VEC(795, 150));
    init_button(glob->s_menu.button_pause[1], PATH_BUTTON, VEC(795, 300));
    init_button(glob->s_menu.button_pause[2], PATH_BUTTON, VEC(795, 450));
    init_button(glob->s_menu.button_pause[3], PATH_BUTTON, VEC(795, 600));
    glob->s_menu.text_pause = malloc(sizeof(text_menu_t *) * (9));
    for (int j = 0; j < 8; j += 1)
        glob->s_menu.text_pause[j] = malloc(sizeof(text_menu_t));
    create_text(glob->s_menu.text_pause[0], "RETURN", VEC(875, 235), 30);
    create_text(glob->s_menu.text_pause[1], "MENU", VEC(875, 400), 40);
    create_text(glob->s_menu.text_pause[2], "OPTIONS", VEC(875, 550), 27);
    create_text(glob->s_menu.text_pause[3], "EXIT", VEC(880, 690), 40);
    create_text(glob->s_menu.text_pause[4], "Volume", VEC(795, 150), 30);
    create_text(glob->s_menu.text_pause[5], "Music", VEC(795, 250), 30);
    create_text(glob->s_menu.text_pause[6], "Press x", VEC(795, 700), 50);
}

void init_button_menu(main_t *glob)
{
    glob->s_menu.button = malloc(sizeof(button_t *) * (4));
    for (int j = 0; j < 4; j += 1)
        glob->s_menu.button[j] = malloc(sizeof(button_t));
    init_button(glob->s_menu.button[0], PATH_BUTTON, VEC(1500, 150));
    init_button(glob->s_menu.button[1], PATH_BUTTON, VEC(1500, 300));
    init_button(glob->s_menu.button[2], PATH_BUTTON, VEC(1500, 450));
    init_button(glob->s_menu.button[3], PATH_BUTTON, VEC(1500, 600));
    glob->s_menu.text = malloc(sizeof(text_menu_t *) * (9));
    for (int j = 0; j < 8; j += 1)
        glob->s_menu.text[j] = malloc(sizeof(text_menu_t));
    create_text(glob->s_menu.text[0], "PLAY", VEC(1580, 235), 40);
    create_text(glob->s_menu.text[1], "CREDITS", VEC(1580, 400), 27);
    create_text(glob->s_menu.text[2], "OPTIONS", VEC(1580, 550), 27);
    create_text(glob->s_menu.text[3], "EXIT", VEC(1585, 690), 40);
    create_text(glob->s_menu.text[4], "Volume", VEC(1500, 150), 30);
    create_text(glob->s_menu.text[5], "Music", VEC(1500, 250), 30);
    create_text(glob->s_menu.text[6], "Press x", VEC(1500, 700), 50);
}

void init_screen_menu(main_t *struct_main)
{
    STR name = my_strdup("ressources/ui/menu_b/menu_b01.jpg");

    struct_main->s_menu.bgt_menu = malloc(sizeof(sfTexture *) * 11);
    struct_main->s_menu.bgs_menu = sfSprite_create();
    struct_main->s_menu.clock_menu = sfClock_create();
    struct_main->s_menu.sec_menu = 9;
    for (int i = 0; i < 10; i++){
        struct_main->s_menu.bgt_menu[i] = CFF(name, NULL);
        (name[28] < '9') ? name[28]++ : (name[28] = '0', name[27]++);
    }
    init_button_menu(struct_main);
    init_button_pause(struct_main);
    struct_main->s_menu.bol_menu = 1;
    struct_main->s_menu.bol_pause = 0;
    init_inventori(struct_main);
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
    sfText_setFont(actual->txt1, FCFF("ressources/ui/other/Pixeled.ttf"));
    sfText_setString(actual->txt1, into);
    sfText_setColor(actual->txt1, sfBlack);
    sfText_setCharacterSize(actual->txt1, size);
    sfText_setPosition(actual->txt1, pos);
}
