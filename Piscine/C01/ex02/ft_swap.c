/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 14:38:58 by felayan           #+#    #+#             */
/*   Updated: 2024/07/22 07:51:40 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
// MAIN IS ONLY ADDED FOR TESTING, DO NOT PUSH IT TO PROJECT REPO AT CAMPUS
// #include <stdio.h>
// int	main(void)
// {
// 	int	x = 2;
// 	int	y = 5;
// 	printf("Before swapping:\n\tX was %d\n\tY was %d\n\n", x, y);
// 	ft_swap(&x, &y);
// 	printf("After swapping:\n\tX is now %d\n\tY is now %d\n\n", x, y);
// }