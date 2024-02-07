/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:36:29 by abakhaev          #+#    #+#             */
/*   Updated: 2024/02/07 11:45:40 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


int game_loop(t_data *data)
{
    mlx_loop_hook(data->mlx_ptr, key_hook, data);
    mlx_loop(data->mlx_ptr);
    return (0);
}

int main(int argc, char **argv)
{
    t_data *data;

     data = malloc(sizeof(t_data));
    if (data == NULL) 
    {
        perror("Échec de l'allocation de mémoire pour data");
        free(data);
        return -1;
    }

    data->map = malloc(sizeof(t_GameMap));
    if (data->map == NULL)
    {
        perror("Échec de l'allocation de mémoire pour game_map");
        free(data);
        return EXIT_FAILURE;
    }

    data->player.x = 3;
data->player.y = 2;

    if (argc != 2)
    {
        write(2, "Usage: ./so_long map.ber\n", 26);
        free(data->map);
        free(data);
        return EXIT_FAILURE;
    }

    data->mlx_ptr = mlx_init(WIDTH, HEIGHT, "So Long", true);
    if (data->mlx_ptr == NULL)
    {
        free(data->map);
        return EXIT_FAILURE; 
    }
    

    data->map->rows = MAX_ROWS;
    data->map->cols = MAX_COLS;
    allocate_map_memory(data->map);
    read_map_from_file(argv[1], data->map);
    draw_map(data);
    game_loop(data);
    collect_object(data);
    free_map_memory(data->map);
    mlx_terminate(data->mlx_ptr);
}
