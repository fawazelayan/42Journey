/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_oper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 04:32:14 by felayan           #+#    #+#             */
/*   Updated: 2025/05/02 04:32:13 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate(t_stack *stack)
{
	t_node	*tmp;

	if (stack -> size < 2)
		return (1);
	tmp = stack -> top -> next;
	tmp -> prev = NULL;
	stack -> top -> next = NULL;
	stack -> top -> prev = stack -> bot;
	stack -> bot -> next = stack -> top;
	stack -> bot = stack -> top;
	stack -> top = tmp;
	return (0);
}

void	ra(t_stack *a)
{
	if (rotate(a))
		return ;
	ft_printf("ra\n");
}

void	rb(t_stack *b)
{
	if (rotate(b))
		return ;
	ft_printf("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	if (rotate(a) || rotate(b))
		return ;
	ft_printf("rr\n");
}
