/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_condition.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:03:48 by abakhaev          #+#    #+#             */
/*   Updated: 2024/02/08 17:17:03 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void collect_object(t_data *data) 
{
    int x = data->player.x;
    int y = data->player.y;
    
    if (data->map->map[y][x] == 'C') 
    {
        data->map->map[y][x] = '0';
        mlx_delete_texture(data->coins);
        draw_map(data);
        data->collected_coins++;
        ft_printf("Pièce collectée !\n");
    }
}

void exit_game(t_data *data)
{
    t_GameMap *game_map = data->map;
    
    if (game_map->map[data->player.y][data->player.x] == 'E')
    {
        if (all_coins_collected(data))
        {
            ft_printf("Toutes les pièces ont été collectées !\n");
            mlx_close_window(data->win_ptr);
        }
        else
        {
            ft_printf("Vous ne pouvez pas sortir avant de collecter toutes les pièces.\n");
        }
    }
}
int all_coins_collected(t_data *data)
{
    t_GameMap *game_map = data->map;
    int i; 
    int j;

    i = 0;
    while (i < game_map->rows)
    {
        j = 0;
        while (j < game_map->cols)
        {
            if (game_map->map[i][j] == 'C')
            {
                ft_printf("Il reste des pièces à collecter.\n");
                return 0;
            }
            j++;
        }
        i++;
    }

    ft_printf("Toutes les pièces ont été collectées !\n");
    return 1;
}