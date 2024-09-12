/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 00:30:25 by felayan           #+#    #+#             */
/*   Updated: 2024/09/12 03:09:53 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	numl(long n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

void	fills(long n, char *p)
{
	size_t	i;

	i = numl(n) - 1;
	p[i + 1] = '\0';
	if (n == 0)
		p[0] = '0';
	else
	{
		while (n)
		{
			p[i] = n % 10 + '0';
			n /= 10;
			i--;
		}
	}
}

char	*ft_itoa(int n)
{
	long	nm;
	char	*nms;

	nm = n;
	nms = malloc(numl(nm) + 1);
	if (!nms)
		return (NULL);
	if (n < 0)
	{
		nms[0] = '-';
		if (n == -2147483648)
		{
			nms[1] = '2';
			nm = 147483648;
			fills(nm, nms + 2);
		}
		else
		{
			nm *= -1;
			fills(nm, nms + 1);
		}
	}
	else if (n >= 0)
		fills(nm, nms);
	return (nms);
}
/*
#include <stdio.h>
int main()
{
	char *s = ft_itoa(0);
	printf("%s\n", s);
}*/
