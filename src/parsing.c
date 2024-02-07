/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:53:23 by abakhaev          #+#    #+#             */
/*   Updated: 2024/02/07 14:55:52 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


// int check_map(t_data *data)
// {
//     int items;
    
//     if (check_sign(data) == false)
        
//     if(check_size(data) == false)

//     if (check_count(data) == false)

//     if(check_walls(data) == false)

// }


int check_count(t_data *data)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (data->map->map[i] != NULL)
    {
        j = 0;
        while (data->map->map[i][j] != '\0')
        {
            if (data->map->map[i][j] == 'E')
                data->map_exit++;
            if (data->map->map[i][j] == 'P')
                save_player_pos(data, i, j);
            if(data->map->map[i][j] == 'C')
                data->collectible_count++;
    
            j++;
        }
        i++;
    }
    if ((data->map_exit == 1) && (data->start_pos == 1)
    && (data->collectible_count > 0))
        return (true);
    else
        return (false);
}


int	check_sign(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map->map[i] != NULL)
	{
		j = 0;
		while (data->map->map[i][j] != '\0')
		{
			if ((data->map->map[i][j] != '0')
			&& (data->map->map[i][j] != '1')
			&& (data->map->map[i][j] != 'C')
			&& (data->map->map[i][j] != 'P')
			&& (data->map->map[i][j] != 'E')
			&& (data->map->map[i][j] != '\r')
			&& (data->map->map[i][j] != '\n'))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

int check_size(t_data *data)
{
    int i;
    size_t first_line_length;
    size_t next_line_length;

    i = 0;
    first_line_length = ft_strlen(data->map->map[i]) - 1;
    while(data->map->map[i] != NULL)
    {
        if (ft_strchr(data->map->map[i], '\n'))
            next_line_length = ft_strlen(data->map->map[i]) - 1;
        else
            next_line_length = ft_strlen(data->map->map[i]);
        if (next_line_length != first_line_length)
            return (false);

        i++;
    }
    return (true);
}


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