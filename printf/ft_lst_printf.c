/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:56:46 by abakhaev          #+#    #+#             */
/*   Updated: 2024/07/15 11:42:51 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print	*ft_lstnew_printf(int size, char *str)
{
	t_print	*newlist;

	newlist = malloc(sizeof(t_print));
	if (newlist == NULL)
		return (NULL);
	newlist->size = size;
	newlist->str = str;
	newlist->next = NULL;
	return (newlist);
}

void	ft_lstadd_back_pf(t_print **lst, t_print *new)
{
	t_print	*temp;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
}

void	ft_lstclear_pf(t_print **lst)
{
	t_print	*temp;
	t_print	*next;

	if (lst == NULL)
		return ;
	temp = *lst;
	while (temp != NULL)
	{
		next = temp->next;
		free(temp->str);
		free(temp);
		temp = next;
	}
	*lst = NULL;
}
