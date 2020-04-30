/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** call all lib
*/

#ifndef MY_MAIN_H_
#define MY_MAIN_H_

#include "include_all.h"
#include "screen_menu.h"
#include "player_and_map/player_and_map_struct.h"
#include "player_and_map/player_movement.h"

#define SFWC(A, B, C, D) sfRenderWindow_create(A, B, C, D)
#define RWPE(A, B) sfRenderWindow_pollEvent(A, B)
#define UNUSED __attribute__((unused))

typedef struct main_s
{
    sfRenderWindow *window;
    sfEvent event;
    main_menu_t s_menu;
    main_sound_t sound;
    playmap_t pm;
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

#endif //MY_MAIN_H_