/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:02:09 by abakhaev          #+#    #+#             */
/*   Updated: 2024/07/15 11:48:48 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_format(t_data *data)
{
	size_t	i;

	i = ft_strlen(data->mapname);
	if ((data->mapname[i - 1] == 'r')
		&& (data->mapname[i - 2] == 'e')
		&& (data->mapname[i - 3] == 'b')
		&& (data->mapname[i - 4] == '.'))
		return (true);
	else
		return (false);
}

int	ft_flood_fill(char	**map, int x, int y, int *items)
{
	if (map[y][x] == '1')
		return (false);
	if (map[y][x] == 'C' || map[y][x] == 'E')
		*items -= 1;
	map[y][x] = '1';
	ft_flood_fill(map, x - 1, y, items);
	ft_flood_fill(map, x + 1, y, items);
	ft_flood_fill(map, x, y - 1, items);
	ft_flood_fill(map, x, y + 1, items);
	if (*items == 0)
		return (true);
	return (false);
}
