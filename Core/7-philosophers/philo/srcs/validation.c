/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:14:10 by felayan           #+#    #+#             */
/*   Updated: 2025/06/14 15:14:11 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isempty(char *str)
{
	if (!str || !ft_strlen(str))
		return (1);
	return (0);
}

int	ft_isnumber(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	invalid_args(char **args)
{
	int	i;

	i = 1;
	while (args[i])
	{
		if (ft_isempty(args[i]) || !ft_isnumber(args[i]))
			return (1);
		i++;
	}
	return (0);
}

int	validation(int ac, char **av)
{
	if (ac < 5 || ac > 6)
	{
		print_error("wrong number of arguments.");
		return (1);
	}
	else if (invalid_args(av))
	{
		print_error("argument must be a positive number.");
		return (1);
	}
	return (0);
}
