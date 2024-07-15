/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:01:30 by abakhaev          #+#    #+#             */
/*   Updated: 2024/07/15 11:48:37 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
		return (ft_error_message("Wrong number of arguments", 1));
	ft_bzero(&data, sizeof(t_data));
	data.mapname = ft_strdup(argv[1]);
	if (!data.mapname)
	{
		ft_free_all(&data, "Malloc error", 1);
		ft_free_all(&data, "Wrong map", 1);
	}
	data.moove_count = 1;
	ft_open_map(&data);
	ft_check_map(&data);
	data.mlx_ptr = mlx_init((ft_strlen(data.map[0]) - 1) * 64,
			data.count_line * 64, "so_long", false);
	if (data.mlx_ptr == NULL)
		return (1);
	ft_load_image(&data);
	ft_texture_to_image(&data);
	ft_display_image(&data);
	mlx_key_hook(data.mlx_ptr, &my_keyhook, &data);
	mlx_close_hook(data.mlx_ptr, &my_close_hook, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
