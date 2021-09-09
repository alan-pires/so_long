/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 16:20:37 by apires-d          #+#    #+#             */
/*   Updated: 2021/09/09 15:53:35 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_exit(t_game *game)
{
	if (game->to_collect == 0)
	{
		game->steps++;
		printf("%d\n", game->steps);
		free_map(game);
		printf("\nYou won!\n\n");
		exit(0);
	}
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	if (game->map.arr)
	{
		while (i < game->map.lines)
		{
			free(game->map.arr[i]);
			i++;
		}
		free(game->map.arr);
	}
}

void	exit_err(t_game *game, char *msg)
{
	free_map(game);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putchar_fd('\n', 2);
	exit(0);
}

int	exit_game(t_game *game)
{
	free_map(game);
	exit(0);
}
