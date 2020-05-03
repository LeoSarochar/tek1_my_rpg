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
#include "story/pnj/pnj_funcs.h"
#include "story/pnj/events.h"
#include "story/objects/events.h"
#include "story/objects/object_funcs.h"
#include "story/objects/create.h"
#include "story/quests.h"
#include "fight/init_attribute.h"

#define CUR_PNJ story->pnjs[story->nb_pnjs - 1]
#define CUR_OBJ story->objects[story->nb_objects - 1]
#define STRY_PTR void (*ptr)(main_t *)

typedef struct main_s main_t;
typedef struct story story_t;
typedef struct quests quests_t;

typedef struct pnj {
    char *name;
    char *path;
    int map_scene;
    sprite_t *sprite;
    sfVector2f pos;
    void (*onclick)(main_t *main);
} pnj_t;

typedef struct object {
    char *name;
    char *path;
    int map_scene;
    sprite_t *sprite;
    sfVector2f pos;
    void (*onclick)(main_t *main);
} object_t;

typedef struct story {
    sfView *fixed;
    pnj_t *current_pnj;
    pnj_t *pnjs;
    int nb_pnjs;
    object_t *current_object;
    object_t *objects;
    sfClock *objects_clock;
    int nb_objects;

    quests_t *quests;

    int show_window;
    char *w_text;
    sprite_t *w_background;
    sprite_t *w_avatar;
    void (*onclose)(main_t *main);
} story_t;

void init_story(main_t *main_struct);
void render_pnjs(main_t *main);
void handle_pnj_event(main_t *main, sfEvent event);
void nothing(main_t *main);

#endif //MY_STORY_H_