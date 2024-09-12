/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 23:20:31 by felayan           #+#    #+#             */
/*   Updated: 2024/09/12 00:29:55 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*#include "libft.h"

size_t wc(const char *s, char c)
{
	size_t i = 0;
	size_t co = 0;

	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			co++;
		i++;
	}
	return (co);
}

size_t	check(const char *s, char c)
{
	size_t	i;
	size_t	res;

	res = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			res = 1;
			break ;
		}
		i++;
	}
	return (res);
}

char	**ft_split(const char *s, char c)
{
	char	**sp;
	size_t	i;

	i = 0;
	if(!s || !check(s, c))
		return (NULL);
	sp = malloc(wc(s,c) * sizeof(sp) + 1);
	if (!sp)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			sp[j] = malloc
}*/
