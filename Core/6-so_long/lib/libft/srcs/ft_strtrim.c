/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 22:11:58 by felayan           #+#    #+#             */
/*   Updated: 2024/09/12 00:29:23 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	setch(char c, const char *set)
{
	size_t	i;
	size_t	sset;

	sset = ft_strlen(set);
	i = 0;
	while (i < sset)
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s, const char *set)
{
	char	*trim;
	size_t	st;
	size_t	en;

	st = 0;
	en = ft_strlen(s);
	while (s[st] != '\0' && setch(s[st], set))
		st++;
	while (en - 1 > st && setch(s[en - 1], set))
		en--;
	trim = malloc((en - st + 1));
	if (!trim)
		return (NULL);
	trim = ft_memcpy(trim, s + st, en - st);
	trim[en - st] = '\0';
	return (trim);
}
/*
#include <stdio.h>
int main()
{
	char *str = ft_strtrim("alooppabcppooll","pol");
	printf("%s", str);
	free(str);
}*/
