/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_print_moves.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 12:57:37 by apires-d          #+#    #+#             */
/*   Updated: 2021/09/09 13:04:08 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	print_moves(t_game *game)
{
	char	*moves;
	//char	*aux;

	//aux = malloc()
	moves = ft_itoa(game->ply.steps);
	if (!moves)
		exit_err(game, "Something went wrong with memory allocation.");
	mlx_string_put(game->mlx, game->window.ref, 20, 15, 0xff6700,
		moves);
	free(moves);
}