/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:00:44 by abakhaev          #+#    #+#             */
/*   Updated: 2024/07/15 11:48:26 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error_message(char *message, int boolean)
{
	if (boolean == 1)
		ft_printf("Error\n");
	if (message != NULL)
		ft_printf("%s\n", message);
	return (0);
}

void	ft_free_all(t_data *data, char *message, int boolean)
{
	free(data->mapname);
	ft_free_map(data);
	ft_free_texture(data);
	ft_free_image(data);
	if (data->collectible)
		free(data->collectible);
	if (data->wall)
		free(data->wall);
	if (data->exit)
		free(data->exit);
	if (data->mlx_ptr)
		mlx_terminate(data->mlx_ptr);
	ft_error_message(message, boolean);
	exit(0);
}

void	ft_free_map(t_data *data)
{
	int	i;

	i = 0;
	if (data->map)
	{
		while (i <= data->count_line)
		{
			free(data->map[i]);
			i++;
		}
		free(data->map);
	}
}

void	ft_free_image(t_data *data)
{
	int	i;

	i = 0;
	while (data->image_bg && i < data->map_size)
	{
		mlx_delete_image(data->mlx_ptr, data->image_bg[i]);
		i++;
	}
	free(data->image_bg);
	i = 0;
	while (data->image_collectible && i < data->collectible_count)
	{
		mlx_delete_image(data->mlx_ptr, data->image_collectible[i]);
		i++;
	}
	free(data->image_collectible);
	if (data->image_exit)
		mlx_delete_image(data->mlx_ptr, data->image_exit[0]);
	free(data->image_exit);
	if (data->image_player)
		mlx_delete_image(data->mlx_ptr, data->image_player[0]);
	free(data->image_player);
	ft_free_wall(data);
}

void	ft_free_texture(t_data *data)
{
	if (data->texture_bg)
	{
		mlx_delete_texture(data->texture_bg[0]);
		free(data->texture_bg);
	}
	if (data->texture_collectible)
	{
		mlx_delete_texture(data->texture_collectible[0]);
		free(data->texture_collectible);
	}
	if (data->texture_exit)
	{
		mlx_delete_texture(data->texture_exit[0]);
		free(data->texture_exit);
	}
	if (data->texture_player)
	{
		mlx_delete_texture(data->texture_player[0]);
		free(data->texture_player);
	}
	if (data->texture_wall)
	{
		mlx_delete_texture(data->texture_wall[0]);
		free(data->texture_wall);
	}
}
