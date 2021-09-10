/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 11:46:26 by apires-d          #+#    #+#             */
/*   Updated: 2021/09/10 14:32:27 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	init_opt(t_game *game);
static void	check_args(int argc, char **argv);
static void	init_win(t_game *game);
static void	init_position(t_game *game);

void	game_start(t_game *game, int argc, char **argv)
{
	check_args(argc, argv);
	init_opt(game);
	check_map(game, argv);
	init_position(game);
	init_win(game);
	init_imgs(game);
	game_display(game);
	mlx_expose_hook(game->win, game_display, game);
	mlx_key_hook(game->win, ft_move, game);
	mlx_hook(game->win, EXIT_GAME, 0, exit_game, game);
	mlx_loop(game->mlx);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}

static void	init_opt(t_game *game)
{
	game->ply.steps = 0;
	game->enemy.left = 0;
	game->to_coll = 0;
	game->ply.animate = 0;
	game->map.arr = NULL;
}

static void	init_position(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.lines)
	{
		j = 0;
		while (j < game->map.cols)
		{
			if (game->map.arr[i][j] == 'P')
			{
				game->ply.po.x = i;
				game->ply.po.y = j;
			}
			if (game->map.arr[i][j] == 'G')
			{
				game->enemy.po.x = i;
				game->enemy.po.y = j;
			}
			if (game->map.arr[i][j] == 'C')
				game->to_coll++;
			j++;
		}
		i++;
	}
}

static void	check_args(int argc, char **argv)
{
	unsigned int	i;
	char			*aux;

	i = 0;
	if (argc != 2)
	{
		printf("Error\n");
		printf("Wrong number of arguments. You must input a map.ber file.\n");
		exit(0);
	}
	while (argv[1][i])
		i++;
	i -= 4;
	aux = ft_substr(argv[1], i, 4);
	if (ft_strncmp(aux, ".ber", 4) != 0)
	{
		printf("Error\n");
		printf("You must enter a .ber file to be read\n");
		free(aux);
		exit(0);
	}
	free(aux);
}

static	void	init_win(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, BLOCK * game->map.cols,
			BLOCK * game->map.lines, "so_long");
}
