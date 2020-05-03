/*
** EPITECH PROJECT, 2020
** test_fight_rpg
** File description:
** init_attribute
*/

#ifndef INIT_ATTRIBUTE_H_
#define INIT_ATTRIBUTE_H_
#include "fight_struct.h"
#include "linked_list_library/attack_list.h"
#include "linked_list_library/player_list.h"
#include "linked_list_library/preset_list.h"
#include "linked_list_library/enemy_list.h"
#include "linked_list_library/destroyer.h"
#include "linked_list_library/getter.h"
#include "creator/attack_and_preset.h"
#include "creator/init_sprite_enem.h"
#include "render/render_character.h"
#include "render/analyse_position.h"
#include "animation/rect_function.h"
#include "render/drawer_function.h"
#include "render/create_scene.h"
#include "render/enemy_preset.h"
#include "render/render_fight.h"
#include "attack/player_turn.h"
#include "attack/enemy_turn.h"
#include "render/draw_menu.h"
#include "render/drawer_bg.h"
#include "animation/first.h"

void init_state(state_t *state);
void init_player(main_t *main_struct);
void analyse_attack(main_t *main_struct, fight_scene_t *scene);
void is_dead(enemy_list_t *enemy, fight_scene_t *scene);
void init_scene_name(main_t *main_struct, char *, void (*)(main_t *));
void init_randomn(main_t *main_struct);
int is_same(int i, int ind, int tab[4]);
void second_anim(main_t *main, Rect_t rect1, char *attack);
void wait_second(float to_wait);
void render_biensur(main_t *main_struct);
void change_position(sprite_t *sprite, int x, int y);
void change_lifebar(int life, int new_life, sprite_t *red);
void draw_player(main_t *main);
void ending_cond(main_t *main);
int check_github(attack_t *attack, char *name, main_t *main);
void write_enemy(char *attack, char *name, main_t *main);
void render_fight2(main_t *main, fight_scene_t *sc);
preset_t *give_where(char *name, main_t *main);
void set_attrib(main_t *main, int att, int def, int life);
void enemy_turn_attack(player_t *player, enemy_t *enemy, int todo);
void win_rimka(main_t *main);
#endif /* !INIT_ATTRIBUTE_H_ */
