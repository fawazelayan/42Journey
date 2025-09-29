/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 19:22:51 by moaljazz          #+#    #+#             */
/*   Updated: 2025/09/26 00:54:43 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	check_newline(bool *newline, int *index, char **args)
{
	int	j;

	while (args[*index] && args[*index][0] == '-' && args[*index][1] == 'n')
	{
		j = 1;
		while (args[*index][j] == 'n')
			j++;
		if (args[*index][j] != '\0')
			break ;
		*newline = false;
		(*index)++;
	}
}

int	echo_cmd(char **args)
{
	int		i;
	bool	newline;

	i = 1;
	newline = true;
	check_newline(&newline, &i, args);
	while (args[i])
	{
		printf("%s", args[i]);
		if (args[i + 1])
			printf(" ");
		i++;
	}
	if (newline)
		printf("\n");
	return (SUCCESS);
}
