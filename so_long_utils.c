/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:47:51 by abakhaev          #+#    #+#             */
/*   Updated: 2023/12/04 14:36:06 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	read_map_line(int fd, char *buffer, t_GameMap *game_map)
{
	int	rows;
	int	cols;

	rows = game_map->rows;
	cols = 0;
	while (read(fd, buffer, 1) > 0)
	{
		if (*buffer == '\n')
		{
			rows++;
			cols = 0;
			return ;
		}
		else if (rows >= MAX_COLS || cols >= MAX_COLS)
		{
			ft_printf("Error: Too many rows or columns in the map.\n");
			exit(EXIT_FAILURE);
		}
		else
		{
			game_map->map[rows][(cols)++] = *buffer;
		}
	}
}

void	free_map_memory(t_GameMap *game_map)
{
	int	i;

	i = 0;
	while (i < MAX_COLS)
	{
		free(game_map->map[i]);
		i++;
	}
	free(game_map->map);
}

void	free_map(t_GameMap *game_map)
{
	int	i;

	i = 0;
	while (i < game_map->rows)
	{
		free(game_map->map[i]);
		i++;
	}
	free(game_map->map);
}
