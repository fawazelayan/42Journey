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

	fact = nb;
	i = 1;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	while (i < nb)
	{
		fact *= i;
		i++;
	}
	return (fact);
}
/*#include <stdio.h>
int	main(void)
{
	printf("Fact of 5:%d", ft_iterative_factorial(5));
	printf("\nFact of 0:%d", ft_iterative_factorial(0));
	printf("\nFact of 1:%d", ft_iterative_factorial(1));
	printf("\nFact of -1:INVALID: %d", ft_iterative_factorial(-1));
	printf("\nFact of 10:%d", ft_iterative_factorial(10));
	printf("\n");
}
*/
