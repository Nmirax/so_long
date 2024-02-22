/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:36:29 by abakhaev          #+#    #+#             */
/*   Updated: 2024/02/22 13:37:01 by abakhaev         ###   ########.fr       */
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
    t_data *data = NULL;

    if (argc != 2)
    {
        write(2, "Usage: ./so_long map.ber\n", 26);
        free(data);
        return EXIT_FAILURE;
    }
    if (malloc_data(&data) != 0)
    {
        free(data);
        return -1;
    }

    data->extention_map = strrchr(argv[1], '.');
    if (data->extention_map == NULL || !ft_check_format(data))
    {
        write(2, "Invalid map file format. Use a .ber file.\n", 43);
        free(data->map); // Libérer la mémoire allouée pour data->map
        free(data); // Libérer la mémoire allouée pour data
        return EXIT_FAILURE;
    }

    data->mlx_ptr = mlx_init(WIDTH, HEIGHT, "So Long", false);
    if (data->mlx_ptr == NULL)
    {
        allocate_map_memory(data->map);
        free_data(&data);
        free(data);
        return EXIT_FAILURE;
    }

    data->map->rows = MAX_ROWS;
    data->map->cols = MAX_COLS;
    
    allocate_map_memory(data->map);
    read_map_from_file(argv[1], data->map);
    check_map(data);
    draw_map(data);
    game_loop(data);
    mlx_close_hook(data->mlx_ptr, &my_close_hook, &data);
    free_map_memory(data->map);
    mlx_terminate(data->mlx_ptr);
    free_data(&data);
    free(data);
    
    return EXIT_SUCCESS;
}

