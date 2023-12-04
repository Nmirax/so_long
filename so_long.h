/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:41:33 by abakhaev          #+#    #+#             */
/*   Updated: 2023/12/04 14:52:15 by abakhaev         ###   ########.fr       */
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

mlx_t	g_mlx;

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

void	allocate_map_memory(t_GameMap *game_map);
void	read_map_line(int fd, char *buffer, t_GameMap *game_map);
void	read_map(const char *filename, t_GameMap *game_map);
void	free_map(t_GameMap *game_map);
void	free_map_memory(t_GameMap *game_map);
void	render_frame(t_GameMap *game_map);

#endif