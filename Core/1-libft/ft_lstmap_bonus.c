/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 04:26:15 by felayan           #+#    #+#             */
/*   Updated: 2024/09/13 04:55:09 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*node;
	void	*con;

	if (!lst || !f || !del)
		return (NULL);
	new = NULL;
	while (lst)
	{
		con = f(lst -> content);
		node = ft_lstnew(con);
		if (!node)
		{
			if (con)
				del(con);
			ft_lstclear(&new, del);
		}
		ft_lstadd_back(&new, node);
		lst = lst -> next;
	}
	return (new);
}
