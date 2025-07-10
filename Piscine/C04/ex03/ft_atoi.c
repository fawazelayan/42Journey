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
void	whitespace_check(char *str, int *index)
{
	while (str[*index] == 32 || (str[*index] >= 9 && str[*index] <= 13))
		(*index)++;
}

void	sign_check(char *str, int *sign, int *index)
{
	while (str[*index] == '-' || str[*index] == '+')
	{
		if (str[*index] == '-')
			*sign *= -1;
		(*index)++;
	}
}

void	convert_char_to_int(char *str, int *num, int *index)
{
	while (str[*index] >= '0' && str[*index] <= '9')
	{
		*num = *num * 10 + (str[*index] - '0');
		(*index)++;
	}
}

int	ft_atoi(char *str)
{
	int	i;
	int	num;
	int	sign;

	i = 0;
	num = 0;
	sign = 1;
	whitespace_check(str, &i);
	sign_check(str, &sign, &i);
	convert_char_to_int(str, &num, &i);
	return (num * sign);
}
// MAIN IS ONLY ADDED FOR TESTING, DO NOT PUSH IT TO PROJECT REPO AT CAMPUS
// #include <stdio.h>
// int	main(void)
// {
// 	printf("The num converted from the string is: %d\n", ft_atoi(" -+-123a"));
// }