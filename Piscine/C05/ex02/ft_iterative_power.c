/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 00:01:16 by felayan           #+#    #+#             */
/*   Updated: 2024/07/31 00:21:33 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	nbp;

	nbp = nb;
	if (power == 0 || (power == 0 && nb == 0) || nb == 1)
		return (1);
	if (power == 1)
		return (nb);
	if (power < 0)
		return (0);
	while (power-- != 1)
		nbp *= nb;
	return (nbp);
}
/*#include<stdio.h>
int	main(void)
{
	printf("%d", ft_iterative_power(2, 30));
}
*/
