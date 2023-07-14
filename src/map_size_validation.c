/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguarien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:17:07 by sguarien          #+#    #+#             */
/*   Updated: 2023/05/29 12:17:09 by sguarien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	get_col_size(t_game *game, int fd)
{
	char	*c;
	int		y;
	int		temp;

	(void)game;
	c = get_next_line(fd);
	y = ft_strlen(c)-1;
	temp = y;
	free(c);
	if (fd < 0)
		ft_exit("Error\n The fd is empty!\n", game);
	while (1)
	{
		c = get_next_line(fd);
		if (!c)
			break ;
		y = ft_strlen(c) - 1;
		if (temp != y)
			return (-1);
		free(c);
	}
	return (y);
}

int	get_line_size(t_game *game, int fd)
{
	char	*c;
	int		x;

	x = 0;
	(void)game;
	while (1)
	{
		c = get_next_line(fd);
		if (!c)
			break ;
		x++;
		free(c);
	}
	if (x == 0)
	{
		ft_printf("Error\n The file is empty or do not exist!\n");
		exit(0);
	}
	return (x);
}
