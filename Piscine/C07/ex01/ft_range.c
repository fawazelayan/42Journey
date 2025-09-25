/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 23:14:55 by felayan           #+#    #+#             */
/*   Updated: 2024/07/31 23:34:59 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*arr;

	i = 0;
	arr = NULL;
	if (min >= max)
		return (NULL);
	arr = malloc(sizeof(int) * (max - min));
	if (!arr)
		return (NULL);
	while (min < max)
		arr[i++] = min++;
	return (arr);
}
// MAIN IS ONLY ADDED FOR TESTING, DO NOT PUSH IT TO PROJECT REPO AT CAMPUS
// #include<stdio.h>
// int	main(void)
// {
// 	int	i = 0;
// 	int	min = 0 , max = 10;
// 	int	*arr = ft_range(min, max);
// 	if (!arr)
// 		return (1);
// 	printf("The range from min to (max - 1)\n\t");
// 	while (i < (max - min))
// 		printf("%d ", arr[i++]);
// 	printf("\n");
// 	free(arr);
// 	return (0);
// }