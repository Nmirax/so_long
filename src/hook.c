/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:16:32 by abakhaev          #+#    #+#             */
/*   Updated: 2023/12/12 15:09:45 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int key_hook(int keycode, t_data *data)
{
	if (keycode == 53) // Touche ESC
		mlx_close_window(data->mlx_ptr);
	else if (keycode == 13)
		data->map->cols++;
	else if (keycode == 0)
		data->map->rows--;
	else if (keycode == 2)
		data->map->rows++;
	else if (keycode == 1)
		data->map->cols--;
	else if (keycode == 14)
	{
		if (all_coins_collected(data))
		{
			exit_game(data);
		}
		mlx_close_window(data->mlx_ptr);
	}
	return (0);
}
