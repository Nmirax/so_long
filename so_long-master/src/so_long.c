/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:36:29 by abakhaev          #+#    #+#             */
/*   Updated: 2023/12/07 14:44:21 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int key_hook(int keycode, t_data *data)
{
	if (keycode == 53) // Touche ESC
		close_window(data);
	else if (keycode == 13)
        
	else if (keycode == 0)
    
	else if (keycode == 2)
    
	else if (keycode == 1)
    
	else if (keycode == 14)
    {
        if (all_coins_collected(data) && exit_game(data, ))
        mlx_close_window(data);
    }