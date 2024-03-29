/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:41:33 by abakhaev          #+#    #+#             */
/*   Updated: 2024/02/26 14:20:15 by abakhaev         ###   ########.fr       */
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
	int		rows;
	int		cols;
}	t_GameMap;

typedef struct s_Player
{
	int	x;
	int	y;

}	t_Player;

typedef struct s_wall
{
	int		x;
	int		y;
}	t_wall;

typedef struct s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_GameMap		*map;
	char			*extention_map;
	t_Player		player;
	mlx_image_t		*droitee;
	mlx_image_t		*soll;
	mlx_image_t		*murr;
	mlx_image_t		*coinss;
	mlx_image_t		*escapee;
	mlx_texture_t	*droite;
	mlx_texture_t	*escape;
	mlx_texture_t	*sol;
	mlx_texture_t	*mur;
	mlx_texture_t	*coins;
	int				wall_count;
	int				index;
	int				collected_coins;
	int				moove_count;
	int				map_exit;
	int				collectible_count;
	int				start_pos;
	int				count_line;
	int				map_size;
	t_wall			*wall;
}	t_data;

# define MAX_ROWS 6
# define MAX_COLS 36
# define WIDTH 2176
# define HEIGHT 384
# define MAX_COINS 5

void	collect_object(t_data *data);
void	exit_game(t_data *data);
int		all_coins_collected(t_data *data);
int		game_loop(t_data *data);
void	read_map_from_file(char *filename, t_GameMap *game_map);
void	allocate_map_memory(t_GameMap *game_map);
void	free_map_memory(t_GameMap *game_map);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	draw_map(t_data *data);
void	player_up(t_data *data);
void	player_down(t_data *data);
void	player_right(t_data *data);
void	player_left(t_data *data);
void	save_player_pos(t_data *data, int i, int j);
int		check_sign(t_data *data);
int		check_size(t_data *data);
int		check_walls(t_data *data);
int		check_count(t_data *data);
int		check_map(t_data *data);
void	free_image(t_data *data);
void	free_texture(t_data *data);
int		error_message(char *message, int boolean);
void	free_wall(t_data *data);
void	free_all(t_data *data, char *message, int boolean);
int		ft_check_format(t_data *data);
int		malloc_data(t_data **data);
void	break_wall(t_data *data, int x, int y);
int		is_outer_wall(t_data *data, int x, int y);
void	free_data(t_data **data);
void	my_close_hook(void *param);
void	key_hook(void *param);
void	handle_special_keys(t_data *data);
void	handle_movement_keys(t_data *data);
void	load_textures(t_data *data);
void	draw_player(t_data *data);
void	load_last(t_data *data);
void	main_finish(t_data *data);
void	mlx_inisializer(t_data *data);
void	main_test(t_data *data);
void	free_extention_file(t_data *data);
#endif