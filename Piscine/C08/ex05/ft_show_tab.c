/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 21:55:56 by felayan           #+#    #+#             */
/*   Updated: 2024/08/07 22:19:52 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	str(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	write(1, s, i);
}

void	size(int nb)
{
	long	i;
	char	sizee[10];

	i = 0;
	while (nb > 0)
	{
		sizee[i] = nb % 10 + '0';
		nb /= 10;
		i++;
	}
	while (i > 0)
	{
		write (1, &sizee[i - 1], 1);
		i--;
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != 0)
	{
		str(par[i].str);
		str("\n");
		size(par[i].size);
		str("\n");
		str(par[i].copy);
		str("\n");
		i++;
	}
}
