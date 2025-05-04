/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 01:10:17 by felayan           #+#    #+#             */
/*   Updated: 2025/05/02 01:10:18 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*create_array(int argc, char **argv)
{
	int		*arr;
	int		i;

	i = 0;
	arr = malloc(argc * sizeof(int));
	if (!arr)
		return (NULL);
	while (i < argc)
	{
		if (safe_atoi(argv[i], &arr[i]))
		{
			free(arr);
			return (NULL);
		}
		i++;
	}
	return (arr);
}

int	is_duplicate(int argc, int *arr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_number(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		if (!argv[i][j])
			return (1);
		while (argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	validate_arguments(int argc, char **argv)
{
	int	*arr;

	arr = NULL;
	if (is_number(argc, argv))
		return (1);
	else
	{
		arr = create_array(argc, argv);
		if (!arr)
			return (1);
	}
	if (is_duplicate(argc, arr))
	{
		free(arr);
		return (1);
	}
	free(arr);
	return (0);
}
