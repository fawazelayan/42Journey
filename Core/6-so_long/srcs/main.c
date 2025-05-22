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

int	main(int argc, char **argv)
{
	t_game	witch;

	ft_memset(&witch, 0, sizeof(t_game));
	validate_usage(argc, argv[1]);
	if (init_game(&witch, argv[1]))
	{
		print_error("Failed to start the game.");
		close_game(&witch);
	}
	render_game(&witch);
	mlx_hook(witch.win, 2, 1L << 0, &key_press_handler, &witch);
	mlx_hook(witch.win, 17, 0, &close_game, &witch);
	mlx_loop(witch.mlx);
}
