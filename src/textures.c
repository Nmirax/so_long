/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:45:06 by abakhaev          #+#    #+#             */
/*   Updated: 2023/12/14 13:23:09 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_textures(t_data *data)
{

	data->textures[0] = mlx_load_xpm42("bas.xpm");
	data->textures[1] = mlx_load_xpm42("haut.xpm");
	data->textures[2] = mlx_load_xpm42("gauche.xpm");
	data->textures[3] = mlx_load_xpm42("droite.xpm");
	data->textures[4] = mlx_load_xpm42("coins.xpm");
	data->textures[5] = mlx_load_xpm42("mur.xpm");
	data->textures[6] = mlx_load_xpm42("sol.xpm");
	data->textures[7] = mlx_load_xpm42("escape.xpm");
}

void	draw_textures(t_data *data)
{
	int		rows;
	int		cols;
	int		x;
	int		y;
	char	symbol;
	
	rows = 0;
	cols = 0;
		while(rows < data->map->rows)
		{
			while(cols <data->map->cols)
				{
			symbol = data->map->map[rows][cols];

			x = cols * 16;
			y = rows * 16;

			if (symbol == '1') 
			{
                mlx_image_to_window(data->mlx_ptr, data->textures[5], x, y);
            } 
			// else if (symbol == '0')
			// {
			// 	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[7], x, y);
			// }
			else if (symbol == 'E')
			{
				mlx_image_to_window(data->mlx_ptr, data->textures[7], x, y);
			}
			else if (symbol == 'P' || symbol == '0' || symbol == 'C' || symbol == '#' || symbol == '1')
			{
				if (key_hook(13, data))
					mlx_image_to_window(data->mlx_ptr, data->textures[1], x, y);
				if (key_hook(1, data))
					mlx_image_to_window(data->mlx_ptr, data->textures[0], x, y);
				if (key_hook(16, data))
					mlx_image_to_window(data->mlx_ptr, data->textures[1], x, y);
				if (key_hook(2, data))
					mlx_image_to_window(data->mlx_ptr, data->textures[3], x, y);
			}
			cols++;
		}
		rows++;
	}
}

void free_textures(t_data *data)
{
    int i = 0;
    while (i < NUM_TEXTURES)
    {
        if (data->textures[i])
        {
            mlx_delete_texture(data->textures[i]);
            data->textures[i] = NULL;
        }
        i++;
    }
}