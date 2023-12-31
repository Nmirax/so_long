/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:36:29 by abakhaev          #+#    #+#             */
/*   Updated: 2023/12/11 13:29:34 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


void	update(t_data *data)
{
	key_hook(data);
	handle_collectables_and_exits(data);
	exit_game(data);
}

int	game_loop(t_data *data)
{
	int	i;

	i = 0;
	while(i > 0)
	{
	mlx_loop_hook(data->mlx_ptr, &update, data);
		i++;
	}
	mlx_loop(data->mlx_ptr);

	mlx_terminate(data->mlx_ptr);
		return (0);
}