/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_etc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 01:10:33 by felayan           #+#    #+#             */
/*   Updated: 2025/05/20 01:10:34 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game -> mlx, game -> win, img,
		x * IMG_W, y * IMG_H);
}

void	print_error(char *err)
{
	ft_putstr_fd("\nError: ", 2);
	ft_putstr_fd(err, 2);
	ft_putstr_fd("\n\n", 2);
}

int	not_flooded(char **map)
{
	int	y;
	int	x;

	y = 1;
	while (map[y])
	{
		x = 1;
		while (map[y][x])
		{
			if (map[y][x] == 'C' || map[y][x] == 'E')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void	find_player_position(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = 1;
	while (map[i])
	{
		j = 1;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				*y = i;
				*x = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	find_exit_position(t_game *game)
{
	int	y;
	int	x;

	y = 1;
	while (game -> map[y])
	{
		x = 1;
		while (game -> map[y][x])
		{
			if (game -> map[y][x] == 'E')
			{
				game -> exit_x = x;
				game -> exit_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}
