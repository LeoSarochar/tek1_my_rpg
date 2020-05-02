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
#include "screen_menu.h"
#include "player_and_map/player_and_map_struct.h"
#include "player_and_map/player_movement.h"
#include "fight/init_attribute.h"

#define SFWC(A, B, C, D) sfRenderWindow_create(A, B, C, D)
#define RWPE(A, B) sfRenderWindow_pollEvent(A, B)
#define RWDS(A, B, C) sfRenderWindow_drawSprite(A, B, C)
#define UNUSED __attribute__((unused))

#define vec (sfVector2f)
typedef struct story story_t;
typedef struct player_s player_t;

typedef struct main_s {
    sfRenderWindow *window;
    sfEvent event;

    story_t *story;
    main_menu_t s_menu;
    main_sound_t sound;
    playmap_t pm;
    player_t *player;
} main_t;

void close_window(main_t *main_struct, UNUSED sfEvent event);
void render(main_t *main_struct);
void init(main_t *main_struct);
void first_process(main_t *struct_main);
void game_event(main_t *main_struct);
void init_screen_menu(main_t *);
void destoy_menu(main_t *all);
void exec_menu(main_t *main_struct);
void exec_pause(main_t *struct_main);
void init_inventori(main_t *structm);
void render_inv(main_t *structm);

#endif //MY_MAIN_H_