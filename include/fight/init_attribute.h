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
#include "render/drawer_function.h"
#include "render/create_scene.h"
#include "render/enemy_preset.h"
#include "render/render_fight.h"
#include "attack/player_turn.h"
#include "attack/enemy_turn.h"
#include "render/draw_menu.h"
#include "render/drawer_bg.h"



//
//\brief function to initialize state of charachter
//\param take the state of character
void init_state(state_t *state);
//

void init_player(main_t *main_struct);
void analyse_attack(main_t *main_struct, fight_scene_t *scene);
void is_dead(enemy_list_t *enemy, fight_scene_t *scene);
void init_scene_name(main_t *main_struct, char *, void (*)(main_t *));
void init_randomn(main_t *main_struct);
#endif /* !INIT_ATTRIBUTE_H_ */
