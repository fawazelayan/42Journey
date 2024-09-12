/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:13:34 by felayan           #+#    #+#             */
/*   Updated: 2024/07/29 13:46:21 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	i;
	int	last;

	last = 1;
	i = 0;
	while (str[i] != '\0')
	{
		last = 0;
		if (str[i] >= 32 && str[i] <= 126)
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
	int	i = ft_str_is_printable("");
	printf("%i", i);
}
*/
