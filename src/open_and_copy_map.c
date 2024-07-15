/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_and_copy_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:10:45 by abakhaev          #+#    #+#             */
/*   Updated: 2024/07/15 11:48:41 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_open_map(t_data *data)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open(data->mapname, O_RDONLY);
	if (read(fd, 0, 0) < 0 || fd == -1)
		ft_free_all(data, "Read error", 1);
	while ((line != NULL) || (data->count_line == 0))
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		data->count_line++;
		free(line);
	}
	close(fd);
	ft_copy_map(data);
	return (0);
}

void	ft_copy_map(t_data *data)
{
	int		fd;
	char	*line;

	data->index = 0;
	line = NULL;
	fd = open(data->mapname, O_RDONLY);
	data->map = ft_calloc((data->count_line + 1), sizeof(char *));
	if (!data->map)
		ft_free_all(data, "Malloc error", 1);
	data->map[data->count_line] = NULL;
	data->count_line = 0;
	while ((line != NULL) || (data->count_line == 0))
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		data->map[data->index] = ft_strdup(line);
		data->count_line++;
		data->index++;
		free(line);
	}
	close(fd);
}
