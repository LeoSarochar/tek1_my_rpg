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
#include "particule.h"

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
    char **map[3];
    particle_t *part1;
    particle_t *part2;
} main_t;

void disp_option_pause(main_t *glob);
void exit_cmb(main_t *glob);
void enter_combat(main_t *glob);
void init_option(main_t *glob);
void disp_option(main_t *glob);
void disp_cred(main_t *glob);
void close_window(main_t *main_struct, UNUSED sfEvent event);
void render(main_t *main_struct);
void init(main_t *main_struct);
void first_process(main_t *struct_main);
void game_event(main_t *main_struct);
void init_cred(main_t *glob);
void init_screen_menu(main_t *);
void destoy_menu(main_t *all);
void exec_menu(main_t *main_struct);
void exec_pause(main_t *struct_main);
void cond_disp_part(main_t *struct_main);
void init_inventori(main_t *structm);
void render_inv(main_t *structm);
void wear_stuff(item_t *item, main_t *glob);
void get_mouse(main_t *glob);
void disp_pause(main_t *struct_main);
void disp_menu(main_t *struct_main);
void mouse_position_pause(main_t *glob, sfRenderWindow *window);
void modif_statement_pause(main_t *glob);
void screen_menu_order(main_t *glob);
void modif_statement(main_t *glob);
void button_effect_pause(main_t *glob);
void button_effect(main_t *glob);
void basic_button_pause(main_t *glob);
void basic_button(main_t *glob);
void play_music(main_t *struct_main);
void init_screen_menu(main_t *struct_main);
void create_sound(main_t *struct_main);
void init_button_pause(main_t *struct_main);
void init_button_menu(main_t *struct_main);
void mouse_position(main_t *glob, sfRenderWindow *window);
void find_button(main_t *glob, sfVector2i cursor);
void create_text(text_menu_t *actual, char *into, sfVector2f pos, int size);
void init_button(button_t *butt, char *path, sfVector2f posin);
sfIntRect move_rect_button(sfIntRect spritesheet, int offset, int max_value);
void find_item2(main_t *glob, sfVector2i cursor, int i);
void find_wear2(main_t *glob, sfVector2i cursor, int i);
int my_strlen(char const *str);
int assign_num(main_t *glob);
void handle_music_pause(main_t *global);
char *nbr_str(long nb);

#endif //MY_MAIN_H_