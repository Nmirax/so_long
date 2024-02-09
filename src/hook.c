/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:16:32 by abakhaev          #+#    #+#             */
/*   Updated: 2024/02/09 10:26:26 by abakhaev         ###   ########.fr       */
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
        player_up(data);
        collect_object(data);
    }
    else if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_A)) // Déplacer vers la gauche
    {
        player_left(data);
        collect_object(data);
    }
    else if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_D)) // Déplacer vers la droite
    {
        player_right(data);
        collect_object(data);
    }
    else if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_S)) // Déplacer vers le bas
    {
        player_down(data);
        collect_object(data);
    }
    else if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_E)) // Action spéciale (par exemple, utiliser un objet)
    {
        if (all_coins_collected(data))
        {
            exit_game(data);
        }
    }
    else if (mlx_is_key_down(data->mlx_ptr, MLX_KEY_T))
    {
        int player_x = data->player.x;
        int player_y = data->player.y;
        break_wall(data, player_x - 1, player_y);
        break_wall(data, player_x + 1, player_y);
        break_wall(data, player_x, player_y - 1);
        break_wall(data, player_x, player_y + 1);
    }
}

