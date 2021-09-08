/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 11:46:26 by apires-d          #+#    #+#             */
/*   Updated: 2021/09/08 12:15:05 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	init_opt(t_game *game);
static void	check_args(int argc, char **argv);
static void	init_win(t_game *game);
static void	init_position(t_game *game);
static int	exit_game(t_game *game);

void	game_start(t_game *game, int argc, char **argv)
{
	check_args(argc, argv);
	init_opt(game);
	check_map(game, argv);
	init_position(game);
	init_win(game);
	init_imgs(game);
	game_display(game);
	mlx_key_hook(game->window.ref, ft_move, game);
	mlx_hook(game->window.ref, EXIT_GAME, 0, exit_game, game);
	mlx_loop(game->mlx);
	// mlx_destroy_window(game->mlx, game->window.ref);
	// mlx_destroy_display(game->mlx);
	free(game->mlx);
}

static void	init_opt(t_game *game)
{
	game->steps = 0;
	game->to_collect = 0;
	game->ply.animate = 0;
	game->map.arr = NULL;
}

static void	init_position(t_game *game)
{
	int i;
	int j;

	i = 0;
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

static void	check_args(int argc, char **argv)
{
	unsigned int i;
	char		*aux;
	
	i = 0;
	if (argc != 2)
	{
		printf("Wrong number of arguments. You must input a map.ber file.\n");
		exit(0);
	}
	while (argv[1][i])
		i++;
	i -= 4;
	aux = ft_substr(argv[1], i, 4);
	if (ft_strncmp(aux,".ber", 4) != 0)
	{
		printf("You must enter a .ber file to be read\n");
		exit(0);
	}
	free(aux);
}

static	void	init_win(t_game *game)
{
	game->mlx = mlx_init();
	game->window.ref = mlx_new_window(game->mlx, BLOCK * game->map.cols,
		BLOCK * game->map.lines, "so_long");
}

static int	exit_game(t_game *game)
{
	free_map(game);
	exit(0);
}
