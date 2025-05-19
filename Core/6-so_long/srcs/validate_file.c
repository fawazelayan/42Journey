/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 01:08:52 by felayan           #+#    #+#             */
/*   Updated: 2025/05/20 01:08:55 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	does_not_exist(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		print_error("File does not exist.");
		return (1);
	}
	close(fd);
	return (0);
}

int	invalid_extension(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 5 || ft_strncmp(file + len - 4, ".ber", 4))
	{
		print_error("File does not end with .ber");
		return (1);
	}
	return (0);
}

int	is_empty(char *file)
{
	char	buf[1];
	int		byte;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		print_error("Opening file failed.");
		return (1);
	}
	byte = read(fd, buf, 1);
	close(fd);
	if (byte < 0)
	{
		print_error("Reading file error.");
		return (1);
	}
	if (!byte)
	{
		print_error("Empty file.");
		return (1);
	}
	return (0);
}

void	validate_usage(int argc, char *file)
{
	if (argc != 2)
	{
		print_error("Usage: <./so_long example.ber>.");
		exit(EXIT_FAILURE);
	}
	if (does_not_exist(file) || invalid_extension(file) || is_empty(file))
		exit(EXIT_FAILURE);
}

int	is_invalid_map(char **map)
{
	int	rows;
	int	cols;

	if (!map || !map[0])
		return (1);
	map_dimensions(map, &rows, &cols);
	if (is_not_rectangular(map, cols)
		|| is_not_closed(map, cols, rows)
		|| is_invalid_char(map, cols, rows)
		|| is_invalid_count(map, rows)
		|| is_not_reachable(map, rows))
		return (1);
	return (0);
}
