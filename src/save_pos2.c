/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_pos2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:05:03 by abakhaev          #+#    #+#             */
/*   Updated: 2024/07/15 11:48:56 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_save_exit_pos(t_data *data)
{
	int	j;

	data->index = 0;
	data->exit = ft_calloc(1, sizeof(t_exit));
	if (data->exit == NULL)
		ft_free_all(data, "Malloc error", 1);
	while (data->map[data->index] != NULL)
	{
		j = 0;
		while (data->map[data->index][j] != '\0')
		{
			if (data->map[data->index][j] == 'E')
			{
				data->exit[0].x = j;
				data->exit[0].y = data->index;
			}
			j++;
		}
		data->index++;
	}
}

int	ft_wall_image(t_data *data)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (i < data->wall_count)
	{
		k = 0;
		while (data->map[j][k] != '\0' && data->map[j][k] != '\n')
		{
			if (data->map[j][k] == '1')
			{
				data->image_wall[i] = mlx_texture_to_image
					(data->mlx_ptr, data->texture_wall[0]);
				if (!data->image_wall)
					ft_free_all(data,
						"Error loading texture to image", 1);
				i++;
			}
			k++;
		}
		j++;
	}
	return (0);
}

int	ft_display_wall(t_data *smain)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (i < smain->wall_count)
	{
		k = 0;
		while (smain->map[j][k] != '\0' && smain->map[j][k] != '\n')
		{
			if (smain->map[j][k] == '1')
			{
				mlx_image_to_window(smain->mlx_ptr,
					smain->image_wall[i], k * 64, j * 64);
				i++;
			}
			k++;
		}
		j++;
	}
	return (0);
}

void	ft_free_wall(t_data *data)
{
	int	i;

	i = 0;
	while (data->image_wall && i < data->wall_count)
	{
		mlx_delete_image(data->mlx_ptr, data->image_wall[i]);
		i++;
	}
	free(data->image_wall);
}
