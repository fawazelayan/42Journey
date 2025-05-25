/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 01:09:11 by felayan           #+#    #+#             */
/*   Updated: 2025/05/20 01:09:12 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**parse_map(char *map)
{
	char	**parsed;
	int		fd;
	int		count;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (NULL);
	count = count_lines(fd);
	close(fd);
	parsed = malloc((count + 1) * sizeof(char *));
	if (!parsed || read_map(map, &parsed, count) || is_invalid_map(parsed))
	{
		clean_map(parsed);
		return (NULL);
	}
	return (parsed);
}

void	init_player(t_player *player, char **map)
{
	player -> moves = 0;
	player -> frame = 0;
	player -> dir = DOWN;
	find_player_position(map, &player -> x, &player -> y);
}

int	init_imgs(t_textures *imgs, void *mlx)
{
	imgs -> width = IMG_W;
	imgs -> height = IMG_H;
	imgs -> d_closed = mlx_xpm_file_to_image(mlx, "txtrs/d_closed.xpm",
			&imgs -> width, &imgs -> height);
	imgs -> d_open = mlx_xpm_file_to_image(mlx, "txtrs/d_open.xpm",
			&imgs -> width, &imgs -> height);
	imgs -> cllct = mlx_xpm_file_to_image(mlx, "txtrs/scroll.xpm",
			&imgs -> width, &imgs -> height);
	imgs -> wall = mlx_xpm_file_to_image(mlx, "txtrs/wall.xpm",
			&imgs -> width, &imgs -> height);
	imgs -> tile = mlx_xpm_file_to_image(mlx, "txtrs/tile.xpm",
			&imgs -> width, &imgs -> height);
	imgs -> enemy[0] = mlx_xpm_file_to_image(mlx, "txtrs/enemy1.xpm",
			&imgs -> width, &imgs -> height);
	imgs -> enemy[1] = mlx_xpm_file_to_image(mlx, "txtrs/enemy2.xpm",
			&imgs -> width, &imgs -> height);
	load_player_imgs(imgs, mlx);
	load_number_imgs(imgs, mlx);
	if (!imgs -> wall || !imgs -> tile || !imgs -> cllct
		|| !imgs -> d_closed || !imgs -> d_open
		|| !imgs -> enemy[0] || !imgs -> enemy[1]
		|| is_null_player(imgs) || is_null_number(imgs))
		return (1);
	return (0);
}

int	init_game(t_game *game, char *map)
{
	game -> map = parse_map(map);
	if (!game -> map)
		return (1);
	game -> mlx = mlx_init();
	if (!game -> mlx)
		return (1);
	game -> cllcts_num = count_collectibles(game -> map);
	game -> cllctd = 0;
	find_exit_position(game);
	map_dimensions(game -> map, &game -> height, &game -> width);
	game -> height *= IMG_H;
	game -> width *= IMG_W;
	init_player(&game -> player, game -> map);
	if (init_imgs(&game -> imgs, game -> mlx))
		return (1);
	game -> win = mlx_new_window(game -> mlx,
			game -> width, game -> height, "Witch Cat");
	if (!game -> win)
		return (1);
	return (0);
}
