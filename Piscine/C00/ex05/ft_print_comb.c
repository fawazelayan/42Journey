/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:27:26 by felayan           #+#    #+#             */
/*   Updated: 2024/07/20 05:05:45 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char	dig[3];

	dig[0] = '0';
	while (dig[0] <= '7')
	{
		dig[1] = dig[0] + 1;
		while (dig[1] <= '8')
		{
			dig[2] = dig[1] + 1;
			while (dig[2] <= '9')
			{
				write(1, &dig, 3);
				if (dig[0] != '7')
					write(1, ", ", 2);
				dig[2]++;
			}
			dig[1]++;
		}
		dig[0]++;
	}
}
/*
int	main(void)
{
	ft_print_comb();
	return (0);
}
*/
