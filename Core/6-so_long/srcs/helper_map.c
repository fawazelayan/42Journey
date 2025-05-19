/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 01:09:46 by felayan           #+#    #+#             */
/*   Updated: 2025/05/20 01:09:47 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	strip_newline(char *line)
{
	size_t	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}

int	read_map(char *map, char ***parsed, int count)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (1);
	while (i < count)
	{
		(*parsed)[i] = get_next_line(fd);
		if (!(*parsed)[i])
		{
			clean_map(*parsed);
			close(fd);
			return (1);
		}
		strip_newline((*parsed)[i]);
		i++;
	}
	close(fd);
	(*parsed)[count] = NULL;
	return (0);
}

void	map_dimensions(char **map, int *rows, int *cols)
{
	*rows = 0;
	while (map[*rows])
		(*rows)++;
	*cols = (int)ft_strlen(map[0]);
}

char	**copy_map(char **map, int rows)
{
	char	**cpy;
	int		i;

	i = 0;
	cpy = malloc (sizeof(char *) * (rows + 1));
	if (!cpy)
		return (NULL);
	while (i < rows)
	{
		cpy[i] = ft_strdup(map[i]);
		if (!cpy[i])
		{
			clean_map(cpy);
			return (NULL);
		}
		i++;
	}
	cpy[i] = NULL;
	return (cpy);
}

void	flood_fill(char **map, int x, int y)
{
	int	rows;
	int	cols;

	map_dimensions(map, &rows, &cols);
	if (x < 0 || y < 0 || x >= cols || y >= rows
		|| map[y][x] == '1' || map[y][x] == 'F'
		|| map[y][x] == 'X')
		return ;
	map[y][x] = 'F';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}
