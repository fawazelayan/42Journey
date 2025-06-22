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

static bool	is_empty(char *str)
{
	if (!str || !str_len(str))
		return (true);
	return (false);
}

static bool	is_num(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	if (!str[i])
		return (false);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

static bool	invalid_args(char **args)
{
	int	i;

	i = 1;
	while (args[i])
	{
		if (is_empty(args[i]) || !is_num(args[i]))
			return (true);
		i++;
	}
	return (false);
}

bool	is_valid_prog(int ac, char **av)
{
	if (ac < 5 || ac > 6)
	{
		print_error_ret("wrong number of arguments.");
		return (false);
	}
	else if (invalid_args(av))
	{
		print_error_ret("argument must be a positive number.");
		return (false);
	}
	return (true);
}
