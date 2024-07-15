/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:56:22 by abakhaev          #+#    #+#             */
/*   Updated: 2024/07/15 11:43:03 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_getsize(unsigned int n)
{
	size_t	size;

	size = 0;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static char	*ft_filltab(int dst_size, int i, char *dst, long int num)
{
	dst[dst_size] = '\0';
	while (dst_size > i)
	{
		dst_size--;
		dst[dst_size] = (num % 10) + '0';
		num = num / 10;
	}
	return (dst);
}

char	*ft_itoa_unsigned(unsigned int n)
{
	int			dst_size;
	char		*dst;
	int			i;
	long int	num;

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
