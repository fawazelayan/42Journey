/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 21:36:14 by felayan           #+#    #+#             */
/*   Updated: 2024/09/19 05:03:27 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	num_len(long n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

void	fill(char *s, long n)
{
	int	len;

	len = num_len(n);
	s[len] = '\0';
	if (n == 0)
		s[0] = '0';
	else
	{
		while (n)
		{
			s[--len] = n % 10 + '0';
			n /= 10;
		}
	}
}

int	put_dec(long n)
{
	char	s[12];

	if (n < 0)
	{
		s[0] = '-';
		fill(&s[1], -n);
	}
	else
		fill(s, n);
	return (put_s(s));
}
