/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 00:33:16 by felayan           #+#    #+#             */
/*   Updated: 2024/09/13 01:36:41 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new -> content = content;
	new -> next = NULL;
	return (new);
}
/*
#include <stdio.h>

int main()
{
    int a = 42;
    int b = 40;

    // Passing addresses of a and b, and casting to void*
    t_list *node1 = ft_lstnew((void *)&a);
    t_list *node2 = ft_lstnew((void *)&b);

    // Linking nodes
    node1->next = node2;

    // Accessing the content of the nodes (need to cast back to int*)
    printf("Node 1 content: %d\n", *(int *)(node1->content));
    printf("Node 2 content: %d\n", *(int *)(node2->content));

    // Freeing memory
    free(node1);
    free(node2);

    return 0;
}*/
