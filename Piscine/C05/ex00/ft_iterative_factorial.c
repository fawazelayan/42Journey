/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 23:47:23 by felayan           #+#    #+#             */
/*   Updated: 2024/07/31 00:00:45 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_iterative_factorial(int nb)
{
	int	i;
	int	fact;

	i = 1;
	fact = 1;
	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (1);
	while (i <= nb)
		fact *= i++;
	return (fact);
}
// MAIN IS ONLY ADDED FOR TESTING, DO NOT PUSH IT TO PROJECT REPO AT CAMPUS
// #include <stdio.h>
// int	main(void)
// {
// 	printf("Fact of 5: %d\n", ft_iterative_factorial(5));
// 	printf("Fact of 0: %d\n", ft_iterative_factorial(0));
// 	printf("Fact of 1: %d\n", ft_iterative_factorial(1));
// 	printf("Fact of -1: %d Invalid\n", ft_iterative_factorial(-1));
// 	printf("Fact of 10: %d\n", ft_iterative_factorial(10));
// }