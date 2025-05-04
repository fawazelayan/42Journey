/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 03:13:05 by felayan           #+#    #+#             */
/*   Updated: 2025/05/02 03:13:06 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (stack -> size < 2)
		return (1);
	first = stack -> top;
	second = first -> next;
	first -> next = second -> next;
	if (second -> next)
		second -> next -> prev = first;
	second -> prev = NULL;
	second -> next = first;
	first -> prev = second;
	stack -> top = second;
	if (stack -> size == 2)
		stack -> bot = first;
	return (0);
}

void	sa(t_stack *a)
{
	if (swap(a))
		return ;
	ft_printf("sa\n");
}

void	sb(t_stack *b)
{
	if (swap(b))
		return ;
	ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	if (swap(a) || swap(b))
		return ;
	ft_printf("ss\n");
}
