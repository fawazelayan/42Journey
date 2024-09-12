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

//#include  <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	arrs;

	i = 0;
	while (i < (size / 2))
	{
		arrs = tab[i];
		tab[i] = tab[size - i - 1];
		tab[size - i - 1] = arrs;
		i++;
	}
}
/*
int	main(void)
{
	int	i = 0;
	int	arr[5] = {1, 2, 3, 4, 5};
	ft_rev_int_tab(arr, 5);
	while (i < 5)
	{
		printf("%i", arr[i]);
		i++;
	}
}
*/	
