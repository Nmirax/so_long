/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_condition.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:03:48 by abakhaev          #+#    #+#             */
/*   Updated: 2023/12/07 14:48:18 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

   int collected;

    collected = 0;

/***********************************************************************************************************************/
void replace_current_position_with_wall(t_GameMap *game_map, int current_rows, int current_cols) 
{
    game_map->map[current_rows][current_cols] = '#';
}
/***********************************************************************************************************************/
void handle_collectables_and_exits(t_GameMap *game_map, int current_rows, int current_cols)
{
    char    current_char;
    
    current_char = game_map->map[current_rows][current_cols];

    if (current_char == 'C')
    {
    //appel fonction
    collect_object(game_map, current_rows, current_cols);
}
    else if (current_char == 'E')
        exit_game(game_map, current_rows, current_cols);   
}

/***********************************************************************************************************************/

void collect_object(t_GameMap *game_map, int rows, int current_cols)
{   
     if (current_rows >= 0 && current_rows < game_map->rows &&
        current_cols >= 0 && current_cols < game_map->cols) 
        {
    if (game_map->map[current_rows][current_cols] == 'C')
    {
        collected++;
        replace_current_position_with_wall(game_map, current_rows, current_cols);
        ft_printf("Objet collecté !\n");
    } 
        else if (current_rows == 0 && current_cols == 0) 
        {
            ft_printf("Aucun objet à collecter à cette position.\n");
        }
        else if (current_rows == 'P' && current_cols == 'P') 
        {
            ft_printf("Aucun objet à collecter à cette position.\n");
        }
        else if (current_rows == 'E' && current_cols == 'E') 
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

void exit_game(t_data *data, int current_rows, int current_cols)
{
    if (data->map->map[current_rows][current_cols] == 'E')
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