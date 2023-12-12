/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:36:29 by abakhaev          #+#    #+#             */
/*   Updated: 2023/12/12 14:57:48 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


void	update(t_data *data)
{
    is_valid_map(data);
    key_hook(13, data);
    key_hook(2, data);
    key_hook(0, data);
    key_hook(14, data);
    key_hook(1, data);
    handle_collectables_and_exits(data);
    exit_game(data);
}

int	game_loop(t_data *data)
{
	while(1)
	{
        draw_textures(data);
		mlx_loop(data->mlx_ptr);
	}

	mlx_terminate(data->mlx_ptr);
		return (0);
}


