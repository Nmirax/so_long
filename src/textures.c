/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:45:06 by abakhaev          #+#    #+#             */
/*   Updated: 2024/02/22 13:35:51 by abakhaev         ###   ########.fr       */
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

	data->droite = mlx_load_png("./src/player.png");
	data->coins = mlx_load_png("./src/coins.png");
	data->mur = mlx_load_png("./src/mur.png");
    data->sol = mlx_load_png("./src/sol.png");
    data->escape = mlx_load_png("./src/escape.png");
	
    
	data->droitee = mlx_texture_to_image(data->mlx_ptr, data->droite);
	data->coinss = mlx_texture_to_image(data->mlx_ptr, data->coins);
	data->murr = mlx_texture_to_image(data->mlx_ptr, data->mur);
    data->soll = mlx_texture_to_image(data->mlx_ptr, data->sol);
    data->escapee = mlx_texture_to_image(data->mlx_ptr, data->escape);
	

if (data->droite == NULL || data->coins == NULL || data->mur == NULL || data->sol == NULL || data->escape == NULL ||
        data->droitee == NULL || data->coinss == NULL || data->murr == NULL || data->soll == NULL || data->escapee == NULL) {
        printf("Erreur lors du chargement des textures ou des images\n");
        free_texture(data);
        return;
    }

    y = 0;
    while (y < data->map->rows)
    {
        x = 0;
        while (x < data->map->cols)
        {
            if (data->map->map[y][x] == '0') 
                mlx_image_to_window(data->mlx_ptr, data->soll, x * 64, y * 64);
            else if(data->map->map[y][x] == '1')
                mlx_image_to_window(data->mlx_ptr, data->murr, x * 64, y * 64);
            else if(data->map->map[y][x] == 'C')
            {
                mlx_image_to_window(data->mlx_ptr,data->soll, x * 64, y * 64);
                mlx_image_to_window(data->mlx_ptr,data->coinss, x * 64, y * 64);
            }
            else if(data->map->map[y][x] == 'E')
            {
                mlx_image_to_window(data->mlx_ptr,data->soll, x * 64, y * 64);
                mlx_image_to_window(data->mlx_ptr,data->escapee, x * 64, y * 64);
            }
            x++;
        }
        y++;
    }

    y = 0;
    while (y < data->map->rows)
    {
        x = 0;
        while (x < data->map->cols)
        {
            if (data->map->map[y][x] == 'P')
            {
                mlx_image_to_window(data->mlx_ptr, data->soll, x * 64, y * 64);
                mlx_image_to_window(data->mlx_ptr, data->droitee, data->player.x * 64, data->player.y * 64);
                return;
            }
            x++;
        }
        y++;
    }
    free_texture(data);
    printf("player error\n");
}

void	free_wall(t_data *data)
{
	int	i;

	i = 0;
	while (data->murr && i < data->wall_count)
	{
		mlx_delete_image(data->mlx_ptr, data->murr);
		i++;
	}
	free(data->murr);
    data->murr = NULL;
}