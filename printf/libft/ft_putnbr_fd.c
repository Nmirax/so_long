/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:44:16 by abakhaev          #+#    #+#             */
/*   Updated: 2023/11/14 20:07:42 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;
	char			c;

	if (n < 0)
	{
		write(fd, "-", 1);
		nb = -n;
	}
	else
	{
		nb = n;
	}
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
	}
	c = nb % 10 + '0';
	write(fd, &c, 1);
}
