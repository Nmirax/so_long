/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_item.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:00:14 by abakhaev          #+#    #+#             */
/*   Updated: 2024/07/15 11:46:52 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_display_item(void *param)
{
	t_data	*s;
	int		i;

	s = param;
	i = 0;
	while (i < s->collectible_count)
	{
		if ((s->player_pos_x == s->collectible[i].x) && (s->player_pos_y
				== s->collectible[i].y) && s->collectible[i].collected == false)
		{
			s->image_collectible[i]->enabled = false;
			s->collectible[i].collected = true;
			s->collected++;
			return ;
		}
		i++;
	}
	if ((s->player_pos_x == s->exit[0].x) && (s->player_pos_y
			== s->exit[0].y) && (s->collected == s->collectible_count))
	{
		s->moove_count--;
		ft_printf("\n\n\nYou won the game in %d mooves, Congrats !! :D\n\n\n",
			s->moove_count);
		ft_free_all(s, NULL, 0);
	}
}
