/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 07:55:48 by felayan           #+#    #+#             */
/*   Updated: 2024/07/22 08:12:43 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < (size / 2))
	{
		ft_swap(&tab[i], &tab[size - i - 1]);
		i++;
	}
}
// MAIN IS ONLY ADDED FOR TESTING, DO NOT PUSH IT TO PROJECT REPO AT CAMPUS
// #include <stdio.h>
// int	main(void)
// {
// 	int	i = 0;
// 	int	arr[5] = {1, 2, 3, 4, 5};
// 	printf("Array before reversing: ");
// 	while (i < 5)
// 		printf("%d ", arr[i++]);
// 	ft_rev_int_tab(arr, 5);
// 	i = 0;
// 	printf("\nArray after reversing: ");
// 	while (i < 5)
// 		printf("%d ", arr[i++]);
// 	printf("\n");
// }