/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguarien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:24:47 by sguarien          #+#    #+#             */
/*   Updated: 2023/05/29 16:24:48 by sguarien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	render_img(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->line_x)
	{
		x = 0;
		while (x < game->col_y)
		{
			put_map(x, y, game->map[y][x], game);
			x++;
		}
		y++;
	}
	return (0);
}
