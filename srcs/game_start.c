/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 11:46:26 by apires-d          #+#    #+#             */
/*   Updated: 2021/09/05 09:53:20 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	check_args(int argc)
{
	if (argc != 2)
	{
		printf("Wrong number of arguments. You must input a map.ber file.\n");
		exit(0);
	}
}

static	void	init_win(t_game *game)
{
	game->mlx = mlx_init();
	game->window.ref = mlx_new_window(game->mlx, BLOCK * game->map.cols,
		BLOCK * game->map.lines, "so_long");
}

void	game_start(t_game *game, int argc, char **argv)
{
	check_args(argc);
	check_map(game, argv);
	init_win(game);
	init_imgs(game);
	//dpois fazer funçao para as inicializações:
	game_display(game);
	//depois criar função para tratar os loopings
	mlx_loop_hook(game->mlx, *game_display, game);
	mlx_loop(game->mlx);
}
