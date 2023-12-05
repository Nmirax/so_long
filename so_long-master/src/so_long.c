/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:36:29 by abakhaev          #+#    #+#             */
/*   Updated: 2023/12/05 18:52:58 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"





void ft_hook(void *param)
{
    mlx_t *mlx;
    
    mlx = param;

    if (mlx_is_key_down(mlx, MLX_KEY_ESC))
        mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_E))
        mlx_close_window(mlx);
    if (mlx_is_key_down(mlx, MLX_KEY_W))
        image->instances[0].y -= 5;
    if (mlx_is_key_down(mlx, MLX_KEY_S))
        image->instances[0].y += 5;
    if (mlx_is_key_down(mlx, MLX_KEY_A))
        image->instances[0].x -= 5;
    if (mlx_is_key_down(mlx, MLX_KEY_D))
        image->instances[0].x += 5;
}

//verification a faire et recoder les fonction

if (all_coins_collected && exit_count == 1)
	return (map_valid);
if (charactere_on_wall)
	return (map_invalid);
if (charactere_coins_collected)
	collected++;
if (charactere_is_exits)
	exits++;
replace_current_position_with_wall;
if (one_of_the_four_adjacent_directions_is_possible)
	return (map_valid);
	return (map_invalid);

int	main(void)
{

}