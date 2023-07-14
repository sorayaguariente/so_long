/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguarien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:48:52 by sguarien          #+#    #+#             */
/*   Updated: 2023/05/25 14:48:53 by sguarien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	start_map(t_game *game)
{
	game->player_x = 0;
	game->player_y = 0;
	game->player_on_rainbow = 0;
	game->exit = 0;
	game->player = 0;
	game->line_x = 0;
	game->col_y = 0;
	game->end_game = 0;
	game->move = 1;
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->col_y * 64,
			game->line_x * 64, "So_long");
	mlx_hook(game->win, 02, 1L, key_handler, game);
	mlx_hook(game->win, 17, 1L << 17, close_window, game);
	put_images (game);
	render_img(game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;
	int		fd;
	int		fd_x;
	int		fd_y;
	int		fd_map;

	fd_x = open(argv[1], O_RDONLY);
	fd_y = open(argv[1], O_RDONLY);
	fd_map = open(argv[1], O_RDONLY);
	check_args(&game, argc, argv);
	start_map(&game);
	game.score = collectible_counter(&game);
	game.line_x = get_line_size(&game, fd_y);
	game.col_y = get_col_size(&game, fd_x);
	fd = open(argv[1], O_RDONLY);
	get_maps(&game, fd);
	start_validations(&game, fd_map);
	if (game.col_y == -1)
		ft_exit("Error!\n", &game);
	close(fd_x);
	close(fd_y);
	close(fd);
	close(fd_map);
	player_position(&game);
	init_game(&game);
}
