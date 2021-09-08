/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 16:20:37 by apires-d          #+#    #+#             */
/*   Updated: 2021/09/08 00:34:06 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_exit(t_game *game)
{
	if (game->to_collect == 0)
	{
		free_map(&game->map, game->map.arr);
		printf("ganhou!\n");
		exit(0);
	}
}

void	free_map(t_map *game_map, char **map)
{
	int	i;

	i = 0;
	if (map != NULL)
	{
		while (i < game_map->lines)
			free(map[i++]);
		free(map);
		map = NULL;
	}
}

// ver depois
// static void	print_error(char *message)
// {
// 	ft_putstr_fd("Error\n", 2);
// 	ft_putstr_fd(message, 2);
// 	ft_putchar_fd('\n', 2);
// }