/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:14:09 by abakhaev          #+#    #+#             */
/*   Updated: 2023/12/06 14:58:45 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	allocate_map_memory(t_GameMap *game_map) 
{
	int i;
    
    game_map->map = (char **)malloc(MAX_ROWS * sizeof(char *));
    if (game_map->map == NULL)
	{
        perror("Error allocating memory for rows");
        exit(EXIT_FAILURE);
    }

		i = 0;
    while (i < MAX_ROWS)
	{
        game_map->map[i] = (char *)malloc(MAX_COLS * sizeof(char));

        // Vérification de l'allocation
        if (game_map->map[i] == NULL)
		{
            perror("Error allocating memory for colons");
            exit(EXIT_FAILURE);
        }

        i++;
    }
}

void	free_map_memory(t_GameMap *game_map) 
{
    int i;

	i = 0;
    while (i < game_map->rows) 
	{
        free(game_map->map[i]);
        i++;
    }
    free(game_map->map);
}