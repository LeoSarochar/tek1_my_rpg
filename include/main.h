/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** call all lib
*/

#ifndef MY_MAIN_H_
#define MY_MAIN_H_

#include "include_all.h"
#include "fight/init_attribute.h"
#include "fight/fight.h"
#include "fight/linked_list_library/char_list.h"
#include "fight/linked_list_library/att_list.h"
#include "fight/all_attack/flistattack.h"
#include "fight/linked_list_library/preset_list.h"
#include "fight/all_attack/preset.h"

#define SFWC(A, B, C, D) sfRenderWindow_create(A, B, C, D)
#define RWPE(A, B) sfRenderWindow_pollEvent(A, B)
#define UNUSED __attribute__((unused))

typedef struct character_s character_t;
typedef struct scene_s scene_t;

typedef struct main_s
{
    sfRenderWindow *window;
    sfEvent event;
    character_t *player;
} main_t;

void close_window(main_t *main_struct, UNUSED sfEvent event);
void render(main_t *main_struct);
void init(main_t *main_struct);

#endif //MY_MAIN_H_