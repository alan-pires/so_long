/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 11:46:26 by apires-d          #+#    #+#             */
/*   Updated: 2021/09/05 19:52:20 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	check_args(int argc);
static void	init_win(t_game *game);
static void	init_game_opt(t_game *game);

void	game_start(t_game *game, int argc, char **argv)
{
	check_args(argc);
	check_map(game, argv);
	init_win(game);
	init_imgs(game);
	init_game_opt(game);
	game_display(game);
	mlx_key_hook(game->window.ref, ft_move, game);
	mlx_loop(game->mlx);
}

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

static void	init_game_opt(t_game *game)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (i < game->map.lines)
	{
		j = 0;
		while (j < game->map.cols)
		{
			if (game->map.array[i][j] == 'P')
			{
				game->player.pos.x = i;
				game->player.pos.y = j;
			}
			j++;
		}
		i++;
	}
	game->collected = 0;
	game->steps = 0;
}
