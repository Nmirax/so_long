/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:36:29 by abakhaev          #+#    #+#             */
/*   Updated: 2024/02/26 11:38:29 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_extention_file(t_data *data)
{
	write(2, "Invalid map file format. Use a .ber file.\n", 43);
	free(data->map);
	free(data);
}

void	main_test(t_data *data)
{
	mlx_inisializer(data);
	data->map->rows = MAX_ROWS;
	data->map->cols = MAX_COLS;
	allocate_map_memory(data->map);
}

int	game_loop(t_data *data)
{
	// mlx_loop_hook(data->mlx_ptr, &key_hook, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = NULL;
	if (argc != 2)
	{
		write(2, "Usage: ./so_long map.ber\n", 26);
		free(data);
		return (EXIT_FAILURE);
	}
	if (malloc_data(&data) != 0)
	{
		free(data);
		return (-1);
	}
	data->extention_map = strrchr(argv[1], '.');
	if (data->extention_map == NULL || !ft_check_format(data))
	{
		free_extention_file(data);
	}
	main_test(data);
	read_map_from_file(argv[1], data->map);
	main_finish(data);
	return (EXIT_SUCCESS);
}
