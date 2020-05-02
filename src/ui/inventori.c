/*
** EPITECH PROJECT, 2020
** inventori
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
    item->num = 0;
    item->stat2 = 0;
    item->texture = CFF(path, NULL);
    sfSprite_setTexture(item->sprite, item->texture, sfTrue);
    item->state = 1;
}

void init_item(main_t *structm)
{
    structm->s_menu.item = malloc(sizeof(item_t *) * 6);
    for (int j = 0; j < 6; j += 1)
        structm->s_menu.item[j] = malloc(sizeof(item_t));
    create_item(structm->s_menu.item[0], "ressources/ui/item/norme.png", 0);
    create_item(structm->s_menu.item[1], "ressources/ui/item/norme.png", 1);
    create_item(structm->s_menu.item[2], "ressources/ui/item/norme.png", 2);
    create_item(structm->s_menu.item[3], "ressources/ui/item/norme.png", 3);
    create_item(structm->s_menu.item[4], "ressources/ui/item/norme.png", 4);
    create_item(structm->s_menu.item[5], "ressources/ui/item/norme.png", 5);
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
    sfSprite_setTexture(structm->s_menu.inv.sprite, structm->s_menu.inv.texture, sfTrue);
    sfSprite_setPosition(structm->s_menu.inv.sprite, structm->s_menu.inv.pos);
}

void find_item(main_t *glob, sfVector2i cursor)
{
    for (int i = 0; i < 6; i++)
    {
        if (cursor.x > 730 && cursor.x < 798 && cursor.y > 403 && cursor.y < 469 && glob->s_menu.item[i]->num == 0 && glob->s_menu.item[i]->state == 1)
        {
            glob->s_menu.item[i]->state = 2;
            glob->s_menu.item[i]->num = -1;
        }
        if (cursor.x > 803 && cursor.x < 872 && cursor.y > 406 && cursor.y < 467 && glob->s_menu.item[i]->num == 1 && glob->s_menu.item[i]->state == 1)
        {
            glob->s_menu.item[i]->state = 2;
            glob->s_menu.item[i]->num = -1;
        }
        if (cursor.x > 730 && cursor.x < 798 && cursor.y > 474 && cursor.y < 534 && glob->s_menu.item[i]->num == 2 && glob->s_menu.item[i]->state == 1)
        {
            glob->s_menu.item[i]->state = 2;
            glob->s_menu.item[i]->num = -1;
        }
        if (cursor.x > 803 && cursor.x < 872 && cursor.y > 475 && cursor.y < 538 && glob->s_menu.item[i]->num == 3 && glob->s_menu.item[i]->state == 1)
        {
            glob->s_menu.item[i]->state = 2;
            glob->s_menu.item[i]->num = -1;
        }
        if (cursor.x > 730 && cursor.x < 798 && cursor.y > 541 && cursor.y < 605 && glob->s_menu.item[i]->num == 5 && glob->s_menu.item[i]->state == 1)
        {
            glob->s_menu.item[i]->state = 2;
            glob->s_menu.item[i]->num = -1;
        }
        if (cursor.x > 803 && cursor.x < 870 && cursor.y > 541 && cursor.y < 605 && glob->s_menu.item[i]->num == 4 && glob->s_menu.item[i]->state == 1)
        {
            glob->s_menu.item[i]->state = 2;
            glob->s_menu.item[i]->num = -1;
        }
    }
}

int assign_num(main_t *glob)
{
    int ref = 0;
    int ref2 = 0;
    int n;
    for (n = 0; n < 6 || ref == n; n++) {
        ref = n;
        for(int i = 0; i < 6; i++)
            (glob->s_menu.item[i]->num == n) ? ref++ : 0;
            if(ref == ref2)
                break;
            else
                ref2++;
    }
    return (ref);
}

void find_wear(main_t *glob, sfVector2i cursor)
{
    for (int i = 0; i < 6; i++)
    {
        if (cursor.x > 982 && cursor.x < 1050 && cursor.y > 403 && cursor.y < 466 && glob->s_menu.item[i]->id == 0 && glob->s_menu.item[i]->state == 2)
        {
            glob->s_menu.item[i]->state = 1;
            glob->s_menu.item[i]->num = assign_num(glob);
        }
        if (cursor.x > 909 && cursor.x < 978 && cursor.y > 485 && cursor.y < 549 && glob->s_menu.item[i]->id == 1 && glob->s_menu.item[i]->state == 2)
        {
            glob->s_menu.item[i]->state = 1;
            glob->s_menu.item[i]->num = assign_num(glob);
        }
        if (cursor.x > 964 && cursor.x < 1050 && cursor.y > 484 && cursor.y < 551 && glob->s_menu.item[i]->id == 2 && glob->s_menu.item[i]->state == 2)
        {
            glob->s_menu.item[i]->state = 1;
            glob->s_menu.item[i]->num = assign_num(glob);
        }
        if (cursor.x > 1053 && cursor.x < 1121 && cursor.y > 489 && cursor.y < 548 && glob->s_menu.item[i]->id == 3 && glob->s_menu.item[i]->state == 2)
        {
            glob->s_menu.item[i]->state = 1;
            glob->s_menu.item[i]->num = assign_num(glob);
        }
        if (cursor.x > 983 && cursor.x < 1051 && cursor.y > 555 && cursor.y < 617 && glob->s_menu.item[i]->id == 4 && glob->s_menu.item[i]->state == 2)
        {
            glob->s_menu.item[i]->state = 1;
            glob->s_menu.item[i]->num = assign_num(glob);
        }
        if (cursor.x > 984 && cursor.x < 1052 && cursor.y > 626 && cursor.y < 687 && glob->s_menu.item[i]->id == 5 && glob->s_menu.item[i]->state == 2)
        {
            glob->s_menu.item[i]->state = 1;
            glob->s_menu.item[i]->num = assign_num(glob);
        }
    }
}

void get_mouse(main_t *glob)
{
    sfVector2i cursor = sfMouse_getPositionRenderWindow(glob->window);
    if (cursor.x > 730 && cursor.x < 873 && glob->event.type == sfEvtMouseButtonPressed)
    {
        if (cursor.y > 403 && cursor.y < 607)
            find_item(glob, cursor);
    }
    if (cursor.x > 905 && cursor.x < 1123 && glob->event.type == sfEvtMouseButtonPressed)
        if (cursor.y > 397 && cursor.y < 716)
            find_wear(glob, cursor);
}

void wear_stuff(item_t *item, main_t *glob)
{
    (item->state == 2 && item->id == 0) ? sfSprite_setPosition(item->sprite, (sfVector2f){979, 413}) : 0;
    (item->state == 2 && item->id == 1) ? sfSprite_setPosition(item->sprite, (sfVector2f){906, 497}) : 0;
    (item->state == 2 && item->id == 2) ? sfSprite_setPosition(item->sprite, (sfVector2f){981, 497}) : 0;
    (item->state == 2 && item->id == 3) ? sfSprite_setPosition(item->sprite, (sfVector2f){1044, 497}) : 0;
    (item->state == 2 && item->id == 4) ? sfSprite_setPosition(item->sprite, (sfVector2f){979, 575}) : 0;
    (item->state == 2 && item->id == 5) ? sfSprite_setPosition(item->sprite, (sfVector2f){979, 646}) : 0;
    sfRenderWindow_drawSprite(glob->window, item->sprite, NULL);
}

void render_inv(main_t *structm)
{
    sfView_setSize(structm->story->fixed, (sfVector2f){1920, 1080});
    sfView_setCenter(structm->story->fixed, (sfVector2f){960, 530});
    sfRenderWindow_setView(structm->window, structm->story->fixed);
    sfRenderWindow_drawSprite(structm->window, structm->s_menu.inv.sprite, NULL);
    get_mouse(structm);
    for (int i = 0; i < 6; i++)
    {
        if (structm->s_menu.item[i]->state == 1)
        {
            (structm->s_menu.item[i]->num == 0) ? sfSprite_setPosition(structm->s_menu.item[i]->sprite, (sfVector2f){722, 415}) : 0;
            (structm->s_menu.item[i]->num == 1) ? sfSprite_setPosition(structm->s_menu.item[i]->sprite, (sfVector2f){800, 415}) : 0;
            (structm->s_menu.item[i]->num == 2) ? sfSprite_setPosition(structm->s_menu.item[i]->sprite, (sfVector2f){722, 487}) : 0;
            (structm->s_menu.item[i]->num == 3) ? sfSprite_setPosition(structm->s_menu.item[i]->sprite, (sfVector2f){800, 487}) : 0;
            (structm->s_menu.item[i]->num == 4) ? sfSprite_setPosition(structm->s_menu.item[i]->sprite, (sfVector2f){800, 560}) : 0;
            (structm->s_menu.item[i]->num == 5) ? sfSprite_setPosition(structm->s_menu.item[i]->sprite, (sfVector2f){722, 560}) : 0;
            sfRenderWindow_drawSprite(structm->window, structm->s_menu.item[i]->sprite, NULL);
        }
        if (structm->s_menu.item[i]->state == 2)
            wear_stuff(structm->s_menu.item[i], structm);
    }
}