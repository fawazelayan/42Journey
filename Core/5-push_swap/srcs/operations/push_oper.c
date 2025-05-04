/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_oper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 04:05:40 by felayan           #+#    #+#             */
/*   Updated: 2025/05/02 04:05:41 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_src_dst(t_stack *src, t_stack *dst)
{
	t_node	*tmp;

	if (!src -> size)
		return (1);
	tmp = src -> top;
	src -> top = tmp -> next;
	if (src -> top)
		src -> top -> prev = NULL;
	else
		src -> bot = NULL;
	tmp -> next = dst -> top;
	if (dst -> top)
		dst -> top -> prev = tmp;
	else
		dst -> bot = tmp;
	dst -> top = tmp;
	src -> size--;
	dst -> size++;
	return (0);
}

void	pa(t_stack *a, t_stack *b)
{
	if (push_src_dst(b, a))
		return ;
	ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	if (push_src_dst(a, b))
		return ;
	ft_printf("pb\n");
}
