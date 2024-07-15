/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:55:33 by abakhaev          #+#    #+#             */
/*   Updated: 2024/07/15 11:42:44 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_getsize(unsigned int n)
{
	size_t	size;

	size = 0;
	while (n != 0)
	{
		n = n / 16;
		size++;
	}
	return (size);
}

static char	*ft_filltab(long dst_size, int i, char *dst, unsigned int num)
{
	dst[dst_size] = '\0';
	while (dst_size > i)
	{
		dst_size--;
		dst[dst_size] = "0123456789ABCDEF" [num % 16];
		num = num / 16;
	}
	return (dst);
}

char	*ft_itoa_hex(unsigned int n)
{
	long			dst_size;
	char			*dst;
	int				i;
	unsigned int	num;

	num = n;
	dst_size = ft_getsize(n);
	i = 0;
	if (dst_size == 0)
		dst_size++;
	dst = malloc((dst_size + 1) * sizeof(char));
	if (dst == NULL)
		return (NULL);
	return (ft_filltab(dst_size, i, dst, num));
}
