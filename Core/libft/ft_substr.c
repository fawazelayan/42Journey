/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:10:09 by felayan           #+#    #+#             */
/*   Updated: 2024/09/14 03:44:16 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char		*sub;
	size_t		lens;

	lens = ft_strlen(s);
	if (len + 1 == 0 || len > lens - start)
		len = lens - start;
	if (start >= lens || len == 0)
	{
		sub = malloc(1);
		if (!sub)
			return (NULL);
		sub[0] = 0;
		return (sub);
	}
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	ft_bzero(sub, len + 1);
	ft_memcpy(sub, &s[start], len);
	sub[len] = '\0';
	return (sub);
}
/*#include <stdio.h>
int main()
{
//	char *str= "lorem ipsum dolor sit amet";
	 char    *strsub;
	 strsub = ft_substr("", 0, 0);
	 printf("%s", strsub);
	 free(strsub);
}*/
