/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 12:06:30 by apires-d          #+#    #+#             */
/*   Updated: 2021/09/03 15:41:46 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	alloc_array(t_game *game)
{
	int	i;

	i = 0;
	game->map.array = malloc(sizeof(char *) * game->map.lines + 1);
	if (game->map.array)
	{
		while (i < game->map.lines)
		{
			game->map.array[i] = malloc(sizeof(char *) * game->map.cols + 1);
			if (game->map.array[i])
				i++;
		}		
	}
}

static int	hastype(t_game *game, char type) // dar os frees necessários
{
	int		i;
	char	**aux;

	aux = NULL;
	i = 0;
	aux = malloc(sizeof(char *) * game->map.lines + 1);
	if (aux)
	{
		while (i < game->map.lines)
		{
			aux[i] = malloc(sizeof(char *) * game->map.cols + 1);
			if (aux[i])
				i++;
		}
	}
	i = -1;
	while (++i < game->map.lines)
		aux[i] = ft_strchr(game->map.array[i], type);
	while (--i >= 0)
		if (aux[i])
			return (1);
	return (0);
}

static int	check_imgtypes(t_game *game)
{
	if (hastype(game, '1') == 0 || hastype(game, '0') == 0
		|| hastype(game, 'C') == 0 || hastype(game, 'E') == 0
		|| hastype(game, 'P') == 0)
		return (0);
	return (1);
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
	game->map.lines = i;
	game->map.cols = ft_strlen(line);
	close(fd);
	//free(line);
	return (0);
}


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
		get_next_line(fd, &game->map.array[i]);
		// printf("%s\n", game->map.array[i]);
		i++;
	}
	if (check_imgtypes(game) == 0)
	{
		printf("Invalid Map... It needs to contain all necessary type of sprites\n");
		exit (0);
	}
	
	// check if all the lines are the same size...
	// free all the necessary stuff.
	// i = 0;
	// while (i < mapsize)
	// {
	// free(&array[i]);
	// i++;
	// }
	close(fd);
	return (0);
}
