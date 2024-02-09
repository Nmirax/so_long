/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_instances.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:20:28 by abakhaev          #+#    #+#             */
/*   Updated: 2024/02/09 10:13:14 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void player_up(t_data *data) 
{
    if (data->player.y > 0 && data->map->map[data->player.y - 1][data->player.x] != '1') 
    {
        data->droitee->instances->y -= 64;
        data->player.y--;
        ft_printf("you mooved %d times\n", data->moove_count++);
    }
    return;
}

void player_down(t_data *data) 
{
    if (data->player.y < data->map->rows - 1 && data->map->map[data->player.y + 1][data->player.x] != '1') 
    {
        data->droitee->instances->y += 64;
        data->player.y++;
        ft_printf("you mooved %d times\n", data->moove_count++);
    }
    return;
}

void player_right(t_data *data) 
{   
    printf("cols = %i\n", data->player.x);
    if (data->player.x < data->map->cols - 4 && data->map->map[data->player.y][data->player.x + 1] != '1') 
    {
        data->droitee->instances->x += 64;
        data->player.x++;
        ft_printf("you mooved %d times\n", data->moove_count++);
    }
    return;
}

void player_left(t_data *data) 
{
    
    
    if (data->player.x > 0 && data->map->map[data->player.y][data->player.x - 1] != '1') 
    {
        data->droitee->instances->x -= 64;
        data->player.x--;
        ft_printf("you mooved %d times\n", data->moove_count++);
    }
    return;
}
