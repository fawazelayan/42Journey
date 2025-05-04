/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 21:51:02 by felayan           #+#    #+#             */
/*   Updated: 2024/09/09 22:11:45 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char		*join;
	size_t		tots;
	size_t		ss1;
	size_t		ss2;

	ss1 = ft_strlen(s1);
	ss2 = ft_strlen(s2);
	tots = ss1 + ss2 + 1;
	join = malloc(tots);
	if (!join)
		return (NULL);
	ft_memmove(join, s1, ss1);
	ft_memmove(join + ss1, s2, ss2 + 1);
	return (join);
}
