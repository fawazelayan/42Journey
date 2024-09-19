/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 22:10:56 by felayan           #+#    #+#             */
/*   Updated: 2024/09/19 05:39:26 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	numl(unsigned long n)
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

int	put_x(unsigned long n, char *base)
{
	char	*s;
	int		len;
	int		count;

	if (n == 0)
	{
		put_s("0");
		return (1);
	}
	count = 0;
	len = numl(n);
	s = malloc(len + 1);
	if (!s)
		return (0);
	s[len] = '\0';
	while (n)
	{
		s[--len] = base[n % 16];
		n /= 16;
	}
	count += put_s(s);
	free(s);
	return (count);
}

int	put_xx(unsigned long n, char *base)
{
	char	*s;
	int		len;
	int		count;

	if (n == 0)
	{
		put_s("0");
		return (1);
	}
	count = 0;
	len = numl(n);
	s = malloc(len + 1);
	if (!s)
		return (0);
	s[len] = '\0';
	while (n)
	{
		s[--len] = base[n % 16];
		n /= 16;
	}
	count += put_s(s);
	free(s);
	return (count);
}

int	put_hex(unsigned long n, char c)
{
	char	*base_x;
	char	*base_xx;
	int		count;

	base_x = "0123456789abcdef";
	base_xx = "0123456789ABCDEF";
	if (c == 'x')
		count = put_x(n, base_x);
	else if (c == 'X')
		count = put_xx(n, base_xx);
	return (count);
}
