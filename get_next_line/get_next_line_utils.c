/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:47:06 by abakhaev          #+#    #+#             */
/*   Updated: 2024/07/15 10:47:11 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoins(char *stock, char *buffer)
{
	size_t		i;
	size_t		j;
	char		*out;

	if (!stock)
	{
		stock = malloc(sizeof(char) * 1);
		stock[0] = '\0';
	}
	if (!buffer)
		return (NULL);
	out = malloc((ft_strlen(stock) + ft_strlen(buffer) + 1) * sizeof(char));
	if (out == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (stock[i] != '\0')
		out[j++] = stock[i++];
	free(stock);
	i = 0;
	while (buffer[i] != '\0')
		out[j++] = buffer[i++];
	out[j] = '\0';
	return (out);
}

char	*ft_strchr(const char *str, int tofind)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0' && str[i] != (char)tofind)
	{
		i++;
	}
	if (str[i] == (char)tofind)
	{
		return ((char *)&str[i]);
	}
	else
		return ((char *) NULL);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
