/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:14:09 by abakhaev          #+#    #+#             */
/*   Updated: 2024/01/08 11:49:59 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	allocate_map_memory(t_GameMap *game_map) 
{
	int i;
    
    i = 0;
    if (game_map->rows <= 0 || game_map->rows > MAX_ROWS) 
    {
        perror("Nombre de lignes invalide");
        exit(EXIT_FAILURE);
    }
    game_map->map = (char **)malloc(game_map->rows * sizeof(char *));
    if (game_map->map == NULL)
	{
        perror("Error allocating memory for rows");
        exit(EXIT_FAILURE);
    }
    while (i < game_map->rows)
	{
        game_map->map[i] = (char *)malloc(MAX_COLS * sizeof(char));
        if (game_map->map[i] == NULL)
        {
            perror("Error allocating memory for a map row");
            exit(EXIT_FAILURE);
        }
        printf("Allocated memory for row %d: %p\n", i, (void *)game_map->map[i]);
    }
}

void	*free_map_memory(t_GameMap *game_map) 
{
	int		i;

	i = 0;
	while (game_map->map[i] != NULL)
	{
		free(game_map->map[i]);
		i++;
	}
	free(game_map->map);
	game_map->map = NULL;
	return (0);
}