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
	return (!str || !str_len(str));
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
		return (print_err_ret("invalid number of arguments", 0));
	else if (invalid_args(av))
		return (print_err_ret("argument must be a positive number.", 0));
	return (true);
}
