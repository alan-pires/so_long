/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 11:46:26 by apires-d          #+#    #+#             */
/*   Updated: 2021/08/31 17:32:59 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	init_win(t_game *game)
{
	game->mlx = mlx_init();
	game->window.ref = mlx_new_window(game->mlx, BLOCK * game->map.cols,
		BLOCK * game->map.lines, "so_long");
}

void	game_start(t_game *game, int argc, char **argv)
{
	// check arguments, check argc...
	check_map(game, argv);
	init_win(game);
	
	mlx_loop(game->mlx);
}
