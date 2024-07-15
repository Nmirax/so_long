/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:47:21 by abakhaev          #+#    #+#             */
/*   Updated: 2024/07/15 10:47:45 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_clear_stock(char *stock)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (stock[i] != '\0' && stock[i] != '\n')
		i++;
	if (!stock[i])
	{
		free(stock);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(stock) - i + 1));
	if (str == NULL)
		return (NULL);
	i++;
	while (stock[i] != '\0')
		str[j++] = stock[i++];
	str[j] = '\0';
	free(stock);
	return (str);
}

char	*ft_get_line(char *stock)
{
	int		index;
	char	*str;

	index = 0;
	if (stock[index] == '\0')
		return (NULL);
	while (stock[index] != '\0' && stock[index] != '\n')
		index++;
	str = malloc((index + 2) * sizeof(char));
	if (!str)
		return (NULL);
	index = 0;
	while (stock[index] != '\0' && stock[index] != '\n')
	{
		str[index] = stock[index];
		index ++;
	}
	if (stock[index] == '\n')
	{
		str[index] = '\n';
		index++;
	}
	str[index] = '\0';
	return (str);
}

char	*ft_read_and_copy(int fd, char *stock)
{
	char	*buffer;
	int		read_size;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	read_size = 1;
	while (!(ft_strchr(stock, '\n')) && read_size != 0)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size == -1)
		{
			free(buffer);
			free(stock);
			return (NULL);
		}
		buffer[read_size] = '\0';
		stock = ft_strjoins(stock, buffer);
	}
	free(buffer);
	return (stock);
}

char	*get_next_line(int fd)
{
	static char	*stock = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stock = ft_read_and_copy(fd, stock);
	if (!stock)
		return (NULL);
	line = ft_get_line(stock);
	stock = ft_clear_stock(stock);
	return (line);
}
