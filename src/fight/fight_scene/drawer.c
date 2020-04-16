/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** drawer
*/

#include "main.h"

void give_attack(character_t *pl, sfVector2f pos, \
fight_t *fighter, main_t *main_struct)
{
    att_list_t *tmp = pl->list;
    int att = 0;

    att = (round(pos.x) == 100 && round(pos.y) == 800) ? 1 : 0;
    att = (round(pos.x) == 1500 && round(pos.y) == 800 && att == 0) ? 2 : att;
    att = (round(pos.x) == 100 && round(pos.y) == 900 && att == 0) ? 3 : att;
    att = (round(pos.x) == 1500 && round(pos.y) == 900 && att == 0) ? 4 : att;

    printf("att = %d\n", att);
    for (int i = 1; i != att; i += 1, tmp = tmp->next);
    player_turn(pl, tmp->attack, &fighter->enemy->attack, pl->state);
    printf("done\n");
    enemy_turn(pl, &fighter->enemy->attack);
    printf("player life = %d\n", pl->commitment);
    printf("enemy life = %d\n", fighter->enemy->attack.life);
    main_struct->scene = 0;
}

void draw_attack(character_t *player, main_t *main_struct)
{
    att_list_t *tmp = player->list;
    for (int y = 800; y <= 900; y += 100) {
        for (int x = 100; x <= 1500; x += 1400) {
            draw_text(main_struct, tmp->attack.name, (sfVector2f){x, y});
            tmp = tmp->next;
        }
    }
}

void display_life(sprite_t *red_one, sprite_t *red_two, \
sprite_t *black_one, sprite_t *black_two) {
    set_position(&red_one->pos, 100, 350);
    set_position(&black_one->pos, 100, 350);
    set_position(&red_two->pos, 1500, 350);
    set_position(&black_two->pos, 1500, 350);
}

void change_lifebar(int life, int new_life, sprite_t *red)
{
    int offset = (new_life * 100) / life;

    //printf("%d\n", offset);
    edit_rect(red, offset, "ressources/red.png");
}