/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 16:20:37 by apires-d          #+#    #+#             */
/*   Updated: 2021/09/08 15:43:56 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_exit(t_game *game)
{
	if (game->to_collect == 0)
	{
		free_map(game);
		printf("ganhou!\n");
		exit(0);
	}
}

// void	free_map(t_game *game)
// {
// 	int	i;

// 	i = 0;
// 	i++;
// }

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





// ver depois
// static void	print_error(char *message)
// {
// 	ft_putstr_fd("Error\n", 2);
// 	ft_putstr_fd(message, 2);
// 	ft_putchar_fd('\n', 2);
// }