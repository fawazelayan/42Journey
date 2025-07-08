/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 15:12:57 by felayan           #+#    #+#             */
/*   Updated: 2024/07/22 07:48:44 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_div_mod(int a, int b, int *div, int *mod)
{
	if (b != 0)
	{
		*div = a / b;
		*mod = a % b;
	}
}
// MAIN IS ONLY ADDED FOR TESTING, DO NOT PUSH IT TO PROJECT REPO AT CAMPUS
// #include <stdio.h>
// int	main(void)
// {
// 	int	num1 = 5;
// 	int	num2 = 6;
// 	int div;
// 	int mod;
// 	ft_div_mod(num1, num2, &div, &mod);
// 	printf("Mod of %d %% %d is %d\nDiv of %d / %d is %d\n",
// 		num1, num2, mod, num1, num2, div);
// }