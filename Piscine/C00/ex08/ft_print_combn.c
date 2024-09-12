/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 05:07:51 by felayan           #+#    #+#             */
/*   Updated: 2024/07/20 07:07:40 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_n(char *x, int s, int l)
{
	int	i;

	i = 0;
	if (x[0] == l)
	{
		while (i < s)
			ft_putchar(x[i++]);
		return ;
	}
	while (i < s)
		ft_putchar(x[i++]);
	if ((l + i + '0') != '9')
		write(1, ", ", 2);
}

void	ft_print_combn(int n)
{
	char	num[9];
	char	num_max[9];
	long	i;
	long	ind;
	long	add;

	i = 0;
	while (i <= n)
	{
		num[i] = '0' + i;
		num_max[i] = 10 - n + i + '0';
		i++;
	}
	print_n(num, n, num_max[0]);
	while (num[0] != num_max[0])
	{
		ind = n - 1;
		while (num[ind] == num_max[ind])
			ind--;
		add = ++(num[ind]);
		while (ind < (n - 1))
			num[++ind] = ++add;
		print_n(num, n, num_max[0]);
	}
}
/*
int	main(void)
{
	int	x;

	scanf("%i", &x);
	ft_print_combn(x);
}
*/
