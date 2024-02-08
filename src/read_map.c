/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:49:42 by abakhaev          #+#    #+#             */
/*   Updated: 2024/02/08 16:47:33 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		++i;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

int has_ber_extention(const char *filename)
{
    const char *dot;

    dot = strrchr(filename, '.'); //change fonction
        if (!dot || dot == filename)
            return (0);
                return (strcmp(dot, ".ber") == 0);//add fonction
}


void read_map_from_file(char *filename, t_GameMap *game_map)
{
    int fd;
    char buffer[MAX_COLS + 1];
    int bytes_read;
    int i;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    i = 0;
   while ((bytes_read = read(fd, buffer, MAX_COLS - 1)) > 0)
{
    buffer[bytes_read] = '\0';
    if (i >= game_map->rows)
    {
        write(2, "Error: Too many rows in the map\n", 33);
        exit(EXIT_FAILURE);
    }
    ft_strncpy(game_map->map[i], buffer, MAX_COLS);
    i++;
}
    close(fd);

    if (i <= 0)
    {
        perror("Error: Map file is empty");
        exit(EXIT_FAILURE);
    }
}
