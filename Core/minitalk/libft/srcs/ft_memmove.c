/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:49:24 by felayan           #+#    #+#             */
/*   Updated: 2024/09/08 22:36:42 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dest;
	s = src;
	if (!dest && !src)
		return (NULL);
	if (d < s || d > (s + n))
	{
		while (n > 0)
		{
			*d++ = *s++;
			n--;
		}
	}
	else
	{
		while (n > 0)
		{
			*(d + n - 1) = *(s + n - 1);
			n--;
		}
	}
	return (dest);
}
/*
#include <stdio.h>
int main()
{
	char d[] = "Hello";
	ft_memmove(d + 1, d, 3);
	printf("%s", d);
}*/
