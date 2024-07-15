/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:01:18 by abakhaev          #+#    #+#             */
/*   Updated: 2024/07/15 11:48:34 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_load_image(t_data *data)
{
	data->map_size = ft_map_size(data);
	data->image_bg = ft_calloc((data->map_size),
			sizeof(mlx_image_t));
	if (data->image_bg == NULL)
		ft_free_all(data, "Malloc error", 1);
	data->image_collectible = ft_calloc((data->collectible_count),
			sizeof(mlx_image_t));
	if (data->image_collectible == NULL)
		ft_free_all(data, "Malloc error", 1);
	data->image_player = ft_calloc(1, sizeof(mlx_image_t));
	if (data->image_player == NULL)
		ft_free_all(data, "Malloc error", 1);
	data->image_exit = ft_calloc(1, sizeof(mlx_image_t));
	if (data->image_exit == NULL)
		ft_free_all(data, "Malloc error", 1);
	data->image_wall = ft_calloc(data->wall_count,
			sizeof(mlx_image_t));
	if (data->image_exit == NULL)
		ft_free_all(data, "Malloc error", 1);
	ft_load_texture(data);
	return (0);
}

int	ft_map_size(t_data *data)
{
	int	map_x;
	int	map_size;

	map_x = ft_strlen(data->map[0]) - 1;
	map_size = map_x * data->count_line;
	return (map_size);
}

int	ft_load_texture(t_data *data)
{
	data->texture_bg = ft_calloc(1, sizeof(mlx_texture_t));
	if (data->texture_bg == NULL)
		ft_free_all(data, "Malloc error", 1);
	data->texture_collectible = ft_calloc(1, sizeof(mlx_texture_t));
	if (data->texture_collectible == NULL)
		ft_free_all(data, "Malloc error", 1);
	data->texture_exit = ft_calloc(1, sizeof(mlx_texture_t));
	if (data->texture_exit == NULL)
		ft_free_all(data, "Malloc error", 1);
	data->texture_player = ft_calloc(1, sizeof(mlx_texture_t));
	if (data->texture_player == NULL)
		ft_free_all(data, "Malloc error", 1);
	data->texture_wall = ft_calloc(1, sizeof(mlx_texture_t));
	if (data->texture_wall == NULL)
		ft_free_all(data, "Malloc error", 1);
	ft_load_png(data);
	return (0);
}

int	ft_load_png(t_data *data)
{
	data->texture_bg[0] = mlx_load_png("./img/bg.png");
	if (data->texture_bg[0] == NULL)
		ft_free_all(data, "Error loading background texture", 1);
	data->texture_collectible[0] = mlx_load_png("./img/collectible.png");
	if (data->texture_collectible[0] == NULL)
		ft_free_all(data, "Error loading collectible texture", 1);
	data->texture_exit[0] = mlx_load_png("./img/exit.png");
	if (data->texture_exit[0] == NULL)
		ft_free_all(data, "Error loading exit texture", 1);
	data->texture_player[0] = mlx_load_png("./img/player.png");
	if (data->texture_player[0] == NULL)
		ft_free_all(data, "Error loading player texture", 1);
	data->texture_wall[0] = mlx_load_png("./img/wall.png");
	if (data->texture_wall[0] == NULL)
		ft_free_all(data, "Error loading wall texture", 1);
	return (0);
}
