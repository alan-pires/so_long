/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_print_moves_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 12:57:37 by apires-d          #+#    #+#             */
/*   Updated: 2021/09/09 15:02:00 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	print_moves(t_game *g)
{
	char	*moves;

	moves = ft_itoa(g->ply.steps);
	if (!moves)
		exit_err(g, "Something went wrong with memory allocation.");
	mlx_put_image_to_window(g->mlx, g->window.ref, g->wall.ref, 0, 0);
	mlx_put_image_to_window(g->mlx, g->window.ref, g->wall.ref, 50, 0);
	mlx_string_put(g->mlx, g->window.ref, 10, 15, 0xFF0000,
		"STEPS: ");
	mlx_string_put(g->mlx, g->window.ref, 50, 15, 0xFF0000,
		moves);
	free(moves);
}