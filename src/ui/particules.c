/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** particules
*/

#include "particule.h"
#include "screen_menu.h"
#include "main.h"
#include "csfml_binding.h"
#include "first_plan_screen.h"


void radial_gradiant(particle_t *particle, sfVector2i pos, int refresh, sfColor
color)
{
    sfVector2f og;
    float d;
    float a;

    if (refresh == 1) {
        if (rand() % 2 == 1)
            color.a = 0;
        if (color.a == 0) {
            put_pixel(particle, pos.x, pos.y, color);
            return;
        }
        og = (V2F){particle->x * 0.5, particle->y * 0.5};
        d = sqrt(pow((og.x - pos.x), 2) + pow((og.y - pos.y), 2));
        a = ((d / (particle->x / 2)) * 255 - 255) * -1;
        color.a = (a >= 0 && a <= 255) ? a : 0;
        put_pixel(particle, pos.x, pos.y, color);
    }
}

void display_square(particle_t *particle, int refresh)
{
    sfVector2i pos = {0, 0};

    while (pos.x != particle->x || pos.y != particle->y) {
        radial_gradiant(particle, pos, refresh, particle->color);
        pos.x += 1;
        if (pos.x > particle->x ) {
            pos.x = 0;
            pos.y += 1;
        }
    }
}

particle_t *create_particle(sfVector2i size, sfColor color)
{
    particle_t *particle = malloc(sizeof(particle_t));
    sfUint8 *pixels = malloc(sizeof(sfUint8) * size.x * size.y * 4);

    for (int i = 0; i < size.x * size.y * 4; i++)
        pixels[i] = 0;
    particle->texture = sfTexture_create(size.x, size.y);
    particle->sprite = sfSprite_create();
    particle->x = size.x;
    particle->y = size.y;
    particle->pixels = pixels;
    particle->color = color;
    sfSprite_setTexture(particle->sprite, particle->texture, sfTrue);
    sfSprite_setOrigin(particle->sprite, (V2F){size.x / 2, size.y / 2});
    return (particle);
}

void put_pixel(particle_t *particle, int x, int y, sfColor color)
{
    int position = (y * particle->x + x) * 4;

    if (position >= 0 && position + 3 <= particle->x * particle->y * 4 &&
    x <= particle->x && y <= particle->y) {
        particle->pixels[position + 0] = color.r;
        particle->pixels[position + 1] = color.g;
        particle->pixels[position + 2] = color.b;
        particle->pixels[position + 3] = color.a;
    }
}

void disp_part(particle_t *particle, sfRenderWindow *window, V2I pos,
int refresh)
{
    display_square(particle, refresh);
    sfTexture_updateFromPixels(particle->texture, particle->pixels,
    particle->x, particle->y, 0, 0);
    sfSprite_setPosition(particle->sprite, (V2F){pos.x, pos.y});
    sfRenderWindow_drawSprite(window, particle->sprite, NULL);
}