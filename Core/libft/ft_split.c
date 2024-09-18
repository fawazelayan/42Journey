/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 03:09:21 by felayan           #+#    #+#             */
/*   Updated: 2024/09/14 03:43:29 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	wc(const char *s, char d)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (d == 0 && s[0] != 0)
		return (1);
	while (s[i])
	{
		if (s[i] != d && (i == 0 || s[i - 1] == d))
			count++;
		i++;
	}
	return (count);
}

int	loc(char **strs, int pos, int len)
{
	int	i;

	i = 0;
	strs[pos] = malloc(len + 1);
	if (!strs[pos])
	{
		while (i <= pos)
		{
			free(strs[i]);
			i++;
		}
		free(strs);
		return (1);
	}
	return (0);
}

int	fill(char **strs, const char *s, char d)
{
	int	i;
	int	len;
	int	j;

	j = 0;
	i = 0;
	while (s[j])
	{
		len = 0;
		while (s[j] == d && s[j])
			j++;
		while (s[j] != d && s[j])
		{
			len++;
			j++;
		}
		if (len)
		{
			if (loc(strs, i, len))
				return (1);
			ft_strlcpy(strs[i], &s[j - len], len + 1);
		}
		i++;
	}
	return (0);
}

char	**ft_split(const char *s, char d)
{
	int		words;
	char	**strs;

	words = wc(s, d);
	if (!s || !words)
	{
		strs = malloc(sizeof(strs));
		if (!strs)
			return (NULL);
		strs[0] = 0;
		return (strs);
	}
	strs = malloc((words + 1) * sizeof(strs));
	if (!strs)
		return (NULL);
	strs[words] = NULL;
	if (fill(strs, s, d))
		return (NULL);
	return (strs);
}
/*
#include <stdio.h>
int main()
{
	char *s = "      split       this for   me  !       ";
	char d = ' ';
	int i = 0;
	char **sp = ft_split(s, d);
	while(sp[i])
		printf("%s\n", sp[i++]);
}*/
