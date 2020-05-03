/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** save.c
*/

#include "save/save.h"

void add_to_save(char **save, char *field, char *to_add)
{
    if (*save)
        *save = my_strcat2(*save, ";", -1, 0);
    *save = my_strcat2(*save, field, -1, 0);
    *save = my_strcat2(*save, "=", -1, 0);
    *save = my_strcat2(*save, to_add, -1, 0);
}

void save_to_file(char *save)
{
    FILE *fp = fopen("save/data.txt", "w");

    fwrite(save, 1, sizeof(save), fp);
    fclose(fp);
}

void save_game(main_t *main)
{
    char *save = NULL;
    char *quest_id = NULL;

    quest_id = strdup((char[]){main->story->quests->quest_id + 48, '\0'});
    add_to_save(&save, "quest_id", quest_id);
    add_to_save(&save, "quest_text", main->story->quests->text);
    save_to_file(save);
}