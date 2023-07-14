/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguarien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 11:29:15 by sguarien          #+#    #+#             */
/*   Updated: 2023/05/29 11:29:16 by sguarien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_images(t_game *game)
{
	int	len;

	len = 64;
	game->img.wall = mlx_xpm_file_to_image(game->mlx, WALL, &len, &len);
	game->img.player = mlx_xpm_file_to_image(game->mlx, UNICORN, &len, &len);
	game->img.floor = mlx_xpm_file_to_image(game->mlx, FLOOR, &len, &len);
	game->img.exit = mlx_xpm_file_to_image(game->mlx, EXIT, &len, &len);
	game->img.collectible = mlx_xpm_file_to_image(game->mlx, HEART, &len, &len);
	game->img.on_rainbow = mlx_xpm_file_to_image(game->mlx, ON_RAINBOW,
			&len, &len);
}

void	put_map(int x, int y, char c, t_game *game)
{
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.wall, x * 64, y * 64);
	if (c == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.floor, x * 64, y * 64);
	if (c == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.player, x * 64, y * 64);
	if (c == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.exit, x * 64, y * 64);
	if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.collectible, x * 64, y * 64);
	if (c == 'R')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.on_rainbow, x * 64, y * 64);
}

int	collectible_counter(t_game *game)
{
	int	x;
	int	y;
	int	points;

	x = 0;
	y = 0;
	points = 0;
	while (x < game->line_x)
	{
		while (y < game->col_y)
		{
			if (game->map[x][y] == 'C')
				points++;
			y++;
		}
		y = 0;
		x++;
	}
	return (points);
}

void	player_position(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < game->line_x)
	{
		while (y < game->col_y)
		{
			if (game->map[x][y] == 'P')
			{
				game->player_x = y;
				game->player_y = x;
			}
			y++;
		}
		y = 0;
		x++;
	}
}
