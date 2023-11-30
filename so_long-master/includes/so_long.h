/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:41:33 by abakhaev          #+#    #+#             */
/*   Updated: 2023/11/30 13:29:28 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include "../printf/include/ft_printf.h"
# include <stdbool.h>

# define MAX_COLS 100

typedef struct s_map
{
	char	**map;
	int		rows;
	int		cols;
}	t_GameMap;

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

void	initialize_game(void);
void	read_map(const char *filename);
void	*mlx_new_window(void *mlx_ptr, int width, int height, char *title);

#endif