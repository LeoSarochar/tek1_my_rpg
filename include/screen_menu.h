/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** object
*/

#ifndef MY_SCREEN_MAIN_MENU_H_
#define MY_SCREEN_MAIN_MENU_H_

#include "include_all.h"
#include "particule.h"

#define PATH_BUTTON "ressources/ui/other/button_men.png"

typedef struct item_s
{
    int id;
    int stat1;
    int stat2;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    int num;
    int state;
} item_t;

typedef struct inventori_s
{
    int **id_item;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    int disp;
} inven_t;

typedef struct opt_s
{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
} opt_t;

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
    opt_t opt;
    item_t **item;
    button_t **button;
    button_t **button_pause;
    sfTexture **bgt_menu;
    sfSprite *bgs_menu;
    sfClock *clock_menu;
    inven_t inv;
    sfTime time_menu;
    text_menu_t **text;
    text_menu_t **text_pause;
    int state_button;
    int pause_button;
    int sec_menu;
    int bol_menu;
    int bol_pause;
    int bol_c_o;
    text_menu_t **cred;
    sfText *disp_vol;
    int d_p;
} main_menu_t;

typedef struct menu_sound_s
{
    sfMusic *menu_music;
    sfMusic *cmb;
    sfSound *button_sound;
    sfSoundBuffer *buffer_button;
    int bol_menu_music;
    int vol;
} main_sound_t;

#endif