/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 17:29:49 by felayan           #+#    #+#             */
/*   Updated: 2025/05/02 17:29:50 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *stack)
{
	if (stack -> top -> data > stack -> bot -> data)
		sa(stack);
}

void	sort_three(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack -> top;
	if (tmp -> data == find_min(stack))
	{
		sa(stack);
		ra(stack);
	}
	else if (tmp -> data != find_min(stack)
		&& stack -> bot -> data == find_max(stack))
		sa(stack);
	else if (tmp -> data != find_max(stack)
		&& stack -> bot -> data == find_min(stack))
		rra(stack);
	else if (tmp -> data == find_max(stack)
		&& stack -> bot -> data != find_min(stack))
		ra(stack);
	else
	{
		ra(stack);
		sa(stack);
	}
}

void	sort_four_five(t_stack *a, t_stack *b)
{
	int	i;
	int	min;

	i = 0;
	min = 0;
	while (a -> size != 3)
	{
		min = find_min(a);
		i = find_index(a, min);
		while (a -> top -> data != min)
		{
			if (i < a-> size / 2)
				ra(a);
			else
				rra(a);
		}
		pb(a, b);
	}
	if (!is_sorted(a))
		sort_three(a);
	while (b -> size)
		pa(a, b);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	int	bits;

	i = 0;
	j = 0;
	bits = get_bits(a);
	while (i < bits)
	{
		j = a -> size;
		while (j)
		{
			if (((a -> top -> data >> i) & 1) == 0)
				pb(a, b);
			else
				ra(a);
			j--;
		}
		while (b -> size)
			pa(a, b);
		i++;
	}
}

void	sort_algo(t_stack *a)
{
	t_stack	*b;

	b = init_stack();
	if (!b)
		clean_and_exit(&a, EXIT_FAILURE);
	if (a -> size == 4 || a -> size == 5)
		sort_four_five(a, b);
	else
	{
		normalize(a);
		radix_sort(a, b);
	}
	clear_stack(&b);
}
