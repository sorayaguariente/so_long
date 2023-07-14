/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguarien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:19:33 by sguarien          #+#    #+#             */
/*   Updated: 2023/05/04 19:19:35 by sguarien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include "printf/ft_printf.h"

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdbool.h>

# define UNICORN "./images/unicorn.xpm"
# define HEART "./images/heart.xpm"
# define EXIT "./images/exit.xpm"
# define WALL "./images/wall.xpm"
# define FLOOR "./images/floor.xpm"
# define ON_RAINBOW "./images/on_rainbow.xpm"

# define W 119
# define A 97
# define S 115
# define D 100
# define ESC 65307

typedef struct s_img
{
	void	*collectible;
	void	*player;
	void	*floor;
	void	*wall;
	void	*exit;
	void	*on_rainbow;
}	t_img;

typedef struct s_game
{
	t_img	img;
	void	*mlx;
	void	*win;
	char	**map;
	char	**map_floodfill;
	char	temp;
	int		line_x;
	int		col_y;
	int		exit;
	int		score;
	int		player;
	int		player_on_rainbow;
	int		player_y;
	int		player_x;
	int		end_game;
	int		move;
}	t_game;

void	check_args(t_game *game, int argc, char **argv);
void	check_map(t_game *game);
void	valid_map(t_game *game);
void	valid_path(t_game *game, int fd);
void	start_validations(t_game *game, int fd);
int		key_handler(int x, t_game *game);
void	get_maps(t_game *game, int fd);
void	put_images(t_game *game);
void	put_map(int x, int y, char c, t_game *game);
int		get_col_size(t_game *game, int fd);
int		get_line_size(t_game *game, int fd);
int		render_img(t_game *game);
int		collectible_counter(t_game *game);
void	player_position(t_game *game);
void	free_map(t_game *game);
void	free_map_floodfill(t_game *game);
void	free_img(t_game *game);
void	ft_exit(char *s, t_game *game);
int		close_window(t_game *game);

#endif