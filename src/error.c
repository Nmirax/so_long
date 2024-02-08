/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:41:36 by abakhaev          #+#    #+#             */
/*   Updated: 2024/02/08 11:54:05 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


int error_message(char *message, int boolean)
{
    if (boolean == 1)
    {
        ft_printf("Error\n");
        if (message != NULL)
            ft_printf("%s\n", message);
        return (0);
    }
    return (1);
}


void	free_all(t_data *data, char *message, int boolean)
{
	free_map_memory(data->map);
	free_texture(data);
	free_image(data);
	error_message(message, boolean);
	exit(0);
}

void	free_image(t_data *data)
{
	int	i;

	i = 0;
	while (data->soll && i < data->map_size)
	{
		mlx_delete_image(data->mlx_ptr, data->soll);
		i++;
	}
	free(data->soll);
	i = 0;
	while (data->coinss && i < data->collectible_count)
	{
		mlx_delete_image(data->mlx_ptr, data->coinss);
		i++;
	}
	free(data->coinss);
	if (data->escapee)
		mlx_delete_image(data->mlx_ptr, data->escapee);
	free(data->escapee);
	if (data->droitee)
		mlx_delete_image(data->mlx_ptr, data->droitee);
	free(data->droitee);
	free_wall(data);
}

void free_texture(t_data *data) 
{
    if (data->droite) 
	{
        mlx_delete_texture(data->droite);
        free(data->droite);
    }
    if (data->coins) 
	{
        mlx_delete_texture(data->coins);
        free(data->coins);
    }
    if (data->mur) 
	{
        mlx_delete_texture(data->mur);
        free(data->mur);
    }
    if (data->soll) 
	{
        mlx_delete_texture(data->sol);
        free(data->sol);
    }
    if (data->escape) 
	{
        mlx_delete_texture(data->escape);
        free(data->escape);
    }
}
