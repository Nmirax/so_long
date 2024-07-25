/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:00:58 by abakhaev          #+#    #+#             */
/*   Updated: 2024/07/25 12:59:39 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_texture_to_image(t_data *data)
{
	ft_bg_image(data);
	ft_wall_image(data);
	ft_collectible_image(data);
	ft_exit_image(data);
	ft_player_image(data);
	return (0);
}

int	ft_bg_image(t_data *smain)
{
	int	j;
	int	k;

	j = 0;
	while (smain->count < smain->map_size)
	{
		k = 0;
		while (smain->map[j][k] != '\0' && smain->map[j][k] != '\n')
		{
			smain->image_bg[smain->count] = mlx_texture_to_image
				(smain->mlx_ptr, smain->texture_bg[0]);
			if (!smain->image_bg[0])
				ft_free_all(smain, "Error loading texture to image", 1);
			smain->count++;
			k++;
		}
		j++;
	}
	return (0);
}

int	ft_collectible_image(t_data *data)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (i < data->collectible_count)
	{
		k = 0;
		while (data->map[j][k] != '\0' && data->map[j][k] != '\n')
		{
			if (data->map[j][k] == 'C')
			{
				data->image_collectible[i] = mlx_texture_to_image
					(data->mlx_ptr, data->texture_collectible[0]);
				if (!data->image_collectible[0])
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

int	ft_exit_image(t_data *data)
{
	data->image_exit[0] = mlx_texture_to_image
		(data->mlx_ptr, data->texture_exit[0]);
	if (!data->image_exit[0])
		ft_free_all(data, "Error loading texture to image", 1);
	return (0);
}

int	ft_player_image(t_data *data)
{
	data->image_player[0] = mlx_texture_to_image
		(data->mlx_ptr, data->texture_player[0]);
	if (!data->image_player[0])
		ft_free_all(data, "Error loading texture to image", 1);
	return (0);
}
