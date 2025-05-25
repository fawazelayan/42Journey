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

/*  ========================  */
/*		   DEFINITIONS		  */
/*  ========================  */
#ifndef SO_LONG_H
# define SO_LONG_H

# define IMG_H 64
# define IMG_W 64
# define RIGHT 1
# define LEFT 2
# define DOWN 3
# define UP 4

/*  ========================  */
/*			INCLUDES		  */
/*  ========================  */
# include "get_next_line.h"
# include "ft_printf.h"
# include "libft.h"
# include "mlx.h"  // Change to <mlx.h>
# include <fcntl.h>
# include <X11/keysym.h>

/*  ========================  */
/*		   STRUCTURES		  */
/*  ========================  */
typedef struct s_player
{
	int		frame;
	int		moves;
	int		dir;
	int		x;
	int		y;
}	t_player;

typedef struct s_textures
{
	void	*d_closed;
	void	*d_open;
	void	*cllct;
	void	*wall;
	void	*tile;
	void	*num[10];
	void	*p_r[2];
	void	*p_l[2];
	void	*p_d[2];
	void	*p_u[2];
	void	*enemy[2];
	int		height;
	int		width;
}	t_textures;

typedef struct s_game
{
	char		**map;
	int			cllcts_num;
	int			cllctd;
	int			eframe;	// Frame for enemy imgs
	int			exit_x;
	int			exit_y;
	int			height;
	int			width;
	t_player	player;
	t_textures	imgs;
	void		*mlx;
	void		*win;
}	t_game;

/*  ========================  */
/*		  HELPER FUNCS		  */
/*  ========================  */
void	map_dimensions(char **map, int *rows, int *cols);
void	find_player_position(char **map, int *x, int *y);
void	put_img(t_game *game, void *img, int x, int y);
void	load_player_imgs(t_textures *imgs, void *mlx);
void	load_number_imgs(t_textures *imgs, void *mlx);
void	flood_fill(char **map, int x, int y);
void	end_game(char elem, t_game *game);
void	find_exit_position(t_game *game);
void	nullify_imgs(t_textures *imgs);
void	strip_newline(char *line);
void	re_render(t_game *game);
void	print_error(char *err);
int		read_map(char *map, char ***parsed, int count);
int		is_null_player(t_textures *imgs);
int		is_null_number(t_textures *imgs);
int		not_flooded(char **map);
char	**copy_map(char **map, int rows);

/*  ========================  */
/*		  COUNTER FUNCS		  */
/*  ========================  */
void	count_chars(char **map, int rows, int *p_cnt, int *e_cnt);
int		count_collectibles(char **map);
int		count_lines(int fd);

/*  ========================  */
/*		VALIDATION FUNCS	  */
/*  ========================  */
int		is_invalid_char(char **map, int cols, int rows);
int		is_not_closed(char **map, int cols, int rows);
int		is_not_rectangular(char **map, int cols);
int		is_invalid_count(char **map, int rows);
int		is_not_reachable(char **map, int rows);
int		invalid_extension(char *file);
int		does_not_exist(char *file);
int		is_invalid_map(char **map);
int		is_empty(char *file);
void	validate_usage(int argc, char *file);

/*  ========================  */
/*		INIT GAME FUNCS		  */
/*  ========================  */
void	init_player(t_player *player, char **map);
int		init_imgs(t_textures *imgs, void *mlx);
int		init_game(t_game *game, char *map);
char	**parse_map(char *map);

/*  ========================  */
/*		RENDERING FUNCS		  */
/*  ========================  */
void	render_elem(t_game *game, char elem, int x, int y);
void	render_player(t_game *game, int x, int y);
void	render_game(t_game *game);
void	render_moves(t_game *game);

/*  ========================  */
/*		CLEANING FUNCS		  */
/*  ========================  */
void	clean_player_enemy_imgs(t_textures *imgs, void *mlx);
void	clean_imgs(t_textures *imgs, void *mlx);
void	clean_map(char **map);
int		close_game(t_game *game);

/*  ========================  */
/*		  HOOKS FUNCS		  */
/*  ========================  */
int		key_press_handler(int keysym, t_game *game);
void	move_right(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_up(t_game *game);

#endif