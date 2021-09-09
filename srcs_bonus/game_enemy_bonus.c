/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_enemy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 23:33:30 by apires-d          #+#    #+#             */
/*   Updated: 2021/09/09 18:16:03 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	enemy_move_right(t_game *g, t_sprite *e);
static void	enemy_move_left(t_game *g, t_sprite *e);
static void	enemy_animat(t_game *g, char *img1, char *img2, t_sprite *e);

int	enemy_move(t_game *g, t_sprite *e)
{
	if (g->map.arr[(e->po.y / BLOCK)][(e->po.x / BLOCK) + 1] == '0'
		&& e->left == 0)
	{
		enemy_move_right(g, e);
		if (g->map.arr[(e->po.y / BLOCK)][(e->po.x / BLOCK) + 1] != '0')
			e->left = 1;
	}
	else if (g->map.arr[(e->po.y / BLOCK)][(e->po.x / BLOCK) - 1] == '0')
	{
		enemy_move_left(g, e);
		if (g->map.arr[(e->po.y / BLOCK)][(e->po.x / BLOCK) - 1] != '0')
			e->left = 0;
	}
	return (0);
}

static void	enemy_move_right(t_game *g, t_sprite *e)
{
	g->empty.po.x = e->po.x;
	g->empty.po.y = e->po.y;
	e->po.x += BLOCK;
	enemy_animat(g, "sprites/gengar_r1.xpm", "sprites/gengar_r2.xpm", e);
}

static void	enemy_move_left(t_game *g, t_sprite *e)
{
	g->empty.po.x = e->po.x;
	g->empty.po.y = e->po.y;
	e->po.x -= BLOCK;
	enemy_animat(g, "sprites/gengar_l1.xpm", "sprites/gengar_l2.xpm", e);
}

static void	enemy_animat(t_game *g, char *img1, char *img2, t_sprite *e)
{
	mlx_put_image_to_window(
		g->mlx, g->win.ref, g->empty.ref, g->empty.po.x, g->empty.po.y);
	if (e->animate % 2 == 0)
	{
		mlx_destroy_image(g->mlx, e->ref);
		e->ref = mlx_xpm_file_to_image(g->mlx, img1, &e->width, &e->height);
		e->pixels = (int *)mlx_get_data_addr(
				e->ref, &e->bpp, &e->line, &e->endian);
	}
	else
	{
		mlx_destroy_image(g->mlx, e->ref);
		e->ref = mlx_xpm_file_to_image(g->mlx, img2, &e->width, &e->height);
		e->pixels = (int *)mlx_get_data_addr(
				e->ref, &e->bpp, &e->line, &e->endian);
	}
	e->animate++;
	mlx_put_image_to_window(g->mlx, g->win.ref, e->ref, e->po.x, e->po.y);
}
