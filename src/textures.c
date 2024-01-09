/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:45:06 by abakhaev          #+#    #+#             */
/*   Updated: 2024/01/09 17:42:59 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int load_textures(t_data *data)
{

    int i;

    i = 0;
	data->textures[0] = mlx_load_xpm42("bas.xpm");
	data->textures[1] = mlx_load_xpm42("haut.xpm");
	data->textures[2] = mlx_load_xpm42("gauche.xpm");
	data->textures[3] = mlx_load_xpm42("droite.xpm");
	data->textures[4] = mlx_load_xpm42("coins.xpm");
	data->textures[5] = mlx_load_xpm42("mur.xpm");
	data->textures[6] = mlx_load_xpm42("sol.xpm");
	data->textures[7] = mlx_load_xpm42("escape.xpm");
    while (i < NUM_TEXTURES)
    {
        if (data->textures[i] == NULL)
            return 0; 
        i++;
    }
    return 1; 
}


void draw_textures(t_data *data)
{

    int rows;
    int cols;
    int x;
    int y;;
    char symbol;
    void *player_texture;

    rows = 0;
    cols = 0;
    while (rows < data->map->rows)
    {
        while (cols < data->map->cols)
        {
            symbol = data->map->map[rows][cols];
            x = cols * 36;
            y = rows * 31;

            if (symbol == '1') 
            {
                mlx_image_to_window(data->mlx_ptr, data->textures[5], x, y);
            }
            else if (symbol == 'E')
            {
                mlx_image_to_window(data->mlx_ptr, data->textures[7], x, y);
            }
            else if (symbol == 'P' || symbol == '0' || symbol == 'C' || symbol == '#' || symbol == '1')
            {
                draw_textures2(data);
                player_texture = choose_player_texture(data);
                mlx_image_to_window(data->mlx_ptr, player_texture, x, y);
            }
            cols++;
        }
        rows++;
    }
}


void draw_textures2(t_data *data)
{
    int rows;
    int cols;
    int x;
    int y;;
    char symbol;

    rows = 0;
    cols = 0;
    while (rows < data->map->rows)
    {
        while (cols < data->map->cols)
        {
            symbol = data->map->map[rows][cols];
            x = cols * 36;
            y = rows * 31;

            if (symbol == 'C') 
            {
                mlx_image_to_window(data->mlx_ptr, data->textures[4], x, y);
            }
            if (symbol == '0')
            {
                mlx_image_to_window(data->mlx_ptr, data->textures[6], x, y);
            }
            if (symbol == '#')
            {
                mlx_image_to_window(data->mlx_ptr, data->textures[6], x, y);
            }
            if (symbol == '5')
            {
                mlx_image_to_window(data->mlx_ptr, data->textures[6], x, y);
            }
            cols++;
        }
        rows++;
    }
}

int *choose_player_texture(t_data *data)
{
	if (data->player.direction == UP)
		return data->textures[1];
	else if (data->player.direction == DOWN)
		return data->textures[0];
	else if (data->player.direction == RIGHT)
		return data->textures[3];
	else if (data->player.direction == LEFT)
		return data->textures[2];
    else
        return data->textures[0];

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