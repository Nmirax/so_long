/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:49:42 by abakhaev          #+#    #+#             */
/*   Updated: 2023/12/12 15:15:47 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void read_map_from_file(char *filename, t_GameMap *game_map)
{
    int     fd;
    char    buffer[MAX_COLS + 1];
    int     bytes_read;
    int     i;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    i = 0;
    while ((bytes_read = read(fd, buffer, MAX_COLS)) > 0)
    {
        if (i >= MAX_ROWS)
        {
            perror("Too many rows in the map");
            exit(EXIT_FAILURE);
        }

        // Null-terminate the buffer
        buffer[bytes_read] = '\0';

        // Copy the buffer to the map
        strncpy(game_map->map[i], buffer, MAX_COLS);
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