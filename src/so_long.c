/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:36:29 by abakhaev          #+#    #+#             */
/*   Updated: 2024/01/11 14:16:20 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void refresh_window(void *param)
{
    t_data *data = (t_data *)param;
    draw_textures(data);
    draw_textures2(data);
    display_image(data);
    handle_collectables_and_exits(data);
    
}

int game_loop(t_data *data)
{
    mlx_loop_hook(data->mlx_ptr, refresh_window, data); // Hook pour rafraîchir la fenêtre
    mlx_loop_hook(data->mlx_ptr, key_hook, data); // Hook pour les entrées clavier
    mlx_loop(data->mlx_ptr); // Démarre la boucle d'événements
    mlx_close_window(data->mlx_ptr); // Ferme la fenêtre après la fin de la boucle
    return (0);
}

int main(int argc, char **argv)
{
    t_data *data;

     data = malloc(sizeof(t_data));
    if (data == NULL) 
    {
        perror("Échec de l'allocation de mémoire pour data");
        return -1;
    }

    data->map = malloc(sizeof(t_GameMap));
    if (data->map == NULL)
    {
        perror("Échec de l'allocation de mémoire pour game_map");
        free(data);
        return EXIT_FAILURE;
    }

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
        free(data);
        return EXIT_FAILURE; 
    }
    
    if (load_textures(data))
    {   
        mlx_close_window(data->mlx_ptr);
        free(data->map);
        free(data);
        return EXIT_FAILURE;
    }

    data->map->rows = MAX_ROWS; 
    data->map->cols = MAX_COLS;
    allocate_map_memory(data->map);
    read_map_from_file(argv[1], data->map);
    game_loop(data);
    mlx_loop(data->mlx_ptr);
    free_map_memory(data->map);
    free_textures(data);
    free(data);
    return EXIT_SUCCESS;
}