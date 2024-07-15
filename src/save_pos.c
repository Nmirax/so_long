/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:04:45 by abakhaev          #+#    #+#             */
/*   Updated: 2024/07/15 11:48:52 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_save_player_pos(t_data *data, int i, int j)
{
	data->start_pos++;
	data->player_pos_y = i;
	data->player_pos_x = j;
}

void	ft_save_collectible_pos(t_data *data)
{
	int	j;
	int	k;

	data->index = 0;
	k = 0;
	data->collectible = ft_calloc((data->collectible_count),
			sizeof(t_collectible));
	if (data->collectible == NULL)
		ft_free_all(data, "Malloc error", 1);
	while (data->map[data->index] != NULL)
	{
		j = 0;
		while (data->map[data->index][j] != '\0')
		{
			if (data->map[data->index][j] == 'C')
			{
				data->collectible[k].x = j;
				data->collectible[k].y = data->index;
				data->collectible[k].collected = false;
				k++;
			}
			j++;
		}
		data->index++;
	}
}

void	ft_count_wall(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i] != NULL)
	{
		j = 0;
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] == '1')
				data->wall_count++;
			j++;
		}
		i++;
	}
}

void	ft_save_wall_pos(t_data *data)
{
	int	j;
	int	k;

	ft_count_wall(data);
	data->index = 0;
	k = 0;
	data->wall = ft_calloc(data->wall_count, sizeof(t_wall));
	if (data->wall == NULL)
		ft_free_all(data, "Malloc error", 1);
	while (data->map[data->index] != NULL)
	{
		j = 0;
		while (data->map[data->index][j] != '\0')
		{
			if (data->map[data->index][j] == '1')
			{
				data->wall[k].x = j;
				data->wall[k].y = data->index;
				k++;
			}
			j++;
		}
		data->index++;
	}
}
