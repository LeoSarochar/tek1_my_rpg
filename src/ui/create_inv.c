/*
** EPITECH PROJECT, 2020
** init item and inv
** File description:
** rpg
*/

#include "screen_menu.h"
#include "main.h"
#include "csfml_binding.h"
#include "first_plan_screen.h"

void create_item(item_t *item, char *path, int id)
{
    item->id = id;
    item->pos = (sfVector2f){0, 0};
    item->sprite = sfSprite_create();
    item->stat1 = 0;
    item->num = -1;
    item->stat2 = 0;
    item->texture = CFF(path, NULL);
    sfSprite_setTexture(item->sprite, item->texture, sfTrue);
    item->state = 0;
}

void init_item(main_t *structm)
{
    structm->s_menu.item = malloc(sizeof(item_t *) * 6);
    for (int j = 0; j < 6; j += 1)
        structm->s_menu.item[j] = malloc(sizeof(item_t));
    create_item(structm->s_menu.item[0], "ressources/ui/item/norme.png", 1);
    create_item(structm->s_menu.item[1], "ressources/ui/item/air.png", 0);
    create_item(structm->s_menu.item[2], "ressources/ui/item/pull.png", 2);
    create_item(structm->s_menu.item[3], "ressources/ui/item/ttb.png", 3);
    create_item(structm->s_menu.item[4], "ressources/ui/item/esc.png", 4);
    create_item(structm->s_menu.item[5], "ressources/ui/item/trot.png", 5);


}

void init_inventori(main_t *structm)
{
    init_item(structm);
    structm->s_menu.inv.id_item = malloc(sizeof(int *) * 3);
    for (int i = 0; i < 3; i++)
        structm->s_menu.inv.id_item[i] = malloc(sizeof(int) * 2);
    structm->s_menu.inv.pos = (sfVector2f){700, 400};
    structm->s_menu.inv.sprite = sfSprite_create();
    structm->s_menu.inv.disp = 0;
    structm->s_menu.inv.texture = CFF("ressources/ui/item/inv.png", NULL);
    SST(structm->s_menu.inv.sprite, structm->s_menu.inv.texture, sfTrue);
    sfSprite_setPosition(structm->s_menu.inv.sprite, structm->s_menu.inv.pos);
}