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

	i = 0;
	arr = NULL;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	arr = malloc(sizeof(int) * (max - min));
	if (!arr)
	{
		*range = NULL;
		return (-1);
	}
	while (i < (max - min))
	{
		arr[i] = min + i;
		i++;
	}
	*range = arr;
	return (max - min);
}
// MAIN IS ONLY ADDED FOR TESTING, DO NOT PUSH IT TO PROJECT REPO AT CAMPUS
// #include <stdio.h>
// int main()
// {
// 	int	i;
// 	int min = 0, max = 10;
// 	int *range;
// 	int	range_size;

// 	i = 0;
// 	range_size = ft_ultimate_range(&range, min, max);
// 	if (!range)
// 		return (1);
// 	printf("The range from min to (max - 1)\n\t");
// 	while (i < (max - min))
// 		printf("%d ", range[i++]);
// 	printf("\nThe range size is: %d\n", range_size);
// 	free (range);
// }