/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:05:19 by abakhaev          #+#    #+#             */
/*   Updated: 2024/07/15 11:49:07 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/stat.h>
# include <fcntl.h>

# define WIDTH 2560
# define HEIGHT 1440

typedef struct s_collectible
{
	int		x;
	int		y;
	bool	collected;
}	t_collectible;

typedef struct s_wall
{
	int		x;
	int		y;
}	t_wall;

typedef struct s_exit
{
	int		x;
	int		y;
}	t_exit;

typedef struct s_data
{
	char			*mapname;
	char			**map;
	int				map_size;
	int				count_line;
	int				map_exit;
	int				collectible_count;
	int				wall_count;
	int				start_pos;
	int				player_pos_x;
	int				player_pos_y;
	void			*mlx_ptr;
	void			*win_ptr;
	mlx_image_t		**image_bg;
	mlx_image_t		**image_wall;
	mlx_image_t		**image_collectible;
	mlx_image_t		**image_player;
	mlx_image_t		**image_exit;
	mlx_texture_t	**texture_player;
	mlx_texture_t	**texture_bg;
	mlx_texture_t	**texture_exit;
	mlx_texture_t	**texture_collectible;
	mlx_texture_t	**texture_wall;
	t_collectible	*collectible;
	t_wall			*wall;
	t_exit			*exit;
	int				index;
	int				count;
	int				moove_count;
	int				collected;
}				t_data;

int		ft_open_map(t_data *data);
void	ft_copy_map(t_data *data);
int		ft_check_map(t_data *data);
int		ft_check_size(t_data *data);
int		ft_check_sign(t_data *data);
int		ft_check_count(t_data *data);
int		ft_check_walls(t_data *data);
int		ft_check_format(t_data *data);
void	ft_save_player_pos(t_data *data, int i, int j);
void	ft_save_collectible_pos(t_data *data);
int		ft_flood_fill(char	**map, int x, int y, int *items);
int		ft_error_message(char *message, int boolean);
int		ft_load_texture(t_data *data);
int		ft_load_image(t_data *data);
int		ft_map_size(t_data *data);
int		ft_load_png(t_data *data);
int		ft_texture_to_image(t_data *data);
int		ft_bg_image(t_data *data);
int		ft_collectible_image(t_data *data);
int		ft_wall_image(t_data *data);
int		ft_exit_image(t_data *data);
int		ft_player_image(t_data *data);
int		ft_display_image(t_data *data);
void	ft_count_wall(t_data *data);
void	ft_save_wall_pos(t_data *data);
void	ft_save_exit_pos(t_data *data);
int		ft_display_bg(t_data *smain);
int		ft_display_collectible(t_data *smain);
int		ft_display_exit(t_data *smain);
int		ft_display_wall(t_data *smain);
void	my_keyhook(mlx_key_data_t keydata, void *param);
void	my_close_hook(void *param);
void	ft_player_up(t_data *data);
void	ft_player_down(t_data *data);
void	ft_player_left(t_data *data);
void	ft_player_right(t_data *data);
void	ft_display_item(void *param);
void	ft_free_all(t_data *data, char *message, int boolean);
void	ft_free_map(t_data *data);
void	ft_free_image(t_data *data);
void	ft_free_texture(t_data *data);
void	ft_free_wall(t_data *data);
#endif