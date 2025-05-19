/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 01:09:17 by felayan           #+#    #+#             */
/*   Updated: 2025/05/20 01:09:18 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game)
{
	char		new_pos;
	static int	i = 0;

	new_pos = 0;
	if (game -> player.y - 1 >= 0)
	{
		game -> player.frame = i++ % 2;
		game -> player.dir = UP;
		new_pos = game -> map[game -> player.y - 1][game -> player.x];
		if (new_pos == '1')
			return ;
		if (new_pos == 'C')
		{
			game -> cllctd++;
			game -> map[game -> player.y - 1][game -> player.x] = '0';
		}
		end_game(new_pos, game);
		re_render(game);
		game -> player.y--;
		ft_printf("Moves: %d\n", ++game -> player.moves);
		game -> map[game -> player.y][game -> player.x] = 'P';
		render_game(game);
	}
}

void	move_down(t_game *game)
{
	char		new_pos;
	static int	i = 0;

	new_pos = 0;
	if (game -> player.y + 1 < game -> height / 64)
	{
		game -> player.frame = i++ % 2;
		game -> player.dir = DOWN;
		new_pos = game -> map[game -> player.y + 1][game -> player.x];
		if (new_pos == '1')
			return ;
		if (new_pos == 'C')
		{
			game -> cllctd++;
			game -> map[game -> player.y + 1][game -> player.x] = '0';
		}
		end_game(new_pos, game);
		re_render(game);
		game -> player.y++;
		ft_printf("Moves: %d\n", ++game -> player.moves);
		game -> map[game -> player.y][game -> player.x] = 'P';
		render_game(game);
	}
}

void	move_left(t_game *game)
{
	char		new_pos;
	static int	i = 0;

	new_pos = 0;
	if (game -> player.x - 1 >= 0)
	{
		game -> player.frame = i++ % 2;
		game -> player.dir = LEFT;
		new_pos = game -> map[game -> player.y][game -> player.x - 1];
		if (new_pos == '1')
			return ;
		if (new_pos == 'C')
		{
			game -> cllctd++;
			game -> map[game -> player.y][game -> player.x - 1] = '0';
		}
		end_game(new_pos, game);
		re_render(game);
		game -> player.x--;
		ft_printf("Moves: %d\n", ++game -> player.moves);
		game -> map[game -> player.y][game -> player.x] = 'P';
		render_game(game);
	}
}

void	move_right(t_game *game)
{
	char		new_pos;
	static int	i = 0;

	new_pos = 0;
	if (game -> player.x + 1 < game -> width / 64)
	{
		game -> player.frame = i++ % 2;
		game -> player.dir = RIGHT;
		new_pos = game -> map[game -> player.y][game -> player.x + 1];
		if (new_pos == '1')
			return ;
		if (new_pos == 'C')
		{
			game -> cllctd++;
			game -> map[game -> player.y][game -> player.x + 1] = '0';
		}
		end_game(new_pos, game);
		re_render(game);
		game -> player.x++;
		ft_printf("Moves: %d\n", ++game -> player.moves);
		game -> map[game -> player.y][game -> player.x] = 'P';
		render_game(game);
	}
}

int	key_handle(int keysym, t_game *game)
{
	if (keysym == XK_W || keysym == XK_w || keysym == XK_Up)
		move_up(game);
	if (keysym == XK_S || keysym == XK_s || keysym == XK_Down)
		move_down(game);
	if (keysym == XK_A || keysym == XK_a || keysym == XK_Left)
		move_left(game);
	if (keysym == XK_D || keysym == XK_d || keysym == XK_Right)
		move_right(game);
	if (keysym == XK_Escape)
		close_game(game);
	return (0);
}
