/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:45:06 by abakhaev          #+#    #+#             */
/*   Updated: 2024/01/25 15:45:45 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

// void load_textures(t_data data)

// 	xpm_t* xpm = mlx_load_xpm42("./src/coins.xpm42");
//        if (!xpm)
//         error(); 