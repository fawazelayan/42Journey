/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 01:09:02 by felayan           #+#    #+#             */
/*   Updated: 2025/05/20 01:09:04 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_not_rectangular(char **map, int cols)
{
	int	i;

	i = 1;
	while (map[i])
	{
		if (cols != (int)ft_strlen(map[i]))
		{
			print_error("Map is not rectangular");
			return (1);
		}
		i++;
	}
	return (0);
}

int	is_not_closed(char **map, int cols, int rows)
{
	int	i;

	i = 0;
	while (map[0][i])
	{
		if (map[0][i] != '1' || map[rows - 1][i] != '1')
		{
			print_error("Map is not closed.");
			return (1);
		}
		i++;
	}
	i = 1;
	while (i < rows - 1)
	{
		if (map[i][0] != '1' || map[i][cols - 1] != '1')
		{
			print_error("Map is not closed.");
			return (1);
		}
		i++;
	}
	return (0);
}

int	is_invalid_char(char **map, int cols, int rows)
{
	int	i;
	int	j;

	i = 1;
	while (i < rows - 1)
	{
		j = 1;
		while (j < cols - 1)
		{
			if (!ft_strchr("10PECX", map[i][j]))
			{
				print_error("Invalid character found.");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	is_invalid_count(char **map, int rows)
{
	int	p_cnt;
	int	e_cnt;
	int	c_cnt;

	p_cnt = 0;
	e_cnt = 0;
	c_cnt = count_collectibles(map);
	count_chars(map, rows, &p_cnt, &e_cnt);
	if (p_cnt != 1 || e_cnt != 1 || c_cnt < 1)
	{
		print_error("Map must have 1 P, 1 E, and atleast 1 C.");
		return (1);
	}
	return (0);
}

int	is_not_reachable(char **map, int rows)
{
	char	**cpy;
	int		x;
	int		y;

	y = 0;
	x = 0;
	cpy = copy_map(map, rows);
	if (!cpy)
		return (1);
	find_player_position(cpy, &x, &y);
	flood_fill(cpy, x, y);
	if (not_flooded(cpy))
	{
		print_error("Map is not fully reachable.");
		clean_map(cpy);
		return (1);
	}
	clean_map(cpy);
	return (0);
}
