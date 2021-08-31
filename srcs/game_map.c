/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 12:06:30 by apires-d          #+#    #+#             */
/*   Updated: 2021/08/31 14:44:44 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	count_lc(t_game *game, char **argv)
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
	return (0);
}

int	check_map(t_game *game, char **argv)
{
	char	**array;
	int		i = 0;
	int		fd;
	
	count_lc(game, argv);
	
	// FAZER MALLOC DOS ARRAYS DENTRO DO ARRAY MAIOR PAREI AQUI....
	game->map.array = malloc(sizeof(char *) * game->map.lines);
	while ()
	
	array = malloc(sizeof(char *) * game->map.cols + 1);
	if (!array)
		return (0);

	// check if there are the minimal number of blocks of each type
	
	fd = open(argv[1], O_RDONLY);
	while (i < lines)
	{
		get_next_line(fd, &array[i]);
		// game->map.array[i] = ft_strjoin(game->map.array[i], array[i]);
		
		printf("%s\n", game->map.array[i]);
		i++;
	}
	cols = (int)ft_strlen(array[0]);
	
	// check if all the lines are the same size...
	
	// i = 0;
	// while (i < mapsize)
	// {
	// free(&array[i]);
	// i++;
	// }
	close(fd);
	return (0);
}
