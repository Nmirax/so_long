/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:14:09 by abakhaev          #+#    #+#             */
/*   Updated: 2024/02/22 14:46:19 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	allocate_map_memory(t_GameMap *game_map)
{
	int	i;

	if (game_map->rows <= 0 || game_map->rows > MAX_ROWS)
	{
		perror("Nombre de lignes invalide");
		exit(EXIT_FAILURE);
	}
	game_map->map = (char **)malloc(MAX_ROWS * sizeof(char *));
	if (game_map->map == NULL)
	{
		perror("Error allocating memory for rows");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < game_map->rows)
	{
		game_map->map[i] = (char *)malloc(MAX_COLS * sizeof(char));
		if (game_map->map[i] == NULL)
		{
			perror("Error allocating memory for colons");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	game_map->map[game_map->rows] = NULL;
}

void	free_map_memory(t_GameMap *game_map)
{
	int	i;

	i = 0;
	while (game_map->map[i] != NULL)
	{
		free(game_map->map[i]);
		i++;
	}
	free(game_map->map);
	game_map->map = NULL;
}

int	malloc_data(t_data **data)
{
	*data = malloc(sizeof(t_data));
	if (*data == NULL)
	{
		perror("Échec de l'allocation de mémoire pour data");
		return (-1);
	}
	(*data)->map = malloc(sizeof(t_GameMap));
	if ((*data)->map == NULL)
	{
		perror("Échec de l'allocation de mémoire pour game_map");
		free(*data);
		return (EXIT_FAILURE);
	}
	return (0);
}

void	free_data(t_data **data)
{
	if (*data != NULL)
	{
		free((*data)->map);
		free(*data);
		*data = NULL;
	}
}
