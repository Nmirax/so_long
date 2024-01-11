/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_condition.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:03:48 by abakhaev          #+#    #+#             */
/*   Updated: 2024/01/11 11:55:10 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/***********************************************************************************************************************/

void replace_current_position_with_wall(t_data *data) 
{
   t_GameMap *game_map;
    int     rows;
    int     cols;
     
      game_map =data->map;
     rows = game_map->rows;
    cols = game_map->cols;

    game_map->map[rows][cols] = '#';
}
/***********************************************************************************************************************/

void handle_collectables_and_exits(t_data *data)
{
    t_GameMap *game_map;
    int     player_x;
    int     player_y;
    char    current_char;
    
    game_map = data->map;
    player_x = data->player.x; 
    player_y = data->player.y;
    
    current_char = game_map->map[player_y][player_x];

    if (current_char == 'C')
    {
        // Appel fonction pour collecter l'objet
        collect_object(data);
    }
    else if (current_char == 'E')
    {
        exit_game(data);
    }
}

/***********************************************************************************************************************/

void collect_object(t_data *data)
{ 
    t_GameMap *game_map;
    int rows; 
    int cols; 
    int collected;
    
     game_map =data->map;
    cols = game_map->cols;
    rows =game_map->rows;
    collected = 0;

    game_map = data->map;
    
    if (rows >= 0 && rows < game_map->rows &&
        cols >= 0 && cols < game_map->cols) 
    {
        char current_char = game_map->map[rows][cols];

        if (current_char == 'C')
    {
        collected++;
        replace_current_position_with_wall(data);
        ft_printf("Objet collecté !\n");
    } 
        else if (rows == 0 && cols == 0) 
        {
            ft_printf("Aucun objet à collecter à cette position.\n");
        }
        else if (rows == 'P' && cols == 'P') 
        {
            ft_printf("Aucun objet à collecter à cette position.\n");
        }
        else if (rows == 'E' && cols == 'E') 
        {
            ft_printf("Aucun objet à collecter à cette position.\n");
        }
    } 
    else 
    {
        ft_printf("Indices hors limites !\n");
    }
}
/***********************************************************************************************************************/

void exit_game(t_data *data)
{
    t_GameMap *game_map; 
    
    int rows;
    int cols;

    game_map = data->map;
    rows = game_map->rows;
    cols = game_map->cols;

    if (game_map->map[rows][cols] == 'E')
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