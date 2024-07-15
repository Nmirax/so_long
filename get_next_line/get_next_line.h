/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:47:59 by abakhaev          #+#    #+#             */
/*   Updated: 2024/07/15 10:48:03 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*ft_get_line(char *stock);
char	*ft_read_and_copy(int fd, char *str);
char	*ft_clear_stock(char *stock);
char	*ft_strchr(const char *str, int tofind);
char	*ft_strjoins(char *stock, char *buffer);
size_t	ft_strlen(const char *str);

#endif