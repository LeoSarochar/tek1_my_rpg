/*
** EPITECH PROJECT, 2020
** test_fight_rpg
** File description:
** fight_struct
*/

#ifndef FIGHT_STRUCT_H_
#define FIGHT_STRUCT_H_
#include "main.h"
#include "sprite.h"

typedef struct main_s main_t;
typedef struct fight_scene_s fight_scene_t;

typedef struct attack_s {
    int dam_com;
    int req_intel;
    int req_ram;
    char *name;
} attack_t;

typedef struct preset_s {
    int xp;
    int dam_com;
    int fo_alr;
    int req_intel;
    int req_ram;
    char *name;
} preset_t;

typedef struct attack_list_s {
    attack_t *attack;
    struct attack_list_s *next;
} attack_list_t;

typedef struct Rect_s {
    int x;
    int y;
    int height;
    int width;
} Rect_t;

typedef struct state_s{
    int is_alive;
    int is_dem;
    int is_tired;
    int can_attack;
} state_t;

typedef struct preset_list_s {
    preset_t *preset;
    struct preset_list_s *next;
} preset_list_t;

typedef struct enemy_s {
    int com;
    int com_max;
    int force;
    int intel;
    int speed;
    int defence;
    char *lastattack;
    int ram;
    char *name;
    Rect_t rect;
    state_t state;
    sprite_t *sprite;
    attack_list_t *attacks;
} enemy_t;

typedef struct enemy_list_s {
    enemy_t *enemy;
    struct enemy_list_s *next;
} enemy_list_t;

typedef struct player_s {
    int com;
    int force;
    int intel;
    int com_max;
    float gpa;
    int speed;
    int defence;
    int ram;
    char *name;
    int xp;
    char *last_attack;
    sfClock *clock;
    Rect_t rect;
    state_t state;
    sprite_t *sprite;
    attack_list_t *attacks;
    preset_list_t *preset;
    fight_scene_t *fight_scene;
} player_t;

typedef struct player_list_s {
    player_t *player;
    struct player_list_s *next;
} player_list_t;

typedef struct fight_var_s {
    int menu;
    int scene;
    int nb;
    int tab[4];
    int to_print;
} fight_var_t;

typedef struct fight_scene_s {
    enemy_list_t *enemies;
    sprite_t *bg;
    sprite_t *cursor;
    sprite_t *red;
    sprite_t *red_pl;
    sprite_t *black;
    sprite_t *black_pl;
    sprite_t *menu;
    sprite_t *green;
    fight_var_t var;
    void (*ptr)(main_t *);
} fight_scene_t;

typedef struct enemy_preset_s {
    char *name;
    char *enemy;
    char *type;
    int life_max;
    int force_max;
    int defence_max;
    int speed_max;
    int intel_max;
    int ram_max;
} enemy_preset_t;

typedef struct enemy_path_s {
    char *path;
    char *incomp;
    char *enemy;
    char *almod;
} enemy_path_t;

#endif /* !FIGHT_STRUCT_H_ */
