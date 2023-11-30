/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:36:29 by abakhaev          #+#    #+#             */
/*   Updated: 2023/11/30 18:27:19 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static mlx_image_t	*g_image;

void	initialize_game(void)
{
}

void	read_map(const char *filename)
{
	int		fd;
	int		col;
	int		row;
	char	buffer;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}
	row = 0;
	col = 0;
	while (read(fd, &buffer, 1) > 0)
	{
		if (buffer == '\n')
		{
			row++;
		}
		else
		}
		if (row >= MAX_COLS || col >= MAX_COLS)
		{
			printf("Error: Too many rows or columns in the map.\n");
			exit(EXIT_FAILURE);
		}

		t_GameMap->map[row][col] = buffer;
		col++;
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
	int	main(void)
	{
	t_position	my_position;
	my_position.x = 10;
	my_position.y = 20;
	ft_printf("Position : x = %d, y = %d\n", my_position.x, my_position.y);
	return (0);
}

