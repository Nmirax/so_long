/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:36:29 by abakhaev          #+#    #+#             */
/*   Updated: 2023/12/04 14:55:18 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static mlx_image_t	*g_image;

void	print_map(const t_GameMap *game_map)
{
	int	i;
	int	j;

	i = 0;
	while (i < game_map->rows)
	{
		j = 0;
		while (j < game_map->cols)
		{
			ft_printf("%c", game_map->map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void	render_frame(t_GameMap *game_map)
{
	mlx_clear_window(g_mlx.mlx_ptr, g_mlx.win_ptr);
	print_map(game_map);
	mlx_put_image_to_window(
		mlx.mlx_ptr,
		win.win_ptr,
		g_image->image_ptr,
		0, 0
);
}

void	allocate_map_memory(t_GameMap *game_map)
{
	int	i;

	game_map->map = (char **)malloc(MAX_COLS * sizeof(char *));
	i = 0;
	while (i < MAX_COLS)
	{
		game_map->map[i] = (char *)malloc(MAX_COLS * sizeof(char));
		i++;
	}
}

void	read_map(const char *filename, t_GameMap *game_map)
{
	int		fd;
	char	buffer;
	int		row;
	int		col;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}
	allocate_map_memory(game_map);
	row = 0;
	col = 0;
	read_map_line(fd, &buffer, game_map);
	game_map->rows = row + 1;
	game_map->cols = col;
	close(fd);
}

void	ft_hook(void *param)
			{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_W))
		g_image->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_S))
		g_image->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_A))
		g_image->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_D))
		g_image->instances[0].x += 5;
}
