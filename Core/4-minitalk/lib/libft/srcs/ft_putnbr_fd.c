/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 02:04:12 by felayan           #+#    #+#             */
/*   Updated: 2024/09/12 02:41:02 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	nml(long n)
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

void	fillst(long n, char *s)
{
	size_t	i;

	i = nml(n);
	s[i] = '\0';
	if (n == 0)
		s[0] = '0';
	else
	{
		while (n)
		{
			s[i - 1] = n % 10 + '0';
			n /= 10;
			i--;
		}
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nm;
	char	s[12];

	nm = n;
	if (n < 0)
	{
		s[0] = '-';
		if (n == -2147483648)
		{
			s[1] = '2';
			nm = 147483648;
			fillst(nm, &s[2]);
		}
		else
		{
			nm *= -1;
			fillst(nm, &s[1]);
		}
	}
	else
		fillst(nm, s);
	ft_putstr_fd(s, fd);
}
/*
int main()
{
	ft_putnbr_fd(-2147483648, 1);
}*/
