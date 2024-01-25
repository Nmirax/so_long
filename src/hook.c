/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:16:32 by abakhaev          #+#    #+#             */
/*   Updated: 2024/01/25 12:49:04 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void key_hook(void *param)
{
    t_data *data = (t_data *)param;

    if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_ESCAPE))
        mlx_close_window(data->mlx_ptr);
    else if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_W)) // Déplacer vers le haut
    {
        data->player.y -= 1; // Décrémenter y pour monter
        data->player.direction = UP;
    }
    else if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_A)) // Déplacer vers la gauche
    {
        data->player.x -= 1; // Décrémenter x pour aller à gauche
        data->player.direction = LEFT;
    }
    else if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_D)) // Déplacer vers la droite
    {
        data->player.x += 1; // Incrémenter x pour aller à droite
        data->player.direction = RIGHT;
    }
    else if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_S)) // Déplacer vers le bas
    {
        data->player.y += 1; // Incrémenter y pour descendre
        data->player.direction = DOWN;
    }
    else if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_E)) // Action spéciale (par exemple, utiliser un objet)
    {
        if (all_coins_collected(data))
        {
            exit_game(data);
        }
    }

    // Vérifier et corriger si le joueur se déplace hors des limites de la carte
    data->player.x = (data->player.x < 0) ? 0 : data->player.x;
    data->player.x = (data->player.x >= data->map->cols) ? data->map->cols - 1 : data->player.x;
    data->player.y = (data->player.y < 0) ? 0 : data->player.y;
    data->player.y = (data->player.y >= data->map->rows) ? data->map->rows - 1 : data->player.y;
}
