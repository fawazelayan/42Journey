/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:11:55 by felayan           #+#    #+#             */
/*   Updated: 2024/09/08 22:40:46 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;
	size_t			i;

	i = 0;
	p = s;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
}
/*
#include <stdio.h>
int main() {
    char str[20] = "Hello, World!";

    // Print the original string
    printf("Original string: '%s'\n", str);

    // Zero out the first 5 bytes of the string
    ft_bzero(str + 2, 5);

    // Print the modified string
    printf("Modified string: '%s'\n", str);

    return 0;
}*/
