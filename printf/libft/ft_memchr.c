/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchrr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:32:58 by abakhaev          #+#    #+#             */
/*   Updated: 2023/11/14 19:33:47 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	if (n != '\0')
		while (n--)
			if (*(unsigned char *)s++ == (unsigned char)c)
				return ((void *)(unsigned char *)s - 1);
	return (NULL);
}
