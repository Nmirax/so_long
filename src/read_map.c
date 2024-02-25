/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:49:42 by abakhaev          #+#    #+#             */
/*   Updated: 2024/02/25 13:29:10 by abakhaev         ###   ########.fr       */
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

void	read_map_from_file(char *filename, t_GameMap *game_map)
{
	int		fd;
	char	buffer[MAX_COLS + 1];
	int		bytes_read;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}
	bytes_read = read(fd, buffer, MAX_COLS - 1);
	i = 0;
	while ((bytes_read > 0))
	{
		buffer[bytes_read] = '\0';
		if (i >= game_map->rows)
			exit(EXIT_FAILURE);
		ft_strncpy(game_map->map[i], buffer, MAX_COLS);
		i++;
		bytes_read = read(fd, buffer, MAX_COLS - 1);
	}
	close(fd);
	if (i <= 0)
		exit(EXIT_FAILURE);
}
