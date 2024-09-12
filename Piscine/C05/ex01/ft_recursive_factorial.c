/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 23:56:52 by felayan           #+#    #+#             */
/*   Updated: 2024/07/31 00:00:26 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	return (nb * ft_recursive_factorial(nb - 1));
}
/*#include <stdio.h>
int	main(void)
{
	printf("Fact of 5:%d", ft_recursive_factorial(5));
	printf("\nFact of 0:%d", ft_recursive_factorial(0));
	printf("\nFact of 1:%d", ft_recursive_factorial(1));
	printf("\nFact of -1:INVALID: %d", ft_recursive_factorial(-1));
	printf("\nFact of 10:%d", ft_recursive_factorial(10));
	printf("\n");
}
*/
