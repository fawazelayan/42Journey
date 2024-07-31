/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 21:05:04 by felayan           #+#    #+#             */
/*   Updated: 2024/07/30 21:35:10 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	whitesp(char **str)
{
	while ((**str >= 9 && **str <= 13) || **str == 32)
		(*str)++;
}

int	sign(char **str)
{
	int	sig;

	sig = 1;
	whitesp(str);
	while (**str == '+' || **str == '-')
	{
		if (**str == '-')
			sig *= -1;
		(*str)++;
	}
	return (sig);
}

int	ft_atoi(char *str)
{
	int	sig;
	int	res;

	res = 0;
	sig = sign(&str);
	while (*str >= 48 && *str <= 57)
	{
		res *= 10;
		res += *str - 48;
		str++;
	}
	res *= sig;
	return (res);
}
/*#include <stdio.h>
int	main(void)
{
	printf("%d", ft_atoi("  	---++--1234as54"));
}
*/
