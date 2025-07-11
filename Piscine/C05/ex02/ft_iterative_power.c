/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 00:01:16 by felayan           #+#    #+#             */
/*   Updated: 2024/07/31 00:21:33 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_iterative_power(int nb, int power)
{
	int	powered_num;

	powered_num = nb;
	if (power < 0)
		return (0);
	if (power == 0 || nb == 1)
		return (1);
	while (power-- != 1)
		powered_num *= nb;
	return (powered_num);
}
// MAIN IS ONLY ADDED FOR TESTING, DO NOT PUSH IT TO PROJECT REPO AT CAMPUS
// #include<stdio.h>
// int	main(void)
// {
// 	printf("%d", ft_iterative_power(2, 4));
// }