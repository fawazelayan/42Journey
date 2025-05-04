/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 20:53:15 by felayan           #+#    #+#             */
/*   Updated: 2025/05/01 20:53:19 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  ========================  */
/*		   DEFINITIONS		  */
/*  ========================  */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*  ========================  */
/*			INCLUDES		  */
/*  ========================  */
# include <limits.h>
# include "libft.h"
# include "ft_printf.h"

/*  ========================  */
/*		   STRUCTURES		  */
/*  ========================  */
typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;
typedef struct s_stack
{
	t_node	*top;
	t_node	*bot;
	int		size;
}	t_stack;

/*  ========================  */
/*		VALIDATION FUNCS	  */
/*  ========================  */
int		validate_arguments(int argc, char **argv);
int		*create_array(int argc, char **argv);
int		is_duplicate(int argc, int *arr);
int		is_number(int argc, char **argv);

/*  ========================  */
/*		  HELPER FUNCS		  */
/*  ========================  */
void	clean_and_exit(t_stack **a, int status);
void	swap_numbers(int *a, int *b);
void	error_output(void);
int		safe_atoi(const char *str, int *num);
int		find_index(t_stack *stack, int num);
int		is_sorted(t_stack *stack);
int		find_min(t_stack *stack);
int		find_max(t_stack *stack);
int		get_bits(t_stack *a);

/*  ========================  */
/*		  STACK FUNCS		  */
/*  ========================  */
int		fill_stack(t_stack *stack, int argc, char **argv);
int		push(t_stack *stack, int value);
void	clear_stack(t_stack **stack);
void	sort_stack(t_stack *a);
t_stack	*init_stack(void);
t_node	*init_node(void);

/*  ========================  */
/*		SWAP OPERATIONS		  */
/*  ========================  */
int		swap(t_stack *stack);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

/*  ========================  */
/*		PUSH OPERATIONS		  */
/*  ========================  */
int		push_src_dest(t_stack *src, t_stack *dest);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

/*  ========================  */
/*	   ROTATION OPERATIONS	  */
/*  ========================  */
int		reverse_rotate(t_stack *stack);
int		rotate(t_stack *stack);
void	rrr(t_stack *a, t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rra(t_stack *a);
void	rb(t_stack *b);
void	rrb(t_stack *a);

/*  ========================  */
/*		 SORTING FUNCS		  */
/*  ========================  */
void	sort_four_five(t_stack *a, t_stack *b);
void	radix_sort(t_stack *a, t_stack *b);
void	sort_three(t_stack *a);
void	sort_algo(t_stack *a);
void	sort_two(t_stack *a);

/*  ========================  */
/*	  NORMALIZATION FUNCS	  */
/*  ========================  */
int		binary_search(int *arr, int number, int size);
int		partition(int *arr, int left, int right);
void	arr_quicksort(int *arr, int left, int right);
void	normalize(t_stack *a);

#endif