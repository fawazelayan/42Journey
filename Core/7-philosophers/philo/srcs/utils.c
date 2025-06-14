/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:14:47 by felayan           #+#    #+#             */
/*   Updated: 2025/06/14 15:14:48 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_error(char *error)
{
	write(2, "\nError: ", 8);
	write(2, error, ft_strlen(error));
	write(2, "\n", 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

long	custom_ft_atol(char *str)
{
	long	num;
	int		i;

	i = 0;
	num = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (num > (LONG_MAX - (str[i] - '0')) / 10)
			return (-1);
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num);
}
