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
	char		new_elem;
	static int	i = 0;

	new_elem = '\0';
	if (game -> player.y - 1 >= 0)
	{
		game -> player.frame = i++ % 2;
		game -> player.dir = UP;
		new_elem = game -> map[game -> player.y - 1][game -> player.x];
		if (new_elem == '1')
			return ;
		if (new_elem == 'C')
			game -> cllctd++;
		end_game(new_elem, game);
		re_render(game);
		game -> player.y--;
		ft_printf("Moves: %d\n", ++game -> player.moves);
		game -> map[game -> player.y][game -> player.x] = 'P';
		render_game(game);
	}
}

void	move_down(t_game *game)
{
	char		new_elem;
	static int	i = 0;

	new_elem = '\0';
	if (game -> player.y + 1 < game -> height / 64)
	{
		game -> player.frame = i++ % 2;
		game -> player.dir = DOWN;
		new_elem = game -> map[game -> player.y + 1][game -> player.x];
		if (new_elem == '1')
			return ;
		if (new_elem == 'C')
			game -> cllctd++;
		end_game(new_elem, game);
		re_render(game);
		game -> player.y++;
		ft_printf("Moves: %d\n", ++game -> player.moves);
		game -> map[game -> player.y][game -> player.x] = 'P';
		render_game(game);
	}
}

void	move_left(t_game *game)
{
	char		new_elem;
	static int	i = 0;

	new_elem = '\0';
	if (game -> player.x - 1 >= 0)
	{
		game -> player.frame = i++ % 2;
		game -> player.dir = LEFT;
		new_elem = game -> map[game -> player.y][game -> player.x - 1];
		if (new_elem == '1')
			return ;
		if (new_elem == 'C')
			game -> cllctd++;
		end_game(new_elem, game);
		re_render(game);
		game -> player.x--;
		ft_printf("Moves: %d\n", ++game -> player.moves);
		game -> map[game -> player.y][game -> player.x] = 'P';
		render_game(game);
	}
}

void	move_right(t_game *game)
{
	char		new_elem;
	static int	i = 0;

	new_elem = '\0';
	if (game -> player.x + 1 < game -> width / 64)
	{
		game -> player.frame = i++ % 2;
		game -> player.dir = RIGHT;
		new_elem = game -> map[game -> player.y][game -> player.x + 1];
		if (new_elem == '1')
			return ;
		if (new_elem == 'C')
			game -> cllctd++;
		end_game(new_elem, game);
		re_render(game);
		game -> player.x++;
		ft_printf("Moves: %d\n", ++game -> player.moves);
		game -> map[game -> player.y][game -> player.x] = 'P';
		render_game(game);
	}
}

int	key_press_handler(int keysym, t_game *game)
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
