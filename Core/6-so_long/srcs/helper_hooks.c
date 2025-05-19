/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 01:10:25 by felayan           #+#    #+#             */
/*   Updated: 2025/05/20 01:10:26 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	end_game(char elem, t_game *game)
{
	if (elem == 'E' && game -> cllctd == game -> cllcts_num)
	{
		ft_printf("\nYou win!\n\n");
		close_game(game);
	}
	else if (elem == 'X')
	{
		ft_printf("\nYou lost :(\n\n");
		close_game(game);
	}
}

void	re_render(t_game *game)
{
	game->map[game->player.y][game->player.x] = '0';
	if (game->exit_x == game->player.x && game->exit_y == game->player.y)
		game->map[game->player.y][game->player.x] = 'E';
}
