/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_and_copy_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:10:45 by abakhaev          #+#    #+#             */
/*   Updated: 2024/07/25 13:10:26 by abakhaev         ###   ########.fr       */
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

void	ft_init_and_open_map(t_data *data, int *fd)
{
	data->index = 0;
	*fd = open(data->mapname, O_RDONLY);
	if (*fd == -1)
		ft_free_all(data, "File open error", 1);
	data->map = ft_calloc((data->count_line + 1), sizeof(char *));
	if (!data->map)
	{
		close(*fd);
		ft_free_all(data, "Malloc error", 1);
	}
	data->count_line = 0;
}

void	ft_read_and_fill_map(t_data *data, int fd)
{
	char	*line;

	data->index = 0;
	data->count_line = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (data->count_line == 0 || line)
		{
			data->map[data->index] = ft_strdup(line);
			if (!data->map[data->index])
			{
				free(line);
				close(fd);
				ft_free_all(data, "ft_strdup error", 1);
			}
			data->index++;
			data->count_line++;
		}
		free(line);
		line = get_next_line(fd);
	}
	data->map[data->index] = NULL;
	close(fd);
}

void	ft_copy_map(t_data *data)
{
	int		fd;

	ft_init_and_open_map(data, &fd);
	ft_read_and_fill_map(data, fd);
}
