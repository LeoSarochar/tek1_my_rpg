/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** csfml binding
*/

#ifndef MY_OWN_H_
#define MY_OWN_H_

#include "include_all.h"

#define CFF(A, B) sfTexture_createFromFile(A, B)
#define SST(A, B, C) sfSprite_setTexture(A, B, C)
#define SBFF(A) sfSoundBuffer_createFromFile(A)
#define SSB(A, B) sfSound_setBuffer(A, B)
#define SMFF(A) sfMusic_createFromFile(A)
#define CET(A) sfClock_getElapsedTime(A)
#define DIV_SEC (struct_main->s_menu.time_menu.microseconds / 100000.0)
#define RWDS(A, B, C) sfRenderWindow_drawSprite(A, B, C)
#define RWT(A, B, C) sfRenderWindow_drawText(A, B, C)
#define WIN (struct_main->window)
#define SP(A, B) sfSprite_setPosition(A, B)
#define VEC(A, B) (sfVector2f){A, B }
#define NUM(A) (structm->s_menu.item[A]->num)
#define MIS(A) structm->s_menu.item[A]->sprite
#define DIVSEC (struct_main->s_menu.time_menu.microseconds / 100000.0)
#define SM (struct_main->s_menu.bgs_menu)
#define SSTR(A, B) sfSprite_setTextureRect(A, B)
#define GBPS (glob->s_menu.button_pause[i]->sprite)
#define PAT1 (glob->s_menu.button[glob->s_menu.state_button - 1])
#define PAT2 (glob->s_menu.button_pause[glob->s_menu.state_button - 1])
#define CR(A) sfClock_restart(A);
#define PRESS sfEvtMouseButtonPressed
#define FCFF(A) sfFont_createFromFile(A)
#define MOUSE(A) sfMouse_getPositionRenderWindow(A)
#define CEDRICK "Aboh-Daniel-Cedrick Kakou"
#endif //MY_OWN_H_