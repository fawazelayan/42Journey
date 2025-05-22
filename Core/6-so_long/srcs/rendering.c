/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 01:09:23 by felayan           #+#    #+#             */
/*   Updated: 2025/05/20 01:09:23 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_player(t_game *game, int x, int y)
{
	void	*img;

	img = NULL;
	if (game -> player.dir == UP)
		img = game -> imgs.p_u[game -> player.frame];
	else if (game -> player.dir == DOWN)
		img = game -> imgs.p_d[game -> player.frame];
	else if (game -> player.dir == LEFT)
		img = game -> imgs.p_l[game -> player.frame];
	else
		img = game -> imgs.p_r[game -> player.frame];
	put_img(game, img, x, y);
}

void	render_elem(t_game *game, char elem, int x, int y)
{
	if (elem == '1')
		put_img(game, game -> imgs.wall, x, y);
	else if (elem == 'C')
		put_img(game, game -> imgs.cllct, x, y);
	else if (elem == 'E')
	{
		if (game -> cllctd == game -> cllcts_num)
			put_img(game, game -> imgs.d_open, x, y);
		else
			put_img(game, game -> imgs.d_closed, x, y);
	}
	else if (elem == 'P')
		render_player(game, x, y);
	else if (elem == 'X')
		put_img(game, game -> imgs.enemy, x, y);
}

void	render_moves(t_game *game)
{
	int	i;
	int	moves;
	int	digits[10];
	int	count;

	i = 0;
	count = 0;
	moves = game -> player.moves;
	if (moves == 0)
	{
		put_img(game, game -> imgs.num[0], 0, 0);
		return ;
	}
	while (moves > 0 && count < 10)
	{
		digits[count++] = moves % 10;
		moves /= 10;
	}
	while (count-- > 0)
		put_img(game, game->imgs.num[digits[count]], i++, 0);
}

void	render_game(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game -> height / IMG_H)
	{
		x = 0;
		while (x < game -> width / IMG_W)
		{
			put_img(game, game -> imgs.tile, x, y);
			render_elem(game, game -> map[y][x], x, y);
			x++;
		}
		y++;
	}
	render_moves(game);
}
