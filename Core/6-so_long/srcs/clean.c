/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 01:11:03 by felayan           #+#    #+#             */
/*   Updated: 2025/05/20 01:11:04 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	clean_player_imgs(t_textures *imgs, void *mlx)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (imgs -> p_u[i])
			mlx_destroy_image(mlx, imgs -> p_u[i]);
		if (imgs -> p_d[i])
			mlx_destroy_image(mlx, imgs -> p_d[i]);
		if (imgs -> p_l[i])
			mlx_destroy_image(mlx, imgs -> p_l[i]);
		if (imgs -> p_r[i])
			mlx_destroy_image(mlx, imgs -> p_r[i]);
		i++;
	}
}

void	clean_imgs(t_textures *imgs, void *mlx)
{
	int	i;

	i = 0;
	if (imgs->d_closed)
		mlx_destroy_image(mlx, imgs->d_closed);
	if (imgs->d_open)
		mlx_destroy_image(mlx, imgs->d_open);
	if (imgs->cllct)
		mlx_destroy_image(mlx, imgs->cllct);
	if (imgs->wall)
		mlx_destroy_image(mlx, imgs->wall);
	if (imgs->tile)
		mlx_destroy_image(mlx, imgs->tile);
	if (imgs -> enemy)
		mlx_destroy_image(mlx, imgs -> enemy);
	clean_player_imgs(imgs, mlx);
	while (i < 10)
	{
		if (imgs -> num[i])
			mlx_destroy_image(mlx, imgs -> num[i]);
		i++;
	}
	nullify_imgs(imgs);
}

int	close_game(t_game *game)
{
	if (!game)
		return (1);
	if (game -> win)
		mlx_destroy_window(game -> mlx, game -> win);
	clean_imgs(&game -> imgs, game -> mlx);
	clean_map(game -> map);
	if (game -> mlx)
	{
		mlx_destroy_display(game -> mlx);
		free(game -> mlx);
	}
	game -> mlx = NULL;
	game -> win = NULL;
	game -> map = NULL;
	exit(EXIT_SUCCESS);
	return (0);
}
