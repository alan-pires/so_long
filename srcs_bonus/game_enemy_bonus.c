/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_enemy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 23:33:30 by apires-d          #+#    #+#             */
/*   Updated: 2021/09/09 12:32:16 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	enemy_move_right(t_game *g);
static void	enemy_move_left(t_game *g);
static void	enemy_animat(t_game *g, char *img1, char *img2);

int	enemy_move(t_game *g)
{
	if (g->map.arr[(g->enemy.pos.y / BLOCK)][(g->enemy.pos.x / BLOCK) + 1] == '0'
		&& g->enemy.left == 0)
	{
		enemy_move_right(g);
		if (g->map.arr[(g->enemy.pos.y / BLOCK)][(g->enemy.pos.x / BLOCK) + 1] != '0')
			g->enemy.left = 1;
	}
	else if (g->map.arr[(g->enemy.pos.y / BLOCK)][(g->enemy.pos.x / BLOCK) - 1] == '0')
	{
		enemy_move_left(g);
		if (g->map.arr[(g->enemy.pos.y / BLOCK)][(g->enemy.pos.x / BLOCK) - 1] != '0')
			g->enemy.left = 0;
	}
	return (0);
}

static void	enemy_move_right(t_game *g)
{
	g->empty.pos.x = g->enemy.pos.x;
	g->empty.pos.y = g->enemy.pos.y;
	g->enemy.pos.x += BLOCK;
	enemy_animat(g, "sprites/gengar_r1.xpm", "sprites/gengar_r2.xpm");
}

static void	enemy_move_left(t_game *g)
{
	g->empty.pos.x = g->enemy.pos.x;
	g->empty.pos.y = g->enemy.pos.y;
	g->enemy.pos.x -= BLOCK;
	enemy_animat(g, "sprites/gengar_l1.xpm", "sprites/gengar_l2.xpm");
}

static void	enemy_animat(t_game *g, char *img1, char *img2)
{
	mlx_put_image_to_window(g->mlx, g->window.ref, g->empty.ref, g->empty.pos.x, g->empty.pos.y);
	if (g->enemy.animate % 2 == 0)
	{
		mlx_destroy_image(g->mlx, g->enemy.ref);
		g->enemy.ref = mlx_xpm_file_to_image(g->mlx, img1, &g->enemy.width, &g->enemy.height);
		g->enemy.pixels = (int *)mlx_get_data_addr(g->enemy.ref, &g->enemy.bpp, &g->enemy.line_size, &g->enemy.endian);
	}
	else
	{
		mlx_destroy_image(g->mlx, g->enemy.ref);
		g->enemy.ref = mlx_xpm_file_to_image(g->mlx, img2, &g->enemy.width, &g->enemy.height);
		g->enemy.pixels = (int *)mlx_get_data_addr(g->enemy.ref, &g->enemy.bpp, &g->enemy.line_size, &g->enemy.endian);
	}
	g->enemy.animate++;	
	mlx_put_image_to_window(g->mlx, g->window.ref, g->enemy.ref, g->enemy.pos.x, g->enemy.pos.y);
}
