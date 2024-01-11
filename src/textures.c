/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:45:06 by abakhaev          #+#    #+#             */
/*   Updated: 2024/01/11 17:03:59 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int load_textures(t_data *data)
{
    int i;
    int j;
    mlx_image_t *img;
    i = 0;
    
    printf("Test\n");
    img = mlx_texture_to_image(data->mlx_ptr, data->textures[i]);
    
	data->textures[0] = mlx_load_xpm42("../src/bas.xpm");
	data->textures[1] = mlx_load_xpm42("../src/haut.xpm");
	data->textures[2] = mlx_load_xpm42("../src/gauche.xpm");
	data->textures[3] = mlx_load_xpm42("../src/droite.xpm");
	data->textures[4] = mlx_load_xpm42("../src/coins.xpm");
	data->textures[5] = mlx_load_xpm42("../src/mur.xpm");
	data->textures[6] = mlx_load_xpm42("../src/sol.xpm");
	data->textures[7] = mlx_load_xpm42("../src/escape.xpm");

    while (i < NUM_TEXTURES)
    {
        if (!img)
        {
            printf("Échec de la conversion de la texture en image\n");  
        }
    j = 0;
    while (j <= i)
    {
    {
        free_textures(data->textures[j]);
        j++;
     }
            return 0;
        }

        data->images[i] = img;
        i++;
    }
    
    if (data->textures[0] != NULL) {
        printf("Texture 0 chargée avec succès\n");
    } else {
        printf("Échec du chargement de la texture 0\n");
    }

    return 1;
}

void draw_textures(t_data *data)
{
    int rows;
    int cols;
    int x;
    int y;
    char symbol;
    void *player_texture;

    rows = 0;
    while (rows < data->map->rows)
    {
        cols = 0;
        while (cols < data->map->cols)
        {
            symbol = data->map->map[rows][cols];
            x = cols * 36;
            y = rows * 31;

            if (symbol == '1') 
            {
                if (data->textures[5]) {
                    mlx_image_to_window(data->mlx_ptr, data->textures[5], x, y);
                }
            }
            else if (symbol == 'E')
            {
                if (data->textures[7]) {
                    mlx_image_to_window(data->mlx_ptr, data->textures[7], x, y);
                }
            }
            else if (symbol == 'P' || symbol == '0' || symbol == 'C' || symbol == '#' || symbol == '1')
            {
                draw_textures2(data);
                player_texture = choose_player_texture(data);
                if (player_texture) {
                    mlx_image_to_window(data->mlx_ptr, player_texture, x, y);
                }
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
    int y;
    char symbol;

    rows = 0;
    while (rows < data->map->rows)
    {
        cols = 0;  // Réinitialisation de cols pour chaque nouvelle ligne
        while (cols < data->map->cols)
        {
            symbol = data->map->map[rows][cols];
            x = cols * 36;
            y = rows * 31;

            if (symbol == 'C') 
            {
                if (data->textures[4]) {
                    mlx_image_to_window(data->mlx_ptr, data->textures[4], x, y);
                }
            }
            else if (symbol == '0')
            {
                if (data->textures[6]) {
                    mlx_image_to_window(data->mlx_ptr, data->textures[6], x, y);
                }
            }
            else if (symbol == '#')
            {
                if (data->textures[6]) {
                    mlx_image_to_window(data->mlx_ptr, data->textures[6], x, y);
                }
            }
            else if (symbol == '5')
            {
                if (data->textures[6]) {
                    mlx_image_to_window(data->mlx_ptr, data->textures[6], x, y);
                }
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

int display_image(t_data *data)
{
    int x;
    int y;

    x = 100;
    y = 100;
    if (data->images[0] == NULL) {
        return 0;
    }

    if (mlx_image_to_window(data->mlx_ptr, data->images[0], x, y) < 0) {
        return 0;
    }

    return 1;
}
