/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:36:29 by abakhaev          #+#    #+#             */
/*   Updated: 2023/12/19 18:23:20 by abakhaev         ###   ########.fr       */
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
    t_data data;

    // Vérifier le nombre d'arguments
    if (argc != 2)
    {
        write(2, "Usage: ./so_long map.ber\n", 26);
        return (EXIT_FAILURE);
    }

    // Initialiser la bibliothèque MiniLibX et créer la fenêtre de jeu
    data.mlx_ptr = mlx_init(WIDTH, HEIGHT, "So Long", false);
    if (data.mlx_ptr == NULL)
        return (EXIT_FAILURE);
    // Charger les textures
    if (load_textures(data))
    {
        // Gérer l'échec du chargement des textures
        return (EXIT_FAILURE);
    }

    // Lire et valider la carte de jeu
    read_map_from_file(argv[1], &data);

    // Configurer les hooks (entrées clavier, etc.)
    mlx_key_hook(data.win_ptr, key_hook, &data);

    // Lancer la boucle de jeu
    mlx_loop(data.mlx_ptr);

    // Libérer les ressources et fermer le jeu proprement
    free_textures(&data);
    return (EXIT_SUCCESS);
}