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
    struct_main->sound.buffer_button = SBFF("ressources/ui/sound/button.mp3");
    SSB(struct_main->sound.button_sound, struct_main->sound.buffer_button);
    struct_main->sound.bol_menu_music = 0;
}

void play_music(main_t *struct_main)
{
    if (struct_main->sound.bol_menu_music == 0) {
        sfMusic_play(struct_main->sound.menu_music);
        sfMusic_setLoop(struct_main->sound.menu_music, sfTrue);
        sfMusic_setVolume(struct_main->sound.menu_music, 15);
        struct_main->sound.bol_menu_music = 1;
    }
}