/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 21:36:14 by felayan           #+#    #+#             */
/*   Updated: 2024/11/29 20:14:16 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	numlen(long n)
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

	len = numlen(n);
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
//