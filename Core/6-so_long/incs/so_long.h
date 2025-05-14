/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:44:59 by felayan           #+#    #+#             */
/*   Updated: 2025/05/14 17:45:02 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "ft_printf.h"
# include "mlx.h"

typedef struct s_mlx_data
{
	void	*mlx;
	void	*win;
}	t_mlx_data;

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_textures
{
	void	*wall;
	void	*floor;
	void	*collc;
	void	*player_up;
	void	*player_down;
	void	*player_left;
	void	*player_right;
	void	*exit;
}	t_textures;

#endif