/*
** EPITECH PROJECT, 2020
** music
** File description:
** rpg
*/

#include "screen_menu.h"
#include "main.h"
#include "csfml_binding.h"
#include "first_plan_screen.h"

void create_sound(main_t *struct_main)
{
    struct_main->sound.button_sound = sfSound_create();
    struct_main->sound.menu_music = SMFF("ressources/ui/sound/menu.ogg");
    struct_main->sound.buffer_button = SBFF("ressources/ui/sound/button.ogg");
    SSB(struct_main->sound.button_sound, struct_main->sound.buffer_button);
    struct_main->sound.bol_menu_music = 0;
    struct_main->sound.cmb = SMFF("ressources/ui/sound/aven.ogg");
}

void play_music(main_t *struct_main)
{
    if (struct_main->sound.bol_menu_music == 0) {
        sfMusic_play(struct_main->sound.menu_music);
        sfMusic_setLoop(struct_main->sound.menu_music, sfTrue);
        sfMusic_setVolume(struct_main->sound.menu_music, 50);
        sfMusic_play(struct_main->sound.cmb);
        sfMusic_setLoop(struct_main->sound.cmb, sfTrue);
        sfMusic_setVolume(struct_main->sound.cmb, 0);
        struct_main->sound.bol_menu_music = 1;
    }
}

void enter_combat(main_t *glob)
{
    sfMusic_setVolume(glob->sound.menu_music, 0);
    sfMusic_setVolume(glob->sound.cmb, glob->sound.vol - 30);
}

void exit_cmb(main_t *glob)
{
    sfMusic_setVolume(glob->sound.menu_music, glob->sound.vol);
    sfMusic_setVolume(glob->sound.cmb, 0);
}

void handle_music_pause(main_t *global)
{
    sfVector2i cur = sfMouse_getPositionRenderWindow(global->window);

    global->s_menu.d_p = 0;
    if (global->event.type == sfEvtMouseButtonPressed) {
        if (cur.x > 566 && cur.x < 636 && cur.y > 264 && cur.y < 336) {
            global->sound.vol++;
            global->s_menu.d_p = 1;
            }
        if (cur.x > 241 && cur.x < 310 && cur.y > 260 && cur.y < 329) {
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