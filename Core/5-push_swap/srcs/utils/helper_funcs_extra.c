/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 17:06:23 by felayan           #+#    #+#             */
/*   Updated: 2025/05/04 17:06:24 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_output(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	clean_and_exit(t_stack **a, int status)
{
	clear_stack(a);
	if (status == EXIT_FAILURE)
		error_output();
	exit(status);
}

int	get_bits(t_stack *a)
{
	int	max;
	int	bits;

	bits = 0;
	max = a -> size - 1;
	while (max >> bits)
		bits++;
	return (bits);
}

int	safe_atoi(const char *str, int *num)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		if ((sign == 1 && res > INT_MAX) || (sign == -1 && - res < INT_MIN))
			return (1);
		i++;
	}
	*num = (int)(sign * res);
	return (0);
}
