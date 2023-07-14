/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_validations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguarien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:29:53 by sguarien          #+#    #+#             */
/*   Updated: 2023/05/29 14:29:54 by sguarien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	start_validations(t_game *game, int fd)
{
	ft_printf("Starting Validations...\n");
	check_map(game);
	valid_map(game);
	valid_path(game, fd);
}
