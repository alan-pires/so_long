/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 11:46:26 by apires-d          #+#    #+#             */
/*   Updated: 2021/09/06 14:44:08 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	check_args(int argc, char **argv);
static void	init_win(t_game *game);
static void	init_game_opt(t_game *game);
static int	exit_game();

void	game_start(t_game *game, int argc, char **argv)
{
	check_args(argc, argv);
	check_map(game, argv);
	init_win(game);
	init_imgs(game);
	init_game_opt(game);
	game_display(game);
	mlx_key_hook(game->window.ref, ft_move, game);
	mlx_hook(game->window.ref, EXIT_GAME, 0, exit_game, game);
	mlx_loop(game->mlx);
}

static void	check_args(int argc, char **argv)
{
	unsigned int i;
	
	i = 0;
	if (argc != 2)
	{
		printf("Wrong number of arguments. You must input a map.ber file.\n");
		exit(0);
	}
	while (argv[1][i])
		i++;
	i -= 4; 
	if (ft_strncmp(ft_substr(argv[1], i, 4),".ber", 4) != 0)
	{
		printf("You must enter a .ber file to be read\n");
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
	game->steps = 0;
	game->to_collect = 0;
	game->ply.animate = 0;
	while (i < game->map.lines)
	{
		j = 0;
		while (j < game->map.cols)
		{
			if (game->map.arr[i][j] == 'P')
			{
				game->ply.pos.x = i;
				game->ply.pos.y = j;
			}
			if (game->map.arr[i][j] == 'C')
				game->to_collect++;
			j++;
		}
		i++;
	}
}

static int	exit_game()
{
	exit(0);
}
