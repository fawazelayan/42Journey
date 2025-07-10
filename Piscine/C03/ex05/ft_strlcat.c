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
int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dest_len;
	unsigned int	src_len;

	i = 0;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size <= dest_len || size == 0)
		return (size + src_len);
	while (src[i] != '\0' && i < (size - dest_len - 1))
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (src_len + dest_len);
}
// MAIN IS ONLY ADDED FOR TESTING, DO NOT PUSH IT TO PROJECT REPO AT CAMPUS
// #include<stdio.h>
// int	main(void)
// {
// 	char src[] = "World!";
// 	char dest[20] = "Hello, ";
// 	printf("Dest before cat: %s\n", dest);
// 	unsigned int total_cat_len = ft_strlcat(dest, src, 9);
// 	printf("Length of cat: %d\n", total_cat_len);
// 	printf("Dest after cat: %s\n", dest);
// }