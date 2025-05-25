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

void	load_number_imgs(t_textures *imgs, void *mlx)
{
	int			i;
	int			h;
	int			w;
	static char	path[] = "txtrs/0.xpm";

	i = 0;
	h = imgs -> height;
	w = imgs -> width;
	while (i < 10)
	{
		path[6] = '0' + i;
		imgs -> num[i++] = mlx_xpm_file_to_image(mlx, path, &w, &h);
	}
}

int	is_null_player(t_textures *imgs)
{
	if (!imgs -> p_u[0] || !imgs -> p_u[1]
		|| !imgs -> p_d[0] || !imgs -> p_d[1])
		return (1);
	if (!imgs -> p_l[0] || !imgs -> p_l[1]
		|| !imgs -> p_r[0] || !imgs -> p_r[1])
		return (1);
	return (0);
}

int	is_null_number(t_textures *imgs)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (!imgs -> num[i++])
			return (1);
	}
	return (0);
}

void	nullify_imgs(t_textures *imgs)
{
	int	i;

	i = 0;
	imgs -> d_closed = NULL;
	imgs -> d_open = NULL;
	imgs -> cllct = NULL;
	imgs -> wall = NULL;
	imgs -> tile = NULL;
	while (i < 10)
		imgs -> num[i++] = NULL;
	i = 0;
	while (i < 2)
	{
		imgs -> p_u[i] = NULL;
		imgs -> p_d[i] = NULL;
		imgs -> p_l[i] = NULL;
		imgs -> p_r[i] = NULL;
		imgs -> enemy[i++] = NULL;
	}
}
