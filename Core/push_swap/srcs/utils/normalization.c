/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 21:43:33 by felayan           #+#    #+#             */
/*   Updated: 2025/05/02 21:43:34 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	partition(int *arr, int left, int right)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[right];
	i = left - 1;
	j = left;
	while (j < right)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap_numbers(&arr[i], &arr[j]);
		}
		j++;
	}
	swap_numbers(&arr[i + 1], &arr[j]);
	return (i + 1);
}

void	arr_quicksort(int *arr, int left, int right)
{
	int	pivot;

	pivot = 0;
	if (right <= left)
		return ;
	pivot = partition(arr, left, right);
	arr_quicksort(arr, left, pivot - 1);
	arr_quicksort(arr, pivot + 1, right);
}

int	binary_search(int *arr, int number, int size)
{
	int	left;
	int	right;
	int	mid;

	left = 0;
	right = size - 1;
	mid = 0;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (arr[mid] == number)
			return (mid);
		else if (arr[mid] > number)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return (-1);
}

void	normalize(t_stack *a)
{
	int		*arr;
	int		i;
	t_node	*current;

	i = 0;
	arr = malloc(sizeof(int) * a -> size);
	if (!arr)
		clean_and_exit(&a, EXIT_FAILURE);
	current = a -> top;
	while (current)
	{
		arr[i++] = current -> data;
		current = current -> next;
	}
	arr_quicksort(arr, 0, a -> size - 1);
	current = a -> top;
	while (current)
	{
		i = binary_search(arr, current -> data, a -> size);
		current -> data = i;
		current = current -> next;
	}
	free(arr);
}
