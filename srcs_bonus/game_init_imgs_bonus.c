/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_imgs_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 08:45:11 by apires-d          #+#    #+#             */
/*   Updated: 2021/09/09 18:17:23 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	init_imgs(t_game *g)
{
	g->ply.ref = mlx_xpm_file_to_image(
			g->mlx, PLAYER, &g->ply.width, &g->ply.height);
	g->ply.pixels = (int *)mlx_get_data_addr(
			g->ply.ref, &g->ply.bpp, &g->ply.line, &g->ply.endian);
	g->empty.ref = mlx_xpm_file_to_image(
			g->mlx, EMPTY, &g->empty.width, &g->empty.height);
	g->empty.pixels = (int *)mlx_get_data_addr(
			g->empty.ref, &g->empty.bpp, &g->empty.line, &g->empty.endian);
	g->wall.ref = mlx_xpm_file_to_image(
			g->mlx, WALL, &g->wall.width, &g->wall.height);
	g->wall.pixels = (int *)mlx_get_data_addr(
			g->wall.ref, &g->wall.bpp, &g->wall.line, &g->wall.endian);
	g->coll.ref = mlx_xpm_file_to_image(
			g->mlx, COLLECT, &g->coll.width, &g->coll.height);
	g->coll.pixels = (int *)mlx_get_data_addr(
			g->coll.ref, &g->coll.bpp, &g->coll.line, &g->coll.endian);
	g->exit.ref = mlx_xpm_file_to_image(
			g->mlx, EXIT, &g->exit.width, &g->exit.height);
	g->exit.pixels = (int *)mlx_get_data_addr(
			g->exit.ref, &g->exit.bpp, &g->exit.line, &g->exit.endian);
	g->enemy.ref = mlx_xpm_file_to_image(
			g->mlx, ENEMY, &g->enemy.width, &g->enemy.height);
	g->enemy.pixels = (int *)mlx_get_data_addr(
			g->enemy.ref, &g->enemy.bpp, &g->enemy.line, &g->enemy.endian);
}
