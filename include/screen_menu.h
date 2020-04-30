/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** object
*/

#ifndef MY_SCREEN_MAIN_MENU_H_
#define MY_SCREEN_MAIN_MENU_H_

#include "include_all.h"

#define VEC(A,B) (sfVector2f){A,B}
#define PATH_BUTTON "ressources/ui/other/button_men.png"

typedef struct button_s
{
    sfTime time_butt;
    int status;
    float sec;
    int on;
    sfClock *clock;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f relative_pos;
    sfIntRect rect;
} button_t;

typedef struct text_s
{
    int compt1;
    sfText *txt1;
    sfVector2f score_pos1;
} text_menu_t;

typedef struct main_menu_s
{
    button_t **button;
    button_t **button_pause;
    sfTexture **bgt_menu;
    sfSprite *bgs_menu;
    sfClock *clock_menu;
    sfTime time_menu;
    text_menu_t **text;
    text_menu_t **text_pause;
    int state_button;
    int pause_button;
    int sec_menu;
    int bol_menu;
    int bol_pause;
} main_menu_t;



typedef struct menu_sound_s
{
    sfMusic *menu_music;
    sfSound *button_sound;
    sfSoundBuffer *buffer_button;
    int bol_menu_music; 
} main_sound_t;

#endif 