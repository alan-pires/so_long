/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 16:20:37 by apires-d          #+#    #+#             */
/*   Updated: 2021/09/06 22:08:39 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_exit(t_game *game)
{
	if (game->to_collect == 0)
	{
		printf("ganhou!\n");
		exit(0);
	}
}

void	free_map(t_map *map, char **str)
{
	int	i;

	i = 0;
	while (i <= map->lines)
		free(str[i++]);
	free(str);
	str = NULL;
}

