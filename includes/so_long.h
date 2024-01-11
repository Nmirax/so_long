/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:41:33 by abakhaev          #+#    #+#             */
/*   Updated: 2024/01/11 14:13:47 by abakhaev         ###   ########.fr       */
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

typedef enum e_Direction 
{
    UP,
    DOWN,
    LEFT,
    RIGHT
} t_Direction;

typedef struct s_Player 
{
    int x;
    int y;
    t_Direction direction;

} t_Player;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*textures[8];
    void        *images[8];
	t_GameMap	*map;
	t_Player	player;
}	t_data;



#define MAX_ROWS 6
#define MAX_COLS 36
#define NUM_TEXTURES 3
#define WIDTH 1296
#define HEIGHT 186

void	replace_current_position_with_wall(t_data *data);
void	handle_collectables_and_exits(t_data *data);
void	collect_object(t_data *data);
void	exit_game(t_data *data);
int		all_coins_collected(t_data *data);
int		is_valid_move(t_data *data);
int		is_valid_map(t_data *data);
void	key_hook (void *param);
int		game_loop(t_data *data);
int     load_textures(t_data *data);
void	draw_textures(t_data *data);
void    draw_textures2(t_data *data);
void 	read_map_from_file(char *filename, t_GameMap *game_map);
void	allocate_map_memory(t_GameMap *game_map);
void	*free_map_memory(t_GameMap *game_map);
void 	free_textures(t_data *data);
int		has_ber_extention(const char *filename);
int     *choose_player_texture(t_data *data);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void    refresh_window(void *param);
int     display_image(t_data *data);
#endif