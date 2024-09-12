/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:44:00 by felayan           #+#    #+#             */
/*   Updated: 2024/07/28 13:19:35 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	int	i;
	int	last;

	last = 1;
	i = 0;
	while (str[i] != '\0')
	{
		last = 0;
		if (str[i] >= '0' && str[i] <= '9')
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
	int	i = ft_str_is_numeric("1231231241234@");
	printf("%i", i);
}
*/
