/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 16:20:37 by apires-d          #+#    #+#             */
/*   Updated: 2021/09/07 01:29:27 by apires-d         ###   ########.fr       */
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
