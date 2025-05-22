/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 01:10:58 by felayan           #+#    #+#             */
/*   Updated: 2025/05/20 01:10:59 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines(int fd)
{
	int		count;
	char	*line;

	count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		count++;
	}
	return (count);
}

void	count_chars(char **map, int rows, int *p_cnt, int *e_cnt)
{
	int	i;
	int	j;
	int	cols;

	i = 1;
	j = 1;
	cols = (int)ft_strlen(map[0]);
	while (i < rows - 1)
	{
		j = 1;
		while (j < cols - 1)
		{
			if (map[i][j] == 'P')
				(*p_cnt)++;
			else if (map[i][j] == 'E')
				(*e_cnt)++;
			j++;
		}
		i++;
	}
}

int	count_collectibles(char **map)
{
	int	count;
	int	rows;
	int	cols;
	int	i;
	int	j;

	i = 1;
	j = 1;
	count = 0;
	map_dimensions(map, &rows, &cols);
	while (i < rows - 1)
	{
		j = 1;
		while (j < cols - 1)
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}
