/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_condition.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:03:48 by abakhaev          #+#    #+#             */
/*   Updated: 2023/12/05 15:21:54 by abakhaev         ###   ########.fr       */
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

    current_char = game_map->map[current_rows][current_cols];
    
    if (current_char == 'C')
    //appel fonction
}