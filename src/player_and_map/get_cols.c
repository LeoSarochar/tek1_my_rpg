/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** sm1_init.c
*/

#include "main.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "./player_and_map/player_movement.h"

void init_collisions(main_t *main_struct)
{
    for (int i = 0; i < 3; i += 1) {
        main_struct->map[i] = malloc(sizeof(char **) * 3);
    }
    main_struct->map[0] =
    get_collision("./ressources/maps/map_cols/sm1_cols.txt");
    main_struct->map[1] =
    get_collision("./ressources/maps/map_cols/corridor_cols.txt");
    main_struct->map[2] =
    get_collision("./ressources/maps/map_cols/ground_cols.txt");
    main_struct->pm.chess.map =
    get_collision("./ressources/maps/map_cols/chess.txt");
}

int open_file(char *name)
{
    int fd = open(name, O_RDONLY);

    return (fd);
}

char *read_file(struct stat *f_info, char *name)
{
    char *buff = NULL;
    int fd = open_file(name);
    int len = 0;

    stat(name, f_info);
    len = f_info->st_size;
    buff = malloc(sizeof(char) * (len + 1));
    buff[len] = '\0';
    read(fd, buff, len);
    return (buff);
}

char **get_collision(char *filename)
{
    struct stat info;
    char *str = read_file(&info, filename);
    char **map_col = my_str_to_word_array(str);

    return (map_col);
}
