/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:36:29 by abakhaev          #+#    #+#             */
/*   Updated: 2024/01/08 12:18:13 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


void	update(t_data *data)
{
    is_valid_map(data);
    key_hook(data);
    is_valid_map(data);
    handle_collectables_and_exits(data);
    exit_game(data);
}

int	game_loop(t_data *data)
{
	while(1)
	{
        update(data);
        draw_textures(data);
		mlx_loop_hook(data->mlx_ptr, key_hook, data);
        mlx_loop(data->mlx_ptr);
    }
        mlx_close_window(data->mlx_ptr);
            return (0);
}

int main(int argc, char **argv)
{
    printf("Début de la fonction main.\n");

    t_data data;
    printf("t_data initialisé.\n");

    // Initialisation de data.map
    data.map = malloc(sizeof(t_GameMap));
    if (data.map == NULL)
    {
        perror("Échec de l'allocation de mémoire pour game_map");
        return EXIT_FAILURE;
    }
    printf("Mémoire allouée pour data.map: %p\n", (void *)data.map);

    if (argc != 2)
    {
        write(2, "Usage: ./so_long map.ber\n", 26);
        return EXIT_FAILURE;
    }

    data.mlx_ptr = mlx_init(WIDTH, HEIGHT, "So Long", true);
    if (data.mlx_ptr == NULL)
        return EXIT_FAILURE;
    printf("MLX initialisé.\n");

    // Charger les textures
    if (load_textures(&data))
    {
        return EXIT_FAILURE;
    }
    printf("Textures chargées.\n");

    // Initialisation des dimensions de la carte
    data.map->rows = MAX_ROWS; // Assurez-vous que ces valeurs sont correctes
    data.map->cols = MAX_COLS;
    printf("Dimensions de la carte définies: lignes = %d, colonnes = %d\n", data.map->rows, data.map->cols);

    // Allocation de mémoire pour la carte
    allocate_map_memory(data.map);
    printf("Mémoire allouée pour la carte.\n");

    // Lecture de la carte
    printf("Lecture de la carte à partir du fichier: %s\n", argv[1]);
    read_map_from_file(argv[1], data.map);

    // Lancer la boucle de jeu
    printf("Début de la boucle de jeu.\n");
    mlx_loop(data.mlx_ptr);

    // Libération de la mémoire
    printf("Libération de la mémoire.\n");
    free_map_memory(data.map);
    free(data.map);

    free_textures(&data);
    printf("Fin de la fonction main.\n");

    return EXIT_SUCCESS;
}