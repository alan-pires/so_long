/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map_erros.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 21:55:43 by apires-d          #+#    #+#             */
/*   Updated: 2021/09/09 15:42:33 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	check_wall_erros(t_game *game);
static void	check_wall(t_game *game, char *line);
static void	check_updown(t_game *game, char *line);
static void	check_sprites(t_game *game);

void	check_map_errors(t_game *game)
{
	size_t	aux;
	int	i;

	i = 0;
	aux = ft_strlen(game->map.arr[0]);
	if (!aux)
		exit_err(game, "Map is empty.");
	while (i < game->map.lines)
	{
		if (aux != ft_strlen(game->map.arr[i]))
			exit_err(game, "The Map must be a rectangle");
		i++;
	}
	check_sprites(game);
	check_wall_erros(game);
}

static void	check_wall_erros(t_game *game)
{
	int	i;
	
	i = 1;
	check_updown(game, game->map.arr[0]);
	while (i < game->map.lines - 1)
	{
		check_wall(game, game->map.arr[i]);
		i++;
	}
	check_updown(game, game->map.arr[i]);
}

static void	check_wall(t_game *game, char *line)
{
	int i;
	int err;

	i = 1;
	err = 0;
	if (line[0] != '1')
		err++;
	while (line[i])
		i++;
	if (line[i - 1] != '1')
		err++;
	if (err > 0)
		exit_err(game, "Map must be surronded by walls.");
}

static void	check_updown(t_game *game, char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			exit_err(game, "Map must be surronded by walls.");
		i++;
	}
}

static void	check_sprites(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.lines)
	{
		j = 0;
		while (j < game->map.cols)
		{
			if (game->map.arr[i][j] != '1' && game->map.arr[i][j] != '0'
				&& game->map.arr[i][j] != 'P' && game->map.arr[i][j] != 'C'
				&& game->map.arr[i][j] != 'E')
					exit_err(game, "Invalid map.");
			j++;
		}
		i++;
	}
}