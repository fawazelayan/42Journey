/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 03:49:06 by felayan           #+#    #+#             */
/*   Updated: 2024/07/20 05:03:41 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_n(long x, char *s)
{
	int	i;

	i = 0;
	while (x > 0)
	{
		s[i++] = '0' + x % 10;
		x /= 10;
	}
	while (i > 0)
		write(1, &s[--i], 1);
}

void	ft_putnbr(int n)
{
	char	s[10];
	long	numbe;

	numbe = n;
	if (numbe == 0)
		write(1, "0", 1);
	else if (numbe > 0)
		write_n(numbe, s);
	else if (n < 0)
	{
		numbe *= -1;
		write(1, "-", 1);
		if (n == -2147483648)
			write(1, "2147483648", 10);
		else
			write_n(numbe, s);
	}
}
/*
int	main(void)
{
	int	x;

	scanf("%i", &x);
	ft_putnbr(x);
}
*/
