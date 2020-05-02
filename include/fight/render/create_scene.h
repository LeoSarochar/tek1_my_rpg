/*
** EPITECH PROJECT, 2020
** test_fight_rpg
** File description:
** create_scene
*/

#ifndef CREATE_SCENE_H_
#define CREATE_SCENE_H_
#include "fight/init_attribute.h"

void init_scene(main_t *main_struct, int visible, char *name);
void create_all_enemy(enemy_list_t **enemy, preset_list_t *pre, int xp);
#endif /* !CREATE_SCENE_H_ */
