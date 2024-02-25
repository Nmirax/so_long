/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:27:31 by abakhaev          #+#    #+#             */
/*   Updated: 2024/02/25 15:00:46 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_walls(t_data *data)
{
	int	line_length;
	int	i;

	i = 0;
	line_length = ft_strlen(data->map->map[0]) - 3;
	while (i < line_length)
	{
		if ((data->map->map[0][i] != '1') ||
		(data->map->map[MAX_ROWS - 1][i] != '1'))
			return (false);
		i++;
	}
	i = 0;
	while (i < MAX_ROWS)
	{
		if ((data->map->map[i][0] != '1') ||
		(data->map->map[i][MAX_COLS - 3] != '1'))
			return (false);
		i++;
	}
	return (true);
}

int	ft_check_format(t_data *data)
{
	size_t	i;

	i = ft_strlen(data->extention_map);
	if ((data->extention_map[i - 1] == 'r')
		&& (data->extention_map[i - 2] == 'e')
		&& (data->extention_map[i - 3] == 'b')
		&& (data->extention_map[i - 4] == '.'))
		return (true);
	else
		return (false);
}

void	break_wall(t_data *data, int x, int y)
{
	if (is_outer_wall(data, x, y))
	{
		return ;
	}
	if (data->map->map[y][x] == '1')
	{	
		free_texture(data);
		data->map->map[y][x] = '0';
		draw_map(data);
	}
}

int	is_outer_wall(t_data *data, int x, int y)
{
	int	map_rows;
	int	map_cols;

	map_rows = data->map->rows;
	map_cols = data->map->cols;
	if (x == 0 || x == map_cols - 3 || y == 0 || y == map_rows - 1)
	{
		return (true);
	}
	else
	{
		return (false);
	}
}
