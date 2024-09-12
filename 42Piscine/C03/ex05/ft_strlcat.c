/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:03:35 by felayan           #+#    #+#             */
/*   Updated: 2024/07/29 16:20:10 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	len1(char *dest)
{
	int	i;

	i = 0;
	while (dest[i] != '\0')
		i++;
	return (i);
}

int	len2(char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	lendest;
	unsigned int	lensrc;

	i = 0;
	lendest = len1(dest);
	lensrc = len2(src);
	if (size <= lendest || size == 0)
		return (size + lensrc);
	while (src[i] != '\0' && i < size - lendest - 1)
	{
		dest[lendest + i] = src[i];
		i++;
	}
	dest[lendest + i] = '\0';
	return (lensrc + lendest);
}
/*#include<stdio.h>
int	main(void)
{
	char src[] = "World!";
	char dest[20] = "Hello, ";
	unsigned int i = ft_strlcat(dest,src, 6);
	printf("%d", i);
	printf("\n%s", dest);
	printf("\n%d", len2(src));
}
*/
