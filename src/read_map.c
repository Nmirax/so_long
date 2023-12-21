/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:49:42 by abakhaev          #+#    #+#             */
/*   Updated: 2023/12/21 16:14:04 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int has_ber_extention(const char *filename)
{
    const char *dot;

    dot = strrchr(filename, '.'); //change fonction
        if (!dot || dot == filename)
            return (0);
                return (strcmp(dot, ".ber") == 0);
}


void read_map_from_file(char *filename, t_GameMap *game_map)
{
    int     fd;
    char    buffer[MAX_COLS + 1];
    int     bytes_read;
    int     i;

    i = 0;
    if (!has_ber_extention(filename))
    {
        write(2, "Error: File is not a .ber file\n", 31);
            exit(EXIT_FAILURE);
    }
    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    while ((bytes_read = read(fd, buffer, MAX_COLS)) > 0)
    {
        if (i >= MAX_ROWS)
        {
            perror("Too many rows in the map");
            exit(EXIT_FAILURE);
        }
        buffer[bytes_read] = '\0';
        strncpy(game_map->map[i], buffer, MAX_COLS);
        printf("test\n");
        i++;
    
    }
    close(fd);

    if (i <= 0)
    {
        perror("Empty or invalid map");
        exit(EXIT_FAILURE);
    }

    game_map->rows = i;
    game_map->cols = MAX_COLS;
}