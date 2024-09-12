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

//#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	sort;

	while (size >= 0)
	{
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] >= tab[i + 1])
			{
				sort = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = sort;
			}
			i++;
		}
		size--;
	}
}
/*
int	main(void)
{
	int	arr[5] = {25, 100, 4, 4, 4};
	int	i = 0;
	ft_sort_int_tab(arr, 5);
	while (i < 5)
	{
		printf(" %i", arr[i]);
		i++;
	}
}
*/
