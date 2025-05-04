/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 02:15:44 by felayan           #+#    #+#             */
/*   Updated: 2024/09/08 23:17:38 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}
/*
#include <stdio.h>
int main() {
    const char *str = "teste";
    char target = '\0';  // Search for the null terminator
    char *result;

    // Find the null terminator in the string
    result = ft_strchr(str,target);

    if (result) {
        printf("Null terminator found at position: %p\n", result);
    } else {
        printf("Null terminator not found.\n");
    }

    return 0;
}*/
