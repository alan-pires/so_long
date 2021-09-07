/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 12:06:30 by apires-d          #+#    #+#             */
/*   Updated: 2021/09/07 01:11:51 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	alloc_array(t_game *game);
static int	hastype(t_game *game, char type);
static int	check_imgtypes(t_game *game);
static int	init_array_lc(t_game *game, char **argv);

int	check_map(t_game *game, char **argv)
{
	int	i;
	int	fd;

	i = 0;
	init_array_lc(game, argv);
	alloc_array(game);
	fd = open(argv[1], O_RDONLY);
	while (i < game->map.lines)
	{
		get_next_line(fd, &game->map.arr[i]);
		i++;
	}
	if (check_imgtypes(game) == 0)
	{
		printf("The Map needs to contain all necessary sprites\n");
		free_map(&game->map, game->map.arr);
		exit (0);
	}
	//free(game->map.arr);
	check_map_errors(game);
	close(fd);
	return (0);
}

static int	init_array_lc(t_game *game, char **argv)
{
	char	*line;
	int		i;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line))
		i++;
	game->map.lines = i + 1;
	game->map.cols = ft_strlen(line);
	close(fd);
	free(line);
	return (0);
}

static void	alloc_array(t_game *game)
{
	int	i;

	i = 0;
	game->map.arr = malloc(sizeof(char *) * game->map.lines);
	if (game->map.arr)
	{
		while (i < game->map.lines)
		{
			game->map.arr[i] = malloc(sizeof(char *) * game->map.cols);
			if (game->map.arr[i])
				i++;
		}
	}
	free_map(&game->map, game->map.arr);
}

static int	check_imgtypes(t_game *game)
{
	if (hastype(game, '1') == 0 || hastype(game, '0') == 0
		|| hastype(game, 'C') == 0 || hastype(game, 'E') == 0
		|| hastype(game, 'P') == 0)
		return (0);
	return (1);
}

static int	hastype(t_game *game, char type) // dar os frees necessários
{
	int		i;
	char	**aux;
	int		res;

	aux = NULL;
	i = 0;
	res = 0;
	aux = malloc(sizeof(char *) * game->map.lines);
	if (aux)
	{
		while (i < game->map.lines)
		{
			aux[i] = malloc(sizeof(char *) * game->map.cols);
			if (aux[i])
				i++;
		}
	}
	i = -1;
	while (++i < game->map.lines)
		aux[i] = ft_strchr(game->map.arr[i], type);
	while (--i >= 0)
		if (aux[i])
			res++;
	// while (aux[i++])
	// 	free(aux[i]);
	free(aux);
	return (res);
}
