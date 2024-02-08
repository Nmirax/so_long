/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:27:31 by abakhaev          #+#    #+#             */
/*   Updated: 2024/02/08 12:29:49 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int check_walls(t_data *data)
{
    int line_lenght;
    int i;

    i = 0;
        line_lenght = ft_strlen(data->map->map[0]) - 1;
            while (i < line_lenght)
                {
                    if ((data->map->map[0][i] != '1'))
                        return (false);
                    i++;
                }
            i = 0;
        while (i < data->count_line)
        {
            if ((data->map->map[i][0] != '1')
            || (data->map->map[i][line_lenght - 1] != '1'))
                return (false);
            i++;
        }
        return(true);
}