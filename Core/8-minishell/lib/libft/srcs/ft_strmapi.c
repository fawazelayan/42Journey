/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 00:43:34 by felayan           #+#    #+#             */
/*   Updated: 2024/09/12 01:58:00 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/*char	transform(unsigned int b, char c)
{
	if (!(b % 2) && ft_isalpha(c))
		return (c + 1);
	else if (ft_isalpha(c))
		return (c - 1);
	return (c);
}*/

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	unsigned int	i;
	char			*map;

	i = 0;
	if (!s || !f)
		return (NULL);
	map = malloc(ft_strlen(s) + 1);
	if (!map)
		return (NULL);
	while (s[i] != '\0')
	{
		map[i] = f(i, s[i]);
		i++;
	}
	map[i] = '\0';
	return (map);
}
/*
#include <stdio.h>
int main()
{
	char *s = "Hello 42 Amman";
	char *b = ft_strmapi(s, transform);

	printf("%s\n", b);
	free(b);
}*/
