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
        main_struct->map[i] = malloc(sizeof(char**) * 3);;
    }
    main_struct->map[1] = get_collision("./ressources/maps/map_cols/sm1_cols.txt");
    main_struct->map[2] = get_collision("./ressources/maps/map_cols/corridor_cols.txt");
    main_struct->map[3] = get_collision("./ressources/maps/map_cols/ground_cols.txt");
}

int open_file(char *name)
{
    int fd = open(name, O_RDONLY);

    if (fd == -1)
        exit (84);
    else
        return (fd);
    return (0);
}

char *read_file(struct stat *f_info, char *name)
{
    char *buff = NULL;
    int fd = open_file(name);
    int len = 0;
    int size = 0;

    stat(name, f_info);
    len = f_info->st_size;
    buff = malloc(sizeof(char) * len + 1);
    size = read(fd, buff, len);
    if (size == -1 || size == 0)
        exit(84);
    return (buff);
}

char **word_array(char *str)
{
    int size = strlen(str) + 1;
    char **new_tab = malloc(sizeof(char * ) * size);
    int y = 0;
    int x = 0;

    for (size_t i = 0; str[i] != '\0'; y++) {
        new_tab[y] = malloc(sizeof(char) * size);
        x = 0;
        while (str[i] != '\t' && \
        str[i] != '\0' && str[i] != '\n') {
            new_tab[y][x] = str[i];
            ++i;
            ++x;
        }
        if (str[i] == '\t' || str[i] == '\n')
            i++;
        new_tab[y][x] = '\0';
    }
    new_tab[y] = NULL;
    return (new_tab);
}



char **get_collision(char *filename)
{
    struct stat info;

    char *str = read_file(&info, filename);
    char **map_col = word_array(str);

    return (map_col);
}
