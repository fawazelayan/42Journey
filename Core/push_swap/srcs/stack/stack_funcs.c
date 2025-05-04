/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:25:29 by felayan           #+#    #+#             */
/*   Updated: 2025/05/01 21:25:30 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack -> top = NULL;
	stack -> bot = NULL;
	stack -> size = 0;
	return (stack);
}

int	push(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = init_node();
	if (!new_node)
		return (1);
	new_node -> data = value;
	if (!(stack -> top))
	{
		stack -> top = new_node;
		stack -> bot = new_node;
	}
	else
	{
		new_node -> prev = stack -> bot;
		stack -> bot -> next = new_node;
		stack -> bot = new_node;
	}
	stack -> size++;
	return (0);
}

int	fill_stack(t_stack *stack, int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (push(stack, ft_atoi(argv[i])))
			return (1);
		i++;
	}
	return (0);
}

void	sort_stack(t_stack *a)
{
	if (a -> size == 1 || is_sorted(a))
		return ;
	if (a -> size == 2)
		sort_two(a);
	else if (a -> size == 3)
		sort_three(a);
	else
		sort_algo(a);
}

void	clear_stack(t_stack **stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack || !*stack)
		return ;
	current = (*stack)-> top;
	while (current)
	{
		next = current -> next;
		free (current);
		current = next;
	}
	free(*stack);
	*stack = NULL;
}
