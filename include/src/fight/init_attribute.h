/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_attribute
*/

#ifndef INIT_ATTRIBUTE_H_
#define INIT_ATTRIBUTE_H_
#include "include_all.h"
#include "main.h"

typedef struct main_s main_t;

typedef struct character_s {
    int intellect;
    int guard;
    int commitment;
    int xp;
    float gpa;
    int speed;
    int posiion;
    int width;
    int height;
}character_t;

typedef struct scene_s {
} scene_t;


///////////////////////////////////
//\brief function to initialize main character
//\param main structure
//\param initialize all the player attribute
void init_character(main_t *main);
/////////////////////////////////////
#endif /* !INIT_ATTRIBUTE_H_ */
