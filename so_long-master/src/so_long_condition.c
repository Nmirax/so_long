/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_condition.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:03:48 by abakhaev          #+#    #+#             */
/*   Updated: 2023/12/05 19:09:20 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int collected;
int exits;

collected = 0; //faudra print sa dans lecran
exits = 0;

void replace_current_position_with_wall(t_GameMap *game_map, int current_rows, int current_cols) 
{
    game_map->map[current_rows][current_cols] = '1'; // '1' pour un mur
}

void handle_collectables_and_exits(t_GameMap *game_map, int current_rows, int current_cols)
{
    char    current_char;
    mlx_t   *mlx;
    
    current_char = game_map->map[current_rows][current_cols];
    
    if (current_char == 'C')
    {
    //appel fonction
    collect_object(game_map ,current_rows, current_cols); //a coder
}
    // else if (current_char == 'E')
    // {
        
    //     mlx_is_key_down(mlx, MLX_KEY_E);
    //     mlx_close_window(mlx);

    exits++; //a coder
    ft_printf("Sortie atteinte !\n");
    replace_current_position_with_wall(game_map, current_rows, current_cols);
    
    
    
    ft_printf("Objets collectés : %d\n", collected);
    ft_printf("Sorties atteintes : %d\n", exits);
}
}
