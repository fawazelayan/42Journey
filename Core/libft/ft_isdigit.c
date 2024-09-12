/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 01:21:58 by felayan           #+#    #+#             */
/*   Updated: 2024/09/08 22:38:08 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/*
#include <stdio.h>
int main()
{
	char a = '0';
	int i = 0;
	while (a <= '9')
	{
		printf("%d: %d\n",i++,ft_isdigit(a));
		a++;
	}
}*/