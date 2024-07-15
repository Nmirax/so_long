/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:59:54 by abakhaev          #+#    #+#             */
/*   Updated: 2024/07/15 11:48:15 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_display_image(t_data *data)
{
	ft_display_bg(data);
	ft_display_wall(data);
	ft_display_collectible(data);
	ft_display_exit(data);
	mlx_image_to_window(data->mlx_ptr, data->image_player[0],
		data->player_pos_x * 64, data->player_pos_y * 64);
	return (0);
}

int	ft_display_bg(t_data *smain)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (i < smain->map_size)
	{
		k = 0;
		while (smain->map[j][k] != '\0' && smain->map[j][k] != '\n')
		{
			mlx_image_to_window(smain->mlx_ptr,
				smain->image_bg[i], k * 64, j * 64);
			i++;
			k++;
		}
		j++;
	}
	return (0);
}

int	ft_display_collectible(t_data *smain)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (i < smain->collectible_count)
	{
		k = 0;
		while (smain->map[j][k] != '\0' && smain->map[j][k] != '\n')
		{
			if (smain->map[j][k] == 'C')
			{
				mlx_image_to_window(smain->mlx_ptr,
					smain->image_collectible[i], k * 64, j * 64);
				i++;
			}
			k++;
		}
		j++;
	}
	return (0);
}

int	ft_display_exit(t_data *smain)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (i < 1)
	{
		k = 0;
		while (smain->map[j][k] != '\0' && smain->map[j][k] != '\n')
		{
			if (smain->map[j][k] == 'E')
			{
				mlx_image_to_window(smain->mlx_ptr,
					smain->image_exit[i], k * 64, j * 64);
				i++;
			}
			k++;
		}
		j++;
	}
	return (0);
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = param;
	if (keydata.key == MLX_KEY_W && ((keydata.action == MLX_PRESS)
			|| (keydata.action == MLX_REPEAT)))
		ft_player_up(data);
	if (keydata.key == MLX_KEY_S && ((keydata.action == MLX_PRESS)
			|| (keydata.action == MLX_REPEAT)))
		ft_player_down(data);
	if (keydata.key == MLX_KEY_D && ((keydata.action == MLX_PRESS)
			|| (keydata.action == MLX_REPEAT)))
		ft_player_right(data);
	if (keydata.key == MLX_KEY_A && ((keydata.action == MLX_PRESS)
			|| (keydata.action == MLX_REPEAT)))
		ft_player_left(data);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		ft_free_all(data, "Game closed", 0);
}
