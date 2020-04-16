/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** displayer
*/

#include "main.h"

static const char *filepath = "ressources/font/BebasNeue-Regular.ttf";

void draw_sprite(main_t *main, sprite_t *sprite)
{
    sfSprite_setPosition(sprite->sprite, sprite->pos);
    sfRenderWindow_drawSprite(main->window, sprite->sprite, NULL);
}

void draw_text(main_t *main, char *to_write, sfVector2f pos)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile(filepath);

    sfText_setPosition(text, pos);
    sfText_setFont(text, font);
    sfText_setString(text, to_write);
    sfText_setCharacterSize(text, 75);
    sfText_setColor(text, sfWhite);
    sfRenderWindow_drawText(main->window, text, NULL);
    sfFont_destroy(font);
    sfText_destroy(text);
}

void edit_rect(sprite_t *sprite, int offset, char *path)
{
    sfTexture *texture = sfTexture_createFromFile(path, NULL);

    sfSprite_destroy(sprite->sprite);
    sprite->offset = offset;
    sprite->rect->left = 0;
    sprite->rect->top = 0;
    sprite->rect->width = offset;
    sprite->sprite = sfSprite_create();
    sfSprite_setTexture(sprite->sprite, texture, sfFalse);
    sfSprite_setTextureRect(sprite->sprite, *(sprite->rect));
}

void set_position(sfVector2f *pos, int pos_x, int pos_y)
{
    pos->x = pos_x;
    pos->y = pos_y;
}

void move_rect(sprite_t *sprite)
{
    sprite->rect->left = (sprite->rect->left + sprite->offset) % sprite->max;
}