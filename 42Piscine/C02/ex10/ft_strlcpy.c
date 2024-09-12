/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:05:44 by felayan           #+#    #+#             */
/*   Updated: 2024/07/29 13:40:31 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	length;

	i = 0;
	length = 0;
	while (src[length] != '\0')
		length++;
	if (size == 0)
		return (length);
	else
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (length);
}
/*
int	main(void)
{
	char	src[] = "Hello12345";
	char	dest[20] = "olleH";
	unsigned int res = ft_strlcpy(dest, src, 0);
	printf("%u", res);
	printf("\n");
	printf("%s", dest);
}
*/
