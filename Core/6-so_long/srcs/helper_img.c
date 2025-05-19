/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 01:10:09 by felayan           #+#    #+#             */
/*   Updated: 2025/05/20 01:10:11 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_player_imgs(t_textures *imgs, void *mlx)
{
	int	w;
	int	h;

	w = imgs -> width;
	h = imgs -> height;
	imgs -> p_u[0] = mlx_xpm_file_to_image(mlx, "txtrs/p_u1.xpm", &w, &h);
	imgs -> p_u[1] = mlx_xpm_file_to_image(mlx, "txtrs/p_u2.xpm", &w, &h);
	imgs -> p_d[0] = mlx_xpm_file_to_image(mlx, "txtrs/p_d1.xpm", &w, &h);
	imgs -> p_d[1] = mlx_xpm_file_to_image(mlx, "txtrs/p_d2.xpm", &w, &h);
	imgs -> p_l[0] = mlx_xpm_file_to_image(mlx, "txtrs/p_l1.xpm", &w, &h);
	imgs -> p_l[1] = mlx_xpm_file_to_image(mlx, "txtrs/p_l2.xpm", &w, &h);
	imgs -> p_r[0] = mlx_xpm_file_to_image(mlx, "txtrs/p_r1.xpm", &w, &h);
	imgs -> p_r[1] = mlx_xpm_file_to_image(mlx, "txtrs/p_r2.xpm", &w, &h);
}

void	load_moves_imgs(t_textures *imgs, void *mlx)
{
	int	w;
	int	h;

	w = imgs -> width;
	h = imgs -> height;
	imgs -> mvs[0] = mlx_xpm_file_to_image(mlx, "txtrs/0.xpm", &w, &h);
	imgs -> mvs[1] = mlx_xpm_file_to_image(mlx, "txtrs/1.xpm", &w, &h);
	imgs -> mvs[2] = mlx_xpm_file_to_image(mlx, "txtrs/2.xpm", &w, &h);
	imgs -> mvs[3] = mlx_xpm_file_to_image(mlx, "txtrs/3.xpm", &w, &h);
	imgs -> mvs[4] = mlx_xpm_file_to_image(mlx, "txtrs/4.xpm", &w, &h);
	imgs -> mvs[5] = mlx_xpm_file_to_image(mlx, "txtrs/5.xpm", &w, &h);
	imgs -> mvs[6] = mlx_xpm_file_to_image(mlx, "txtrs/6.xpm", &w, &h);
	imgs -> mvs[7] = mlx_xpm_file_to_image(mlx, "txtrs/7.xpm", &w, &h);
	imgs -> mvs[8] = mlx_xpm_file_to_image(mlx, "txtrs/8.xpm", &w, &h);
	imgs -> mvs[9] = mlx_xpm_file_to_image(mlx, "txtrs/9.xpm", &w, &h);
}

int	img_fail_player(t_textures *imgs)
{
	if (!imgs -> p_u[0] || !imgs -> p_u[1]
		|| !imgs -> p_d[0] || !imgs -> p_d[1])
		return (1);
	if (!imgs -> p_l[0] || !imgs -> p_l[1]
		|| !imgs -> p_r[0] || !imgs -> p_r[1])
		return (1);
	return (0);
}

int	img_fail_moves(t_textures *imgs)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (!imgs -> mvs[i])
			return (1);
		i++;
	}
	return (0);
}

void	nullify_imgs(t_textures *imgs)
{
	int	i;

	i = 0;
	imgs->d_closed = NULL;
	imgs->d_open = NULL;
	imgs->cllct = NULL;
	imgs->wall = NULL;
	imgs->tile = NULL;
	imgs -> enemy = NULL;
	while (i < 10)
		imgs -> mvs[i++] = NULL;
	i = 0;
	while (i < 2)
	{
		imgs->p_u[i] = NULL;
		imgs->p_d[i] = NULL;
		imgs->p_l[i] = NULL;
		imgs->p_r[i] = NULL;
		i++;
	}
}
