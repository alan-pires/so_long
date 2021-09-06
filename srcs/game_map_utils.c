/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 21:55:43 by apires-d          #+#    #+#             */
/*   Updated: 2021/09/05 22:24:31 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
}