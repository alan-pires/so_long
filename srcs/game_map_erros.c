/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map_erros.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 21:55:43 by apires-d          #+#    #+#             */
/*   Updated: 2021/09/06 00:31:36 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	check_wall_erros(t_game *game);
static void	check_wall(char *line);
static void	check_updown(char *line);

void	check_map_errors(t_game *game)
{
	size_t	aux;
	int	i;

	i = 0;
	aux = ft_strlen(game->map.arr[0]);
	if (!aux)
	{
		printf("Map is empty...\n");
		exit(0);
	}
	while (i < game->map.lines)
	{
		if (aux != ft_strlen(game->map.arr[i]))
		{
			printf("The Map must be a rectangle\n");
			exit(0);
		}
		i++;
	}
	check_wall_erros(game);
}

static void	check_wall_erros(t_game *game)
{
	int	i;
	int	j;
	
	i = 1;
	j = 0;
	check_updown(game->map.arr[0]);
	while (i < game->map.lines - 1)
	{
		check_wall(game->map.arr[i]);
		i++;
	}
	check_updown(game->map.arr[i]);
}

static void	check_wall(char *line)
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
	{
		printf("Map must be surronded by walls.\n");
		exit(0);
	}
}

static void	check_updown(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
		{
			printf("Map must be surronded by walls.\n");
			exit(0);
		}
		i++;
	}
}