/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:49:00 by felayan           #+#    #+#             */
/*   Updated: 2024/07/30 23:07:45 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	double_check(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	print_num(int nb, int baseval, char *base)
{
	long	num;

	num = nb;
	if (num < 0)
	{
		num *= -1;
		ft_putchar('-');
	}
	if (num >= baseval)
		print_num(num / baseval, baseval, base);
	ft_putchar(base[num % baseval]);
}

void	ft_putnbr_base(int nb, char *base)
{
	int	baseval;

	baseval = 0;
	while (base[baseval] != '\0')
	{
		if (base[baseval] == '-' || base[baseval] == '+')
			return ;
		baseval++;
	}
	if (baseval == 0 || baseval == 1)
		return ;
	if (double_check(base))
		return ;
	print_num(nb, baseval, base);
}
/*
int	main(void)
{
	ft_putnbr_base(0, "0123456-");
}
*/
