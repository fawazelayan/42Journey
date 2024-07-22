/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 15:12:57 by felayan           #+#    #+#             */
/*   Updated: 2024/07/22 07:48:44 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	if (b != 0)
	{
		*div = a / b;
		*mod = a % b;
	}
}
/*
int	main(void)
{
	int	n = 5;
	int	m = 6;
	int	*p1;
	int	*p2;
	p1=&n;
	p2=&m;
	ft_div_mod(n, m, p1, p2);
	printf("%i", n);
	printf("%i", m);
}
*/
