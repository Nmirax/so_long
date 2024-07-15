/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:36:01 by abakhaev          #+#    #+#             */
/*   Updated: 2023/11/27 11:42:03 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_start;
	const unsigned char	*src_start;

	if (!dest && !src)
		return (dest);
	if (dest == src)
		return (dest);
	dest_start = (unsigned char *)dest;
	src_start = (const unsigned char *)src;
	if (dest > src)
	{
		while (n--)
			*(dest_start + n) = *(src_start + n);
	}
	else
	{
		while (n--)
			*(dest_start++) = *(src_start++);
	}
	return (dest);
}
