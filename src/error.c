/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:41:36 by abakhaev          #+#    #+#             */
/*   Updated: 2024/02/07 14:59:32 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int error_message(char *message, int boolean)
{
    if(boolean == 1)
        ft_printf("Error\n");
        if (message != NULL)
		ft_printf("%s\n", message);
	return (0);
}

void	ft_free_image(t_data *data)
{
	int	i;

	i = 0;
	while (data->soll && i < data->map_size)
	{
		mlx_delete_image(data->mlx_ptr, data->soll[i]);
		i++;
	}
	free(data->soll);
	i = 0;
	
	while (data->murr && i < data->map_size)
	{
		mlx_delete_image(data->mlx_ptr, data->murr[i]);
		i++;
	}
	free(data->murr);
	while (data->escapee && i < data->map_size)
	{
		mlx_delete_image(data->mlx_ptr, data->escapee[i]);
		i++;
	}
	free(data->escapee);
}