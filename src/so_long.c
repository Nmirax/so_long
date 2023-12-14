/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:36:29 by abakhaev          #+#    #+#             */
/*   Updated: 2023/12/14 14:40:11 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


void	update(t_data *data)
{
    is_valid_map(data);
    key_hook(13, data);
    key_hook(2, data);
    key_hook(0, data);
    key_hook(14, data);
    key_hook(1, data);
    is_valid_map(data);
    handle_collectables_and_exits(data);
    exit_game(data);
}

int	game_loop(t_data *data)
{
	while(1)
	{
        update(data);
        draw_textures(data);
		mlx_loop(data->mlx_ptr);
	}
	    mlx_terminate(data->mlx_ptr);
		    return (0);
}

void    initialize_data(t_data *data, char *map_file)
{
   t_GameMap    *game_map;
   
   game_map = data->win_ptr;  
   mlx_init(16, 16, "SO_LONG", true);
    if (!data->map)
    {
        perror("Error create windows");
            exit(EXIT_FAILURE);
    }
    allocate_map_memory(game_map);
    if(!game_map)
    {
        perror("Error allocating memory for game map");
        exit(EXIT_FAILURE);
    }
    read_map_from_file(map_file, data->map);
}


int main(int argc, char *argv[])
{
    t_data data;

    if (argc != 2)
    {
        ft_printf("Usage: %s <map_file.ber>\n", argv[0]);
            return (EXIT_FAILURE);
    }
    initialize_data(&data, argv[1]);
        load_textures(&data);
    
    if (game_loop(&data) == EXIT_FAILURE)
    {
        perror("Error in game loop");
        exit(EXIT_FAILURE);
   }
   free_textures(&data);
   free_map_memory(data.map);
   mlx_terminate(data.mlx_ptr);
    return (EXIT_SUCCESS);
    
}
