/*
** EPITECH PROJECT, 2020
** free and destroy
** File description:
** rpg
*/

#include "screen_menu.h"
#include "main.h"
#include "csfml_binding.h"
#include "first_plan_screen.h"

void destoy_menu(main_t *all)
{
    sfSound_destroy(all->sound.button_sound);
    sfMusic_destroy(all->sound.menu_music);
    sfMusic_destroy(all->sound.cmb);
    sfSoundBuffer_destroy(all->sound.buffer_button);
}