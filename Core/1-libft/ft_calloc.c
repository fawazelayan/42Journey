/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 00:20:00 by felayan           #+#    #+#             */
/*   Updated: 2024/09/09 01:22:21 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*loc;
	size_t	tots;

	tots = nmemb * size;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (tots / size != nmemb)
		return (NULL);
	loc = malloc (tots);
	if (!loc)
		return (NULL);
	ft_bzero(loc, tots);
	return (loc);
}
