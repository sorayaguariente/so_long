/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_validations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguarien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:33:43 by sguarien          #+#    #+#             */
/*   Updated: 2023/05/29 14:33:44 by sguarien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_args(t_game *game, int argc, char **argv)
{
	if (argc != 2)
		ft_exit("Error\n Wrong number of arguments, try again!\n", game);
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4))
	{
		ft_printf("Error\n File must be of type \".ber\"\n");
		exit(0);
	}
}

static void	check_walls(t_game *game)
{
	int	i;
	int	c;

	i = 0;
	while (game->map[i])
	{
		c = 0;
		while (game->map[i][c])
		{
			if (game->map[0][c] != '1' || game->map[game->line_x - 1][c] != '1')
				ft_exit("Error\n The map is not surrounded by walls", game);
			if (game->map[i][0] != '1' || game->map[i][game->col_y - 1] != '1')
				ft_exit("Error\n The map is not surrounded by walls", game);
			c++;
		}
		i++;
	}
}

void	valid_map(t_game *game)
{
	int	col;
	int	line;
	int	size;

	col = 0;
	line = 0;
	size = ft_strlen(game->map[0]);
	while (game->map[line] != 0)
	{
		col = ft_strlen(game->map[line]);
		if (col != size)
			ft_exit("Error\n Your map is not rectangular", game);
		line++;
	}
	check_walls(game);
}

static void	check_char(t_game *game, char c, int line_x, int col_y)
{
	if (c == 'C')
		game->score++;
	else if (c == 'E')
		game->exit++;
	else if (c == 'P')
	{
		game->player++;
		game->player_x = col_y;
		game->player_y = line_x;
	}
	else if (c == '1' || c == '0')
		return ;
	else
		ft_exit("Error\n Invalid characters", game);
}

void	check_map(t_game *game)
{
	int	line_x;
	int	col_y;

	line_x = 0;
	while (game->map[line_x])
	{
		col_y = 0;
		while (game->map[line_x][col_y])
		{
			check_char(game, game->map[line_x][col_y], line_x, col_y);
			col_y++;
		}
		line_x++;
	}
	if (game->score == 0)
		ft_exit("Error\n There is no heart", game);
	else if (game->exit == 0)
		ft_exit("Error\n There is no rainbow", game);
	else if (game->exit > 1)
		ft_exit("Error\n Just one rainbow per map", game);
	else if (game->player == 0)
		ft_exit("Error\n There is no unicorn", game);
	else if (game->player > 1)
		ft_exit ("Error\n Just one unicorn per map", game);
}
