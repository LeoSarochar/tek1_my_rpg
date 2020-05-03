/*
** EPITECH PROJECT, 2020
** disp option screen
** File description:
** rpg
*/

#include "screen_menu.h"
#include "main.h"
#include "csfml_binding.h"
#include "first_plan_screen.h"

char *nbr_str(long nb)
{
    char *str = malloc(16);
    long i = -1;

    for (int i = 0; i < 13; i++)
        str[i] = (i == 0) ? '0' : '\0';
    for (long compt = nb; compt >= 1; i++)
        compt = compt / 10;
    for (; nb >= 1; i--) {
        str[i] = nb % 10 + 48;
        nb = nb / 10;
    }
    return (str);
}

void init_option(main_t *glob)
{
    char *str = "ressources/ui/other/Pixeled.ttf";

    glob->sound.vol = 50;
    glob->s_menu.disp_vol = sfText_create();
    sfText_setFont(glob->s_menu.disp_vol, FCFF(str));
    sfText_setString(glob->s_menu.disp_vol, "50");
    sfText_setColor(glob->s_menu.disp_vol, sfBlack);
    sfText_setCharacterSize(glob->s_menu.disp_vol, 50);
    sfText_setPosition(glob->s_menu.disp_vol, (sfVector2f){600, 270});
    glob->s_menu.opt.sprite = sfSprite_create();
    glob->s_menu.opt.texture = CFF("ressources/ui/other/how.png", NULL);
    SST(glob->s_menu.opt.sprite, glob->s_menu.opt.texture, sfTrue);
    SP(glob->s_menu.opt.sprite, VEC(350, 50));
}

void handle_music(main_t *global)
{
    sfVector2i cur = sfMouse_getPositionRenderWindow(global->window);

    global->s_menu.d_p = 0;
    if (global->event.type == sfEvtMouseButtonPressed) {
        if (cur.x > 766 && cur.x < 836 && cur.y > 264 && cur.y < 336) {
            global->sound.vol++;
            global->s_menu.d_p = 1;
        }
        if (cur.x > 441 && cur.x < 510 && cur.y > 260 && cur.y < 329) {
            global->sound.vol--;
            global->s_menu.d_p = 1;
        }
        if (global->sound.vol > 100)
            global->sound.vol = 100;
        if (global->sound.vol < 0)
            global->sound.vol = 0;
        sfText_setString(global->s_menu.disp_vol, nbr_str(global->sound.vol));
        sfMusic_setVolume(global->sound.menu_music, global->sound.vol);
    }
}

void disp_option(main_t *glob)
{
    sfText_setPosition(glob->s_menu.disp_vol, (sfVector2f){600, 270});
    SP(glob->s_menu.opt.sprite, VEC(350, 50));
    handle_music(glob);
    RWDS(glob->window, glob->s_menu.opt.sprite, NULL);
    RWT(glob->window, glob->s_menu.disp_vol, NULL);
}

void disp_option_pause(main_t *glob)
{
    if (glob->s_menu.bol_c_o == 2) {
        sfText_setPosition(glob->s_menu.disp_vol, (sfVector2f){400, 270});
        SP(glob->s_menu.opt.sprite, VEC(150, 50));
        handle_music_pause(glob);
        RWDS(glob->window, glob->s_menu.opt.sprite, NULL);
        RWT(glob->window, glob->s_menu.disp_vol, NULL);
    }
}