/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 12:06:30 by apires-d          #+#    #+#             */
/*   Updated: 2021/09/08 00:33:09 by apires-d         ###   ########.fr       */
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
	if (fd < 0)
	{
		printf("A valid file was not found.\n");
		free_map(&game->map, game->map.arr);
		exit (0);
	}
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
	check_map_errors(game);
	close(fd);
	return (0);
}

//========================================================================================
// static int	ft_read(int fd, int *len)
// {
// 	int		size;
// 	char	buff;

// 	size = read(fd, &buff, 1);
	
// 	while ()
// }

static int	init_array_lc(t_game *game, char **argv) // funçao que estava funcionando
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
	game->map.lines = i + 1;
	game->map.cols = len;
	close(fd);
	return (0);
}
//=========================================================================

// static int	init_array_lc(t_game *game, char **argv)
// {
// 	int		fd;
// 	int		size;
// 	char	buff;

// 	fd = open(argv[1], O_RDONLY);
// 	size = read(fd, &buff, 1);
// 	if (size < 0)
// 	{
// 		printf("File is empty.\n");
// 		exit(0);
// 	}
// 	while (size > 0)
// 	{
// 		if (buff == '\n')
// 			game->map.lines++;
// 		else
// 			game->map.cols++;
// 		size = read(fd, &buff, 1);
// 	}
// 	game->map.cols /= game->map.lines;	
// 	close(fd);
// 	printf("lines: %d\n", game->map.lines);
// 	printf("cols: %d\n", game->map.cols);
// 	return (0);
// }

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
	else
	{
		while (i < game->map.lines)
		{
			game->map.arr[i] = malloc(sizeof(char *) * game->map.cols);
			if (game->map.arr[i])
			{
				game->map.arr[i] = NULL;
				i++;
			}
		}
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
