/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:41:33 by abakhaev          #+#    #+#             */
/*   Updated: 2024/02/07 12:40:39 by abakhaev         ###   ########.fr       */
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

typedef struct s_Player 
{
    int x;
    int y;

} t_Player;

typedef struct s_wall
{
	int		x;
	int		y;
}	t_wall;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_GameMap	*map;
	t_Player	player;
    mlx_image_t *droitee;
    mlx_image_t *soll;
    mlx_image_t *murr;
    mlx_image_t *coinss;
    mlx_image_t *escapee;
    mlx_texture_t *droite;
    mlx_texture_t   *escape;
    mlx_texture_t  *sol;
    mlx_texture_t  *mur;
    mlx_texture_t   *coins;
    int             wall_count;
    int     index;
    int     collected_coins;
    t_wall			*wall;
}	t_data;



#define MAX_ROWS 6
#define MAX_COLS 36
#define WIDTH 2176
#define HEIGHT 384


void collect_object(t_data *data);
void	exit_game(t_data *data);
int		all_coins_collected(t_data *data);
void	key_hook (void *param);
int		game_loop(t_data *data);
void 	read_map_from_file(char *filename, t_GameMap *game_map);
void	allocate_map_memory(t_GameMap *game_map);
void	*free_map_memory(t_GameMap *game_map);
int		has_ber_extention(const char *filename);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void    error(void);
void    draw_map(t_data *data);
void    player_up(t_data *data);
void    player_down(t_data *data);
void    player_right(t_data *data);
void    player_left(t_data *data);
#endif