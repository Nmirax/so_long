/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_condition.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:03:48 by abakhaev          #+#    #+#             */
/*   Updated: 2024/02/26 14:26:07 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	collect_object(t_data *data)
{
	int	x;
	int	y;

	x = data->player.x;
	y = data->player.y;
	if (data->map->map[y][x] == 'C')
	{
		data->map->map[y][x] = '0';
		free_texture(data);
		draw_map(data);
		data->collected_coins++;
		ft_printf("Coin collected !\n");
	}
}

void	exit_game(t_data *data)
{
	t_GameMap	*game_map;

	game_map = data->map;
	if (game_map->map[data->player.y][data->player.x] == 'E')
	{
		if (all_coins_collected(data))
		{
			ft_printf("All coins have been collected !\n");
			mlx_close_window(data->mlx_ptr);
		}
		else
		{
			ft_printf("Collect all coins please.\n");
		}
	}
}

int	all_coins_collected(t_data *data)
{
	t_GameMap	*game_map;
	int			i;
	int			j;

	game_map = data->map;
	i = 0;
	while (i < game_map->rows)
	{
		j = 0;
		while (j < game_map->cols)
		{
			if (game_map->map[i][j] == 'C')
			{
				ft_printf("There are still coins to collect.\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	ft_printf("All coins have been collected !\n");
	return (1);
}
