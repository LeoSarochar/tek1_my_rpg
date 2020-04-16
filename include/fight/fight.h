/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** fight
*/

#ifndef FIGHT_H_
#define FIGHT_H_
#include "init_attribute.h"
#include "main.h"

typedef struct list_s {
    character_t *charachter;
    struct list_s *next;
}list_t;

typedef struct fight_s {
    list_t *players;
    att_list_t *enemy;
    int nb_player;
    int nb_enemy;
    int nb_deadpl;
    int nb_deadenem;
}fight_t;

void fight(main_t *main);
void init_sprite(att_list_t *enemy, main_t *main_struct, char *path);
void display_player(character_t *player, main_t *main_struct, char *path);
int to_inflict(int attack, int intel, int speed);
void to_reduce(int *damage, int defence, int speed);
void is_good(state_t *state);
void draw_attack(character_t *player, main_t *main_struct);
void draw_menu(main_t *main_struct);
void display_scene(main_t *main, fight_t *fight);
void player_turn(character_t *pla, attack_t pl, attack_t *enem, state_t state);
void enemy_turn(character_t *player, attack_t *enemy);
void give_attack(character_t *pl, sfVector2f pos, \
fight_t *fighter, main_t *main_struct);
void display_life(sprite_t *red_one, sprite_t *red_two, \
sprite_t *black_one, sprite_t *black_two);
void change_lifebar(int life, int new_life, sprite_t *red);
#endif /* !FIGHT_H_ */
