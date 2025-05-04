/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 20:36:09 by felayan           #+#    #+#             */
/*   Updated: 2024/09/08 23:06:52 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;

	p = (char *)(s + ft_strlen(s));
	while (p >= s)
	{
		if (*p == (unsigned char)c)
			return (p);
		p--;
	}
	return (NULL);
}
/*
#include <stdio.h>
int main() {
    const char *str = "hello w\0rld";
    char target = '\0';
    char *result = ft_strrchr(str, target);

    if (result) {
        printf("Last occurrence of '%c': %s\n", target, result);
	printf("Location at: %ld",result - str);
    } else {
        printf("Character '%c' not found\n", target);
    }

    return 0;
}*/
