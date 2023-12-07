/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:41:33 by abakhaev          #+#    #+#             */
/*   Updated: 2023/12/07 13:30:12 by abakhaev         ###   ########.fr       */
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

typedef struct s_GameMap 
{
    char	**map;
    int 	rows;
    int		cols;
} t_GameMap;


typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*textures[5];
	t_GameMap	*map;
}	t_data;

#define MAX_ROWS 100
#define MAX_COLS 100

int	is_valid_move(t_GameMap *game_map, int rows, int cols);
int	is_valid_map(t_GameMap *game_map);
void ft_hook(void *param);
void replace_current_position_with_wall(t_GameMap *game_map, int current_rows, int current_cols);
void handle_collectables_and_exits(t_GameMap *game_map, int current_rows, int current_cols);
void    exit_game(t_data *data, int current_rows, int current_cols);
int 	all_coins_collected(t_data *data);
int 	key_hook(int keycode t_data *data);
#endif