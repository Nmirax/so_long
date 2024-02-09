/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:36:29 by abakhaev          #+#    #+#             */
/*   Updated: 2024/02/09 11:12:32 by abakhaev         ###   ########.fr       */
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

    if (argc != 2)
    {
        write(2, "Usage: ./so_long map.ber\n", 26);
        free(data->map);
        free(data);
        return EXIT_FAILURE;
    }
    if (malloc_data(&data) != 0)
        return -1;

    data->extention_map = strrchr(argv[1], '.');
    if (data->extention_map == NULL || !ft_check_format(data))
    {
        write(2, "Invalid map file format. Use a .ber file.\n", 43);
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
    check_map(data);
    draw_map(data);
    game_loop(data);
    // collect_object(data);
    free_map_memory(data->map);
    mlx_terminate(data->mlx_ptr);
    free(data);
}

