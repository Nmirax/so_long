/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_instances.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:20:28 by abakhaev          #+#    #+#             */
/*   Updated: 2024/02/06 18:00:08 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void    player_up(t_data *data)
{
    data->droitee->instances->y -= 12;
    data->player.y--;
    return;
}

void    player_down(t_data *data)
{
    data->droitee->instances->y += 12;
    data->player.y++;
    return;
}

void    player_right(t_data *data)
{
    data->droitee->instances->x += 12;
    data->player.x++;
    return;
}

void    player_left(t_data *data)
{
    data->droitee->instances->x -= 12;
    data->player.x--;
    return;
}