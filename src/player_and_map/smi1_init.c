/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** sm1_init.c
*/

#include "player_and_map/sm1_init.h"
#include "main.h"

void put_map_sm1(main_t *main_struct)
{
    if (main_struct->player->fight_scene)
        return;
    if (main_struct->pm.player.scene == 0) {
        sfRenderWindow_drawSprite(main_struct->window, 
        main_struct->pm.map.map_sp->sprite, NULL);
        put_player(main_struct);
    }
}

void put_map_sm1_3D(main_t *main_struct)
{
    if (main_struct->player->fight_scene)
        return;
    if (main_struct->pm.player.scene == 0) {
        sfRenderWindow_drawSprite(main_struct->window, 
        main_struct->pm.map_3D.map_sp->sprite, NULL);
    }
}

void put_player(main_t *main_struct)
{
    sfSprite_setPosition(main_struct->pm.player.player_sp->sprite, 
    main_struct->pm.player.pos);
    sfRenderWindow_drawSprite(main_struct->window, 
    main_struct->pm.player.player_sp->sprite, NULL);
}

sfIntRect *init_rect_player(sfTexture *texture)
{
    sfIntRect *rect = malloc(sizeof(sfIntRect));
    rect->top = 49;
    rect->left = 0;
    rect->height = 47;
    rect->width = 44;
    return (rect);
}

sprite_t *load_sprite_player(char const *file_name)
{
    sprite_t *item = malloc(sizeof(sprite_t));
    sfSprite *sprite = NULL;
    sfTexture *texture = sfTexture_createFromFile(file_name, NULL);

    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    item->sprite = sprite;
    item->rect = malloc(sizeof(sfIntRect));
    item->rect = init_rect_player(texture);
    item->visible = sfTrue;
    return (item);
}

void init_perso(main_t *main_struct)
{

    main_struct->pm.player.pos.x = 96;
    main_struct->pm.player.pos.y = 681;
    main_struct->pm.player.player_sp = 
    load_sprite_player("./ressources/maps/player.png");
    main_struct->pm.player.scene = 2;
    sfSprite_setTextureRect(main_struct->pm.player.player_sp->sprite, 
    *(main_struct->pm.player.player_sp->rect));
    main_struct->pm.player.clock = sfClock_create();
}

void init_map(main_t *main_struct)
{
    main_struct->pm.view = sfView_create();
    sfView_setSize(main_struct->pm.view, (sfVector2f){960, 540});
    main_struct->pm.map.map_sp = load_sprite("./ressources/maps/sm1.png");
    main_struct->pm.map_3D.map_sp = 
    load_sprite("./ressources/maps/sm1_3d.png");
}