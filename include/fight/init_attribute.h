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
#include "sprite.h"

typedef struct main_s main_t;

typedef struct state_s{
    int is_alive;
    int is_dem;
    int is_tired;
}state_t;

typedef struct attack_s {
    int req_attack;
    int req_mana;
    int dama_com;
    int is_special;
    char *name;
    sprite_t *sprite;
}attack_t;

typedef struct character_s {
    int intellect;
    int attack;
    int mana;
    int guard;
    int commitment;
    int xp;
    float gpa;
    int speed;
    sfVector2f posiion;
    int width;
    int height;
    state_t state;
}character_t;

typedef struct scene_s {
    sprite_t *back_sprite;
    sfVector2f back_pos;
    int ena_anim;
}scene_t;


///////////////////////////////////
//\brief function to initialize main character
//\param main structure
//\param initialize all the player attribute
void init_character(main_t *main);
/////////////////////////////////////
#endif /* !INIT_ATTRIBUTE_H_ */
