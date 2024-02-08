/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:27:31 by abakhaev          #+#    #+#             */
/*   Updated: 2024/02/08 16:38:16 by abakhaev         ###   ########.fr       */
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

int	ft_check_format(t_data *data)
{
	size_t	i;

	i = ft_strlen(data->extention_map);
	if ((data->extention_map[i - 1] == 'r')
		&& (data->extention_map[i - 2] == 'e')
		&& (data->extention_map[i - 3] == 'b')
		&& (data->extention_map[i - 4] == '.'))
		return (true);
	else
		return (false);
}

void break_wall(t_data *data, int x, int y) {
    int map_rows = data->map->rows;
    int map_cols = data->map->cols;

    // Vérifiez si les coordonnées sont à l'intérieur des limites de la carte
    if (x >= 0 && x < map_cols && y >= 0 && y < map_rows) {
        // Vérifiez si la case adjacente est un mur ('1')
        if (data->map->map[y][x] == '1') {
            // Vérifiez si la case adjacente n'est pas un mur entourant la carte
            if (!is_outer_wall(data, x, y)) {
                // Si ce n'est pas un mur entourant la carte, mettez à jour la carte
                data->map->map[y][x] = '0';
                draw_map(data);
            }
        }
    }
}

// Fonction pour vérifier si une case est un mur entourant la carte
int is_outer_wall(t_data *data, int x, int y) {
    int map_rows = data->map->rows;
    int map_cols = data->map->cols;

    // Si la case est sur le bord de la carte, elle est un mur entourant la carte
    if (x == 0 || x == map_cols - 1 || y == 0 || y == map_rows - 1) {
        return true;
    } else {
        return false;
    }
}
