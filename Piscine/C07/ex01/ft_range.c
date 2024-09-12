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
	int	j;
	int	*arr;

	if (min >= max)
		return (0);
	j = 0;
	arr = (int *)malloc((max - min) * 4);
	if (!arr)
		return (0);
	while (j < (max - min))
	{
		arr[j] = min + j;
		j++;
	}
	return (arr);
}
/*#include<stdio.h>
int	main(void)
{
	int	i = 0;
	int	min = -10,max = -9;
	int	*arr = ft_range(min, max);
	
	if (!arr)
		return (0);
	while (i < (max - min))
	{
		printf("%d", arr[i]);
		i++;
	}
	free (arr);
	return (0);
}
*/
