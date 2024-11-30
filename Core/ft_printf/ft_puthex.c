/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 22:10:56 by felayan           #+#    #+#             */
/*   Updated: 2024/11/29 22:34:45 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	num_len(unsigned long n)
{
	int	len;

	len = 0;
	while (n)
	{
		len++;
		n /= 16;
	}
	return (len);
}

int	fillh(char *s, unsigned long n, char *base)
{
	int	len;
	int	count;

	count = 0;
	if (n == 0)
		return (put_c('0'));
	len = num_len(n);
	s[len] = '\0';
	while (n)
	{
		s[--len] = base[n % 16];
		n /= 16;
	}
	count += put_s(s);
	return (count);
}

int	put_hex(unsigned long n, char c)
{
	char	*base_cap;
	char	*base_sma;
	char	s[18];
	int		count;

	count = 0;
	base_sma = "0123456789abcdef";
	base_cap = "0123456789ABCDEF";
	if (c == 'x')
		count += fillh(s, n, base_sma);
	else
		count += fillh(s, n, base_cap);
	return (count);
}
