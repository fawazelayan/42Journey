/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:47:23 by felayan           #+#    #+#             */
/*   Updated: 2025/02/19 14:47:27 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_gnl(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strdup_gnl(const char *s)
{
	char	*dup;
	int		len;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen_gnl(s);
	dup = malloc (len + 1);
	if (!dup)
		return (NULL);
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

char	*ft_strjoin_gnl(const char *s1, const char *s2)
{
	char	*join;
	int		len1;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	len1 = ft_strlen_gnl(s1);
	join = malloc (ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1);
	if (!join)
		return (NULL);
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		join[i + len1] = s2[i];
		i++;
	}
	join[i + len1] = '\0';
	return (join);
}

char	*ft_strchr_gnl(const char *s, int c)
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

int	lentonew(const char *s)
{
	int	len;

	len = 0 ;
	while (s[len] != '\n' && s[len] != 0)
		len++;
	return (len + (s[len] == '\n'));
}
//