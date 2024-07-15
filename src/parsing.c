/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:02:01 by abakhaev          #+#    #+#             */
/*   Updated: 2024/07/15 11:48:45 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_map(t_data *data)
{
	int	items;

	if (ft_check_sign(data) == false)
		ft_free_all(data, "Wrong caractere in map\n", 1);
	if (ft_check_size(data) == false)
		ft_free_all(data, "Map is not a rectangle\n", 1);
	if (ft_check_count(data) == false)
		ft_free_all(data,
			"Wrong number of Start, Exit or collectible\n", 1);
	if (ft_check_walls(data) == false)
		ft_free_all(data, "Map not surrounded by walls\n", 1);
	items = data->collectible_count + data->map_exit;
	if ((ft_flood_fill(data->map, data->player_pos_x,
				data->player_pos_y, &items)) == false)
		ft_free_all(data, "No valid path in map\n", 1);
	ft_free_map(data);
	ft_open_map(data);
	ft_save_collectible_pos(data);
	ft_save_wall_pos(data);
	ft_save_exit_pos(data);
	return (0);
}

int	ft_check_size(t_data *data)
{
	int		i;
	size_t	first_line_lenght;
	size_t	next_line_lenght;

	i = 0;
	first_line_lenght = ft_strlen(data->map[i]) - 1;
	while (data->map[i] != NULL)
	{
		if (ft_strchr(data->map[i], '\n'))
			next_line_lenght = ft_strlen(data->map[i]) - 1;
		else
			next_line_lenght = ft_strlen(data->map[i]);
		if (next_line_lenght != first_line_lenght)
			return (false);
		i++;
	}
	return (true);
}

int	ft_check_sign(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i] != NULL)
	{
		j = 0;
		while (data->map[i][j] != '\0')
		{
			if ((data->map[i][j] != '0')
			&& (data->map[i][j] != '1')
			&& (data->map[i][j] != 'C')
			&& (data->map[i][j] != 'P')
			&& (data->map[i][j] != 'E')
			&& (data->map[i][j] != '\r')
			&& (data->map[i][j] != '\n'))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

int	ft_check_count(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i] != NULL)
	{
		j = 0;
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] == 'E')
				data->map_exit++;
			if (data->map[i][j] == 'P')
				ft_save_player_pos(data, i, j);
			if (data->map[i][j] == 'C')
				data->collectible_count++;
			j++;
		}
		i++;
	}
	if ((data->map_exit == 1) && (data->start_pos == 1)
		&& (data->collectible_count > 0))
		return (true);
	else
		return (false);
}

int	ft_check_walls(t_data *data)
{
	int	line_lenght;
	int	i;

	i = 0;
	line_lenght = ft_strlen(data->map[0]) - 1;
	while (i < line_lenght)
	{
		if ((data->map[0][i] != '1')
			|| (data->map[data->count_line - 1][i] != '1'))
			return (false);
		i++;
	}
	i = 0;
	while (i < data->count_line)
	{
		if ((data->map[i][0] != '1')
			|| (data->map[i][line_lenght - 1] != '1'))
			return (false);
		i++;
	}	
	return (true);
}
