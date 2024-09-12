/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:06:31 by felayan           #+#    #+#             */
/*   Updated: 2024/07/28 13:21:14 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	int	i;
	int	last;

	last = 1;
	i = 0;
	while (str[i] != '\0')
	{
		last = 0;
		if (str[i] >= 'A' && str[i] <= 'Z')
			last = 1;
		else
			break ;
		i++;
	}
	return (last);
}
/*
int	main(void)
{
	int	i = ft_str_is_uppercase("Hello");
	printf("%i", i);
}
*/
