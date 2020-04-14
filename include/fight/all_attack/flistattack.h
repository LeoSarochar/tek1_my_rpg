/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** flistattack
*/

#ifndef FLISTATTACK_H_
#define FLISTATTACK_H_
#include "main.h"

//
//\brief initialize an attack depending on parameter
//\param take an 3-element array
//\param the first element correspond to the req_intel of the struct attack_t
//\param the second element correspond to the req_logi of the struct attack_t
//\param the third element correspond to the dama_com of the struct attack_t
//\param the fourth element correspond to the life variable of struct attack_t
//\param take also a char * which will be the name of the attack
//\return an attack(enemy or just competencies)
attack_t crte_att(int attrib[4], char *name, int is_enemy);
//

//brief create a preset attack
//\param the parameter are all the attribute listed in struct attpre_t
//return a preset attack
attpre_t create_preset(char *name, int max_deg, int min_xp, int fo_alr);
//
#endif /* !FLISTATTACK_H_ */
