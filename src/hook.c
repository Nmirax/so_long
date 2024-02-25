/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:15:05 by abakhaev          #+#    #+#             */
/*   Updated: 2024/02/25 15:19:46 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	handle_movement_keys(t_data *data)
{
	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_W))
	{
		player_up(data);
		collect_object(data);
	}
	else if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_A))
	{
		player_left(data);
		collect_object(data);
	}
	else if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_D))
	{
		player_right(data);
		collect_object(data);
	}
	else if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_S))
	{
		player_down(data);
		collect_object(data);
	}
}

void	handle_special_keys(t_data *data)
{
	int	player_x;
	int	player_y;

	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_E))
	{
		if (all_coins_collected(data))
		{
			exit_game(data);
			free_texture(data);
			mlx_close_window(data->mlx_ptr);
		}
	}
	else if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_T))
	{
		player_x = data->player.x;
		player_y = data->player.y;
		break_wall(data, player_x - 1, player_y);
		break_wall(data, player_x + 1, player_y);
		break_wall(data, player_x, player_y - 1);
		break_wall(data, player_x, player_y + 1);
	}
}

void	key_hook(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_ESCAPE))
	{
		free_texture(data);
		mlx_close_window(data->mlx_ptr);
		mlx_terminate(data->mlx_ptr);
	}
	else
	{
		handle_movement_keys(data);
		handle_special_keys(data);
	}
}
