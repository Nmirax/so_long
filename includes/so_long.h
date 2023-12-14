/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:41:33 by abakhaev          #+#    #+#             */
/*   Updated: 2023/12/14 15:34:59 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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
	void		*textures[7];
	t_GameMap	*map;
}	t_data;

#define MAX_ROWS 100
#define MAX_COLS 100
#define NUM_TEXTURES 7
#define WIDTH 256
#define HEIGHT 256

void	replace_current_position_with_wall(t_data *data);
void	handle_collectables_and_exits(t_data *data);
void	collect_object(t_data *data);
void	exit_game(t_data *data);
int		all_coins_collected(t_data *data);
int		is_valid_move(t_data *data);
int		is_valid_map(t_data *data);
int		key_hook(int keycode, t_data *data);
void	update(t_data *data);
int		game_loop(t_data *data);
void	load_textures(t_data *data);
void	draw_textures(t_data *data);
void 	read_map_from_file(char *filename, t_GameMap *game_map);
// char	*ft_strncpy(char *dest, char *src, unsigned int n);
void	allocate_map_memory(t_GameMap *game_map);
void	free_map_memory(t_GameMap *game_map);
void 	free_textures(t_data *data);
#endif