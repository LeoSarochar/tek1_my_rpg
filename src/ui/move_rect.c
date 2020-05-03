/*
** EPITECH PROJECT, 2020
** rect move effect
** File description:
** rpg
*/

#include "screen_menu.h"
#include "main.h"
#include "csfml_binding.h"
#include "first_plan_screen.h"

sfIntRect move_rect_button(sfIntRect spritesheet, int offset, int max_value)
{
    if (spritesheet.left == max_value - offset)
        return (spritesheet);
    else
        spritesheet.left += offset;
    return (spritesheet);
}