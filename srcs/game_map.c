/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 12:06:30 by apires-d          #+#    #+#             */
/*   Updated: 2021/08/31 14:20:34 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	count_lines(char **argv)
{
	char	*line;
	int		i;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line))
		i++;
	close(fd);
	return (i);
}

int	check_map(t_game *game, char **argv)
{
	char	**array;
	int		i = 0;
	int		fd;
	int		lines;
	int		cols;
	
	lines = count_lines(argv);
	array = malloc(sizeof(char *) * lines + 1);
	if (!array)
		return (0);

	// check if there are the minimal number of blocks of each type
	
	fd = open(argv[1], O_RDONLY);
	while (i < lines)
	{
		get_next_line(fd, &array[i]);
		printf("%s\n", array[i]);
		i++;
	}
	cols = (int)ft_strlen(array[0]);
	game->map.column = cols;
	game->map.line = lines;
	
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
