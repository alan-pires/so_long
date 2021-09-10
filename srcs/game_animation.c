/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 11:16:58 by apires-d          #+#    #+#             */
/*   Updated: 2021/09/09 21:48:54 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	walk_animat(t_game *g, char *img1, char *img2)
{
	mlx_put_image_to_window(
		g->mlx, g->win.ref, g->empty.ref, g->empty.po.x, g->empty.po.y);
	if (g->ply.animate % 2 == 0)
	{
		mlx_destroy_image(g->mlx, g->ply.ref);
		g->ply.ref = mlx_xpm_file_to_image(
				g->mlx, img1, &g->ply.width, &g->ply.height);
		g->ply.pixels = (int *)mlx_get_data_addr(
				g->ply.ref, &g->ply.bpp, &g->ply.line, &g->ply.end);
	}
	else
	{
		mlx_destroy_image(g->mlx, g->ply.ref);
		g->ply.ref = mlx_xpm_file_to_image(
				g->mlx, img2, &g->ply.width, &g->ply.height);
		g->ply.pixels = (int *)mlx_get_data_addr(
				g->ply.ref, &g->ply.bpp, &g->ply.line, &g->ply.end);
	}
	g->ply.animate++;
	mlx_put_image_to_window(
		g->mlx, g->win.ref, g->ply.ref, g->ply.po.x, g->ply.po.y);
}
