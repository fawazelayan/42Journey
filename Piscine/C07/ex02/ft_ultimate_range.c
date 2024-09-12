/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 23:48:19 by felayan           #+#    #+#             */
/*   Updated: 2024/08/01 00:01:59 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*arr;

	if (min >= max)
	{
		range = NULL;
		return (0);
	}
	i = 0;
	arr = (int *)malloc((max - min) * 4);
	if (!arr)
	{
		range = NULL;
		return (-1);
	}
	*range = arr;
	while (i < (max - min))
	{
		arr[i] = min + i;
		i++;
	}
	return (max - min);
}
#include <stdio.h>
int main()
{
	int *range;
	int	size = ft_ultimate_range(&range,3, 5);
	int	i = 0;

	while (i < (5 - 3))
	{
		printf("%d", range[i]);
		printf("\n");
		i++;
	}
	printf("%d", size);
	free (range);
	return (0);
}
