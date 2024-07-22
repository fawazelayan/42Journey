/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 07:15:52 by felayan           #+#    #+#             */
/*   Updated: 2024/07/22 07:49:35 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;

	if (*b != 0)
	{
		div = *a / *b;
		mod = *a % *b;
		*a = div;
		*b = mod;
	}
}

/*int	main(void)
{
	int	a = 5;
	int	b = 6;
	int	*p1 = &a;
	int	*p2 = &b;
	ft_ultimate_div_mod(p1, p2);
	printf("%i", a);
	printf("%i", b);
}
*/
