/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 03:53:48 by felayan           #+#    #+#             */
/*   Updated: 2024/09/13 04:54:42 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*nextlst;

	nextlst = NULL;
	if (!(*lst) || !lst || !del)
		return ;
	while (*lst)
	{
		nextlst = (*lst)-> next;
		del((*lst)-> content);
		free(*lst);
		*lst = nextlst;
	}
	*lst = NULL;
}
