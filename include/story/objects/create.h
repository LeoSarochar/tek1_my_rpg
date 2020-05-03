/*
** EPITECH PROJECT, 2019
** MyRPG
** File description:
** create.h
*/

#ifndef MY_CREATE_OBJECT_H_
#define MY_CREATE_OBJECT_H_

#define STRY_PTR void (*ptr)(main_t *)

#include "include_all.h"
#include "main.h"

typedef struct main_s main_t;
typedef struct story story_t;
typedef struct object object_t;

object_t *create_object(story_t *story, char **conf, int id, STRY_PTR);
object_t *get_object_by_name(story_t *story, char *name);
void render_objects(main_t *main);
int player_can_interact_object(main_t *main, object_t obj, int radius);

#endif //MY_CREATE_OBJECT_H_