/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 23:36:11 by felayan           #+#    #+#             */
/*   Updated: 2024/07/31 23:46:41 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*dupl;

	i = 0;
	while (src[i] != '\0')
		i++;
	dupl = (char *)malloc(i * 1);
	i = 0;
	if (!dupl)
		return (0);
	while (src[i] != '\0')
	{
		dupl[i] = src[i];
		i++;
	}
	dupl[i] = '\0';
	return (dupl);
}
/*#include<stdio.h>
int	main()
{
	char *dupl = ft_strdup("HELLO");
	if (!dupl)
		return (0);
	printf("%s", dupl);
	free (dupl);
	return (0);
}*/
