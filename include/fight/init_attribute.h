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

typedef enum {
    CPOOL,
    PSU_SEM1,
    CPE_SEM1,
    MUL_SEM1,
    PSU_SEM2,
    CPE_SEM2,
    MUL_SEM2
}TYPE;

typedef struct main_s main_t;

typedef struct state_s{
    int is_alive;
    int is_dem;
    int is_tired;
    int can_attack;
}state_t;


typedef struct attack_s {
    int req_intel;
    int req_logi;
    int dama_com;
    int life;
    int speed;
    int defen;
    char *name;
    sprite_t *sprite;
    state_t state;
}attack_t;

typedef struct att_list_s {
    attack_t attack;
    struct att_list_s *next;
}att_list_t;

typedef struct attpre_s {
    char *name;
    int max_deg;
    int min_xp;
    int fought_already;
}attpre_t;

typedef struct list_attpre_s {
    attpre_t attack;
    struct list_attpre_s *next;
}list_attpre_t;

typedef struct preset_s {
    att_list_t *comp;
    list_attpre_t *attack;
}preset_t;

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
    state_t state;
    att_list_t *list;
    preset_t preset;
    sprite_t *sprite;
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
//
//\brief function to initialize state of charachter
//\param take the state of character
void init_state(state_t *state);
//
#endif /* !INIT_ATTRIBUTE_H_ */
