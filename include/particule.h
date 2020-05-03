/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** particule
*/

#ifndef PARTICLE_H_
#define PARTICLE_H_

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define M_PI 3.14159265358979323846

#define V2F sfVector2f
#define V2I sfVector2i

typedef struct particle_s
{
    sfSprite *sprite;
    sfTexture *texture;
    sfUint8 *pixels;
    sfColor color;
    int x;
    int y;
} particle_t;

particle_t *create_particle(sfVector2i size, sfColor color);

//DISPLAY
void put_pixel(particle_t *particle, int x, int y, sfColor color);
void disp_part(particle_t *particle, sfRenderWindow *window,
                      sfVector2i pos, int refresh);
void display_square(particle_t *, int);
void radial_gradiant(particle_t *, sfVector2i, int, sfColor);

#endif
