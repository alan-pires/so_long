/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 12:06:30 by apires-d          #+#    #+#             */
/*   Updated: 2021/09/08 16:16:14 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	alloc_array(t_game *game);
static int	hastype(t_game *game, char type);
static int	check_imgtypes(t_game *game);
static int	init_lc(t_game *game, char **argv);

int	check_map(t_game *game, char **argv)
{
	int	i;
	int	fd;

	i = 0;
	init_lc(game, argv);
	alloc_array(game);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit_err(game, "A valid file was not found");
	while (i < game->map.lines)
	{
		get_next_line(fd, &game->map.arr[i]);
		i++;
	}
	close(fd);
	if (check_imgtypes(game) == 0)
		exit_err(game, "Map needs to contain all necessary sprites");
	check_map_errors(game);
	return (0);
}

static int	init_lc(t_game *game, char **argv) // funçao que estava funcionando
{
	char	*line;
	int		i;
	int		fd;
	int		len;

	fd = open(argv[1], O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line))
	{
		len = ft_strlen(line);
		free(line);
		i++;
	}
	free(line);
	game->map.lines = i + 1;
	game->map.cols = len;
	close(fd);
	return (0);
}

static void	alloc_array(t_game *game)
{
	int	i;

	i = 0;
	game->map.arr = malloc(sizeof(char *) * game->map.lines);
	if (!game->map.arr)
	{
		printf("Failed to allocate memory.\n");
		exit(0);
	}
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
	int		res;

	i = 0;
	res = 0;
	while (i < game->map.lines)
	{
		if(ft_strchr(game->map.arr[i], type) != NULL)
			res++;
		i++;
	}
	return (res);
}
