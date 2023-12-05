/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_position.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:53:23 by abakhaev          #+#    #+#             */
/*   Updated: 2023/12/05 13:04:58 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_valid_move(t_GameMap *game_map, int rows, int cols)
{
	{
	if (rows > 0 && game_map->map[rows - 1][cols] != '1')
		return (1);
	}
	{
		if(rows < game_map->rows - 1 && game_map->map[rows + 1][cols] != '1')
			return (1);
	}
	{
		if (cols > 0 && game_map->map[rows][cols - 1] != '1')
			return (1);
	}
	{
		if (cols < game_map->cols -1 && game_map->map[rows][cols + 1] != '1')
			return(1);
	}
	return (0);
	
}

int	is_valid_map(t_GameMap *game_map)
{
	int rows;
	int	cols;
		
	rows = 0;
	while (rows < game_map->rows)
		{
		cols = 0;
	while (cols < game_map->cols)
	{
		if (!is_valid_move(game_map, rows, cols));
			return (0);
	
	cols++;
	}
	rows++;
	}
	return (1);
}