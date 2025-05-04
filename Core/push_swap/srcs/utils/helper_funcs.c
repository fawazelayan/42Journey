/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 00:17:49 by felayan           #+#    #+#             */
/*   Updated: 2025/05/04 00:17:49 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_numbers(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	current = stack -> top;
	while (current -> next)
	{
		if (current -> data > current -> next -> data)
			return (0);
		current = current -> next;
	}
	return (1);
}

int	find_index(t_stack *stack, int num)
{
	t_node	*current;
	int		i;

	i = 0;
	current = stack -> top;
	while (current)
	{
		if (current -> data == num)
			return (i);
		current = current -> next;
		i++;
	}
	return (-1);
}

int	find_min(t_stack *stack)
{
	t_node	*tmp;
	int		min;

	tmp = stack -> top;
	min = tmp -> data;
	while (tmp)
	{
		if (tmp -> data < min)
			min = tmp -> data;
		tmp = tmp -> next;
	}
	return (min);
}

int	find_max(t_stack *stack)
{
	t_node	*tmp;
	int		max;

	tmp = stack -> top;
	max = tmp -> data;
	while (tmp)
	{
		if (tmp -> data > max)
			max = tmp -> data;
		tmp = tmp -> next;
	}
	return (max);
}
