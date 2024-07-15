/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakhaev <abakhaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:33:41 by abakhaev          #+#    #+#             */
/*   Updated: 2023/11/14 19:04:23 by abakhaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)( void *))
{
	t_list	*new;
	t_list	*newel;

	new = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst != NULL)
	{
		newel = malloc(1 * sizeof(t_list));
		if (!newel)
		{	
			ft_lstclear(&new, del);
			return (NULL);
		}
		newel->content = f(lst->content);
		newel->next = NULL;
		ft_lstadd_back(&new, newel);
		lst = lst->next;
	}
	return (new);
}
