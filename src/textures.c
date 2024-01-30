/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:45:06 by abakhaev          #+#    #+#             */
/*   Updated: 2024/01/30 19:21:05 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void draw_map(t_data *data)
{
    int x;
    int y;
	xpm_t *sol;
	xpm_t *mur;
	xpm_t *coins;
	xpm_t *droite;
	
	droite = mlx_load_xpm42("./src/droite.xpm42");
	if (!droite)
	{
		error();
		return;
	}
	coins = mlx_load_xpm42("./src/coins.xpm42");
		if (!coins)
		{
			error();
			return;
		}
	mur = mlx_load_xpm42("./src/mur.xpm42");
	if(!mur)
	{
		error();
		return;
	}
    sol = mlx_load_xpm42("./src/sol.xpm42");
    if (!sol)
    {
        error();
        return;  
    }
	mlx_image_t *droitee = mlx_texture_to_image(data->mlx_ptr, &droite->texture);
	if (!droitee)
	{
		error();
		return;
	}
	mlx_image_t *coinss = mlx_texture_to_image(data->mlx_ptr, &coins->texture);
	if(!coinss)
	{
		error();
		return;
	}
	mlx_image_t *murr = mlx_texture_to_image(data->mlx_ptr, &mur->texture);
	if (!murr)
	{
		error();
		return;
	}
    mlx_image_t *soll = mlx_texture_to_image(data->mlx_ptr, &sol->texture);
    if (!soll)
    {
        error();
        return;
    }
    y = 0;
	
    while (y < data->map->rows)
    {
        x = 0;
        while (x < data->map->cols)
        {
            if (data->map->map[y][x] == '0')
                mlx_image_to_window(data->mlx_ptr, soll, x * 64, y * 64);
            else if(data->map->map[y][x] == '1')
			{
				mlx_image_to_window(data->mlx_ptr, soll, x * 64, y * 64);
				mlx_image_to_window(data->mlx_ptr, murr, x * 64, y * 64);
			}
			else if(data->map->map[y][x] == 'C')
			{
				mlx_image_to_window(data->mlx_ptr, soll, x * 64, y * 64);
				mlx_image_to_window(data->mlx_ptr, coinss, x * 64, y *64);
			}
			else if(data->map->map[y][x] == 'P')
			{
				mlx_image_to_window(data->mlx_ptr, soll, x * 64, y * 64);
				mlx_image_to_window(data->mlx_ptr, droitee, data->player.x * 64, data->player.y * 64);
			}
            x++;
        }
        y++;	
	}
}