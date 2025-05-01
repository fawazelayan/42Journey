/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 02:13:16 by felayan           #+#    #+#             */
/*   Updated: 2024/09/13 02:42:36 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst -> next;
		i++;
	}
	return (i);
}
/*
int main()
{
	t_list *elem,*elem2,*elem3,*elem4;
	int i = 1;
	char c;
	elem = ft_lstnew(&i);
	elem2 = ft_lstnew(&i);
	elem3 = ft_lstnew(&i);
	elem4 = ft_lstnew(&i);

	elem->next = elem2;
	elem2->next = elem3;
	elem3->next = elem4;
    c = ft_lstsize(elem) + 48;
    write(1, &c, 1);
    write(1, "\n", 1);
    elem->next = NULL;
    c = ft_lstsize(elem) + 48;
    write(1, &c, 1);
    write(1, "\n", 1);
    elem = NULL;
    c = ft_lstsize(elem) + 48;
    write(1, &c, 1);
    write(1, "\n", 1);
    free(elem);
    free(elem2);
    free(elem3);
    free(elem4);
}*/
