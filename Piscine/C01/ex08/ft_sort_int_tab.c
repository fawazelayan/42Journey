/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 08:13:31 by felayan           #+#    #+#             */
/*   Updated: 2024/07/22 08:40:55 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	swapped;

	while (size > 0)
	{
		i = 0;
		swapped = 0;
		while (i < (size - 1))
		{
			if (tab[i] > tab[i + 1])
			{
				ft_swap(&tab[i], &tab[i + 1]);
				swapped = 1;
			}
			i++;
		}
		size--;
		if (!swapped)
			break ;
	}
}
// MAIN IS ONLY ADDED FOR TESTING, DO NOT PUSH IT TO PROJECT REPO AT CAMPUS
// #include <stdio.h>
// int	main(void)
// {
// 	int	arr[6] = {100, 25, 15, 30, 1, 99};
// 	int	i = 0;
// 	printf("Array before soring: ");
// 	while (i < 6)
// 		printf("%d ", arr[i++]);
// 	ft_sort_int_tab(arr, 6);
// 	i = 0;
// 	printf("\nArray after sorting: ");
// 	while (i < 6)
// 		printf("%d ", arr[i++]);
// 	printf("\n");
// }