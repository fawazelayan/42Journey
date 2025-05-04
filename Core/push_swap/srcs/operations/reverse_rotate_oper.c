/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_oper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 04:56:37 by felayan           #+#    #+#             */
/*   Updated: 2025/05/02 04:56:44 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rev_rotate(t_stack *stack)
{
	t_node	*tmp;

	if (stack -> size < 2)
		return (1);
	tmp = stack -> bot -> prev;
	stack -> bot -> prev = NULL;
	tmp -> next = NULL;
	stack -> top -> prev = stack -> bot;
	stack -> bot -> next = stack -> top;
	stack -> top = stack -> bot;
	stack -> bot = tmp;
	return (0);
}

void	rra(t_stack *a)
{
	if (rev_rotate(a))
		return ;
	ft_printf("rra\n");
}

void	rrb(t_stack *b)
{
	if (rev_rotate(b))
		return ;
	ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	if (rev_rotate(a) || rev_rotate(b))
		return ;
	ft_printf("rrr\n");
}
