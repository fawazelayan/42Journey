/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:28:06 by felayan           #+#    #+#             */
/*   Updated: 2024/07/28 15:32:16 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_charupcase(char *str)
{
	if (*str >= 'a' && *str <= 'z')
		*str -= 32;
}

void	ft_charlowcase(char *str)
{
	if (*str >= 'A' && *str <= 'Z')
		*str += 32;
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	ft_charupcase(&str[0]);
	while (str[i] != '\0')
	{
		if (!(str[i] >= 'A' && str[i] <= 'Z')
			&& !(str[i] >= 'a' && str[i] <= 'z')
			&& !(str[i] >= '0' && str[i] <= '9'))
		{
			i++;
			ft_charupcase(&str[i]);
		}
		else
		{
			i++;
			ft_charlowcase(&str[i]);
		}
	}
	return (str);
}
// MAIN IS ONLY ADDED FOR TESTING, DO NOT PUSH IT TO PROJECT REPO AT CAMPUS
// #include <stdio.h>
// int	main(void)
// {
// 	char	str[] = "salut, comment tu vas ? 42mots quarane-deux; cinqua+et+u";
// 	printf("String before capitalizing words: %s\n", str);
// 	ft_strcapitalize(str);
// 	printf("String after capitalizing words: %s\n", str);
// }