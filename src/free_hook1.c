/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_hook1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:01:33 by abakhaev          #+#    #+#             */
/*   Updated: 2024/02/25 15:20:25 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	my_close_hook(void *param)
{
	t_data	*data;

	data = param;
	free_all(data, "Game closed", 0);
}

void	main_finish(t_data *data)
{
	check_map(data);
	draw_map(data);
	game_loop(data);
	mlx_close_hook(data->mlx_ptr, &my_close_hook, &data);
	free_map_memory(data->map);
	mlx_terminate(data->mlx_ptr);
	free_data(&data);
	free(data);
}

void	mlx_inisializer(t_data *data)
{
	data->mlx_ptr = mlx_init(WIDTH, HEIGHT, "So Long", false);
	if (data->mlx_ptr == NULL)
	{
		allocate_map_memory(data->map);
		free_data(&data);
		free(data);
	}
}
