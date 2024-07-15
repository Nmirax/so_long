/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:00:29 by abakhaev          #+#    #+#             */
/*   Updated: 2024/07/15 11:46:59 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_player_up(t_data *s)
{
	s->index = 0;
	while (s->index < s->wall_count)
	{	
		if (((s->player_pos_y - 1) == s->wall[s->index].y)
			&& (s->player_pos_x == s->wall[s->index].x))
			return ;
		s->index++;
	}
	s->image_player[0]->instances[0].y -= 64;
	s->player_pos_y--;
	ft_printf("you mooved %d times\n", s->moove_count++);
	ft_display_item(s);
	return ;
}

void	ft_player_down(t_data *s)
{
	s->index = 0;
	while (s->index < s->wall_count)
	{	
		if (((s->player_pos_y + 1) == s->wall[s->index].y)
			&& (s->player_pos_x == s->wall[s->index].x))
		{
			return ;
		}
		s->index++;
	}
	s->image_player[0]->instances[0].y += 64;
	s->player_pos_y++;
	ft_printf("you mooved %d times\n", s->moove_count++);
	ft_display_item(s);
	return ;
}

void	ft_player_right(t_data *s)
{
	s->index = 0;
	while (s->index < s->wall_count)
	{	
		if (((s->player_pos_x + 1) == s->wall[s->index].x)
			&& (s->player_pos_y == s->wall[s->index].y))
		{
			return ;
		}
		s->index++;
	}
	s->image_player[0]->instances[0].x += 64;
	s->player_pos_x++;
	ft_printf("you mooved %d times\n", s->moove_count++);
	ft_display_item(s);
	return ;
}

void	ft_player_left(t_data *s)
{
	s->index = 0;
	while (s->index < s->wall_count)
	{	
		if (((s->player_pos_x - 1) == s->wall[s->index].x)
			&& (s->player_pos_y == s->wall[s->index].y))
		{
			return ;
		}
		s->index++;
	}
	s->image_player[0]->instances[0].x -= 64;
	s->player_pos_x--;
	ft_printf("you mooved %d times\n", s->moove_count++);
	ft_display_item(s);
	return ;
}
