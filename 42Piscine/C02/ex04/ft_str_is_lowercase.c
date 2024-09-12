/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:01:04 by felayan           #+#    #+#             */
/*   Updated: 2024/07/28 13:20:59 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	int	i;
	int	last;

	last = 1;
	i = 0;
	while (str[i] != '\0')
	{
		last = 0;
		if (str[i] >= 'a' && str[i] <= 'z')
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
	int	i = ft_str_is_lowercase("");
	printf("%i", i);
}
*/
