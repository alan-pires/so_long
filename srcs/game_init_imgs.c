/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_imgs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 08:45:11 by apires-d          #+#    #+#             */
/*   Updated: 2021/09/09 17:53:27 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_imgs(t_game *g)
{
	g->ply.ref = mlx_xpm_file_to_image(
			g->mlx, PLAYER, &g->ply.width, &g->ply.height);
	g->ply.pixels = (int *)mlx_get_data_addr(
			g->ply.ref, &g->ply.bpp, &g->ply.line, &g->ply.end);
	g->empty.ref = mlx_xpm_file_to_image(
			g->mlx, EMPTY, &g->empty.width, &g->empty.height);
	g->empty.pixels = (int *)mlx_get_data_addr(
			g->empty.ref, &g->empty.bpp, &g->empty.line, &g->empty.end);
	g->wall.ref = mlx_xpm_file_to_image(
			g->mlx, WALL, &g->wall.width, &g->wall.height);
	g->wall.pixels = (int *)mlx_get_data_addr(
			g->wall.ref, &g->wall.bpp, &g->wall.line, &g->wall.end);
	g->collect.ref = mlx_xpm_file_to_image(
			g->mlx, COLLECT, &g->collect.width, &g->collect.height);
	g->collect.pixels = (int *)mlx_get_data_addr(
			g->collect.ref, &g->collect.bpp, &g->collect.line, &g->collect.end);
	g->exit.ref = mlx_xpm_file_to_image(
			g->mlx, EXIT, &g->exit.width, &g->exit.height);
	g->exit.pixels = (int *)mlx_get_data_addr(
			g->exit.ref, &g->exit.bpp, &g->exit.line, &g->exit.end);
}
