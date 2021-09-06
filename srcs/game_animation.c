/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 11:16:58 by apires-d          #+#    #+#             */
/*   Updated: 2021/09/06 12:13:24 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	walk_animat(t_game *g, char *img1, char *img2)
{
	mlx_put_image_to_window(g->mlx, g->window.ref, g->empty.ref, g->empty.pos.x, g->empty.pos.y);
	if (g->ply.animate % 2 == 0)
	{
		//mlx_destroy_image(g->mlx, g->ply.ref);
		g->ply.ref = mlx_xpm_file_to_image(g->mlx, img1, &g->ply.width, &g->ply.height);
		g->ply.pixels = (int *)mlx_get_data_addr(g->ply.ref, &g->ply.bpp, &g->ply.line_size, &g->ply.endian);
	}
	else
	{
		//mlx_destroy_image(g->mlx, g->ply.ref);
		g->ply.ref = mlx_xpm_file_to_image(g->mlx, img2, &g->ply.width, &g->ply.height);
		g->ply.pixels = (int *)mlx_get_data_addr(g->ply.ref, &g->ply.bpp, &g->ply.line_size, &g->ply.endian);
	}
	g->ply.animate++;
	mlx_put_image_to_window(g->mlx, g->window.ref, g->ply.ref, g->ply.pos.x, g->ply.pos.y);
}
