/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** story
*/

#ifndef MY_STORY_H_
#define MY_STORY_H_

#include "include_all.h"
#include "sprite.h"
#include "main.h"
#include "lib/my.h"
#include "story/pnj/create.h"

#define CUR_PNJ story->pnjs[story->nb_pnjs - 1]

typedef struct main_s main_t;
typedef struct story story_t;

typedef struct pnj
{
    char *name;
    sprite_t *sprite;
    sfVector2i pos;
    void (*onclick)(story_t *story);
} pnj_t;

typedef struct story
{
    pnj_t *current_pnj;
    pnj_t *pnjs;
    int nb_pnjs;
} story_t;

void init_story(main_t *main_struct);
void render_pnjs(main_t *main);
void close_pnj_window(main_t *main, sfEvent event);

#endif //MY_STORY_H_