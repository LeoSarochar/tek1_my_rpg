/*
** EPITECH PROJECT, 2020
** test_fight_rpg
** File description:
** drawer_function
*/

#include "fight/render/drawer_function.h"

const char *filepath = "ressources/font/BebasNeue-Regular.ttf";

void draw_text(main_t *main, char *to_write, sfVector2f pos, int size)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile(filepath);

    sfText_setPosition(text, pos);
    sfText_setFont(text, font);
    sfText_setString(text, to_write);
    sfText_setCharacterSize(text, size);
    sfText_setColor(text, sfWhite);
    sfRenderWindow_drawText(main->window, text, NULL);
    sfFont_destroy(font);
    sfText_destroy(text);
}

void init_sprite(sprite_t **sprite, sfVector2f pos, const char *path)
{
    (*sprite) = load_sprite(path);
    (*sprite)->pos = pos;
    (*sprite)->offset = 0;
    (*sprite)->visible = 0;
}

void draw_sprite(main_t *main, sprite_t *sprite)
{
    sfSprite_setPosition(sprite->sprite, sprite->pos);
    sfRenderWindow_drawSprite(main->window, sprite->sprite, NULL);
}

void change_sprite(char *filepath, sprite_t **sprite)
{
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);

    sfSprite_destroy((*sprite)->sprite);
    (*sprite)->sprite = sfSprite_create();
    sfSprite_setTexture((*sprite)->sprite, texture, sfFalse);
}