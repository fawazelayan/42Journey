/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 07:15:52 by felayan           #+#    #+#             */
/*   Updated: 2024/07/22 07:49:35 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;

	div = 0;
	mod = 0;
	if (*b != 0)
	{
		div = *a / *b;
		mod = *a % *b;
		*a = div;
		*b = mod;
	}
}
// MAIN IS ONLY ADDED FOR TESTING, DO NOT PUSH IT TO PROJECT REPO AT CAMPUS
// #include <stdio.h>
// int	main(void)
// {
// 	int	a = 5;
// 	int	b = 6;
// 	int tmp = a;
// 	int tmp2 = b;
// 	ft_ultimate_div_mod(&a, &b);
// 	printf("Mod of %d %% %d is %d\nDiv of %d / %d is %d\n",
// 		tmp, tmp2, b, tmp, tmp2, a);
// }