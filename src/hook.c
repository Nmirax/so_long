/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:16:32 by abakhaev          #+#    #+#             */
/*   Updated: 2023/12/18 14:01:53 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_hook (t_data *data)
{

		if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_ESCAPE))
				mlx_close_window(data->mlx_ptr);
	else if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_W))
		{
			data->map->cols++;
			data->player.direction = UP;
		}
	else if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_A))
		{
			data->map->rows--;
			data->player.direction = LEFT;
		}
	else if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_D))
		{
			data->map->rows++;
			data->player.direction = RIGHT;
		}
	else if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_S))
		{
			data->map->cols--;
			data->player.direction = DOWN;
		}
	else if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_E))
		{
		if (all_coins_collected(data))
		{
			exit_game(data);
		}
		mlx_close_window(data->mlx_ptr);
	}
	return (0);
}
