/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:27:00 by abakhaev          #+#    #+#             */
/*   Updated: 2024/02/09 14:16:08 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	save_player_pos(t_data *data, int i, int j)
{
    data->start_pos++;
    data->player.y = i;
    data->player.x = j;
}