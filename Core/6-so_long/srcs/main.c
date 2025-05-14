/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:52:03 by felayan           #+#    #+#             */
/*   Updated: 2025/05/14 17:52:04 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_mlx_data	so_long;
	int i = 0;
	int j = 0;
	so_long.mlx = mlx_init();
	so_long.win = mlx_new_window(so_long.mlx, 500, 500, "So_long");
	//so_long.img = mlx_new_image(so_long.mlx, 50, 50);
	while (i < 50)
	{
		while (j < 50)
		{
			mlx_pixel_put(so_long.mlx, so_long.win, 250 + j, 250 + i, 0x00ff00);
			j++;
		}
		j = 0;
		i++;
	}
	i = 0;
	while (i < 10)
	{
		mlx_pixel_put(so_long.mlx, so_long.win, 260 + i, 260, 0x000000);
		i++;
	}
	while (i > 0)
	{
		mlx_pixel_put(so_long.mlx, so_long.win, 290 - i, 260, 0x000000);
		i--;
	}
	while (i < 10)
	{
		mlx_pixel_put(so_long.mlx, so_long.win, 270 + i, 280, 0x000000);
		i++;
	}
	while (j < 5)
	{
		mlx_pixel_put(so_long.mlx, so_long.win, 270, 280 + j, 0x000000);
		j++;
	}
	j = 0;
	while (j < 5)
	{
		mlx_pixel_put(so_long.mlx, so_long.win, 280, 280 + j, 0x000000);
		j++;
	}
	mlx_loop(so_long.mlx);
}
