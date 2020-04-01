/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** call all lib
*/

#ifndef MY_MAIN_H_
#define MY_MAIN_H_

#include "include_all.h"
#include "story/story.h"
#include "player_and_map/player_and_map_struct.h"

#define SFWC(A, B, C, D) sfRenderWindow_create(A, B, C, D)
#define RWPE(A, B) sfRenderWindow_pollEvent(A, B)
#define RWDS(A, B, C) sfRenderWindow_drawSprite(A, B, C)
#define UNUSED __attribute__((unused))

#define vec (sfVector2f)
typedef struct story story_t;

typedef struct main_s
{
    sfRenderWindow *window;
    sfEvent event;

    story_t *story;
    playmap_t pm;
} main_t;

void close_window(main_t *main_struct, UNUSED sfEvent event);
void render(main_t *main_struct);
void init(main_t *main_struct);

#endif //MY_MAIN_H_