/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:11:14 by abakhaev          #+#    #+#             */
/*   Updated: 2023/11/27 11:43:01 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (dest[i] && i < n)
		i++;
	j = 0;
	while (src[j] && (i + j + 1) < n)
	{
		dest[i + j] = src[j];
		j++;
	}
	if (i != n)
		dest[i + j] = '\0';
	return (i + ft_strlen(src));
}
