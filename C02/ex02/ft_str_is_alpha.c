/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:29:04 by felayan           #+#    #+#             */
/*   Updated: 2024/07/28 13:16:26 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	i;
	int	last;

	last = 1;
	i = 0;
	while (str[i] != '\0')
	{
		last = 0;
		if ((str[i] >= 'A' && str[i] <= 'Z')
			|| (str[i] >= 'a' && str[i] <= 'z'))
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
	int	i = ft_str_is_alpha("");
	printf("%i", i);
}
*/
