/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_movement_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 14:26:08 by apires-d          #+#    #+#             */
/*   Updated: 2021/09/09 20:57:31 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	move_up(t_game *game);
static void	move_down(t_game *game);
static void	move_right(t_game *game);
static void	move_left(t_game *game);

int	ft_move(int key, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (key == ESC)
		exit_game(game);
	if (key == UP)
		move_up(game);
	else if (key == DOWN)
		move_down(game);
	else if (key == RIGHT)
		move_right(game);
	else if (key == LEFT)
		move_left(game);
	return (0);
}

static void	move_up(t_game *g)
{
	if (g->map.arr[(g->ply.po.y / BLOCK) - 1][g->ply.po.x / BLOCK] != '1')
	{
		if (g->map.arr[(g->ply.po.y / BLOCK) - 1][g->ply.po.x / BLOCK] != 'E')
		{
			g->ply.steps++;
			print_moves(g);
		}
		if (g->map.arr[(g->ply.po.y / BLOCK) - 1][g->ply.po.x / BLOCK] == 'G')
			die(g);
		if (g->map.arr[(g->ply.po.y / BLOCK) - 1][g->ply.po.x / BLOCK] == 'C')
		{
			g->map.arr[(g->ply.po.y / BLOCK) - 1][g->ply.po.x / BLOCK] = '0';
			g->to_coll--;
		}
		if (g->map.arr[(g->ply.po.y / BLOCK) - 1][g->ply.po.x / BLOCK] == 'E')
			check_exit(g);
		if (g->map.arr[(g->ply.po.y / BLOCK) - 1][g->ply.po.x / BLOCK] != 'E')
		{
			g->empty.po.x = g->ply.po.x;
			g->empty.po.y = g->ply.po.y;
			g->ply.po.y -= BLOCK;
			walk_animat(g, "sprites/pu1.xpm", "sprites/pu2.xpm");
		}
	}
}

static void	move_down(t_game *g)
{
	if (g->map.arr[(g->ply.po.y / BLOCK) + 1][g->ply.po.x / BLOCK] != '1')
	{
		if (g->map.arr[(g->ply.po.y / BLOCK) + 1][g->ply.po.x / BLOCK] != 'E')
		{
			g->ply.steps++;
			print_moves(g);
		}
		if (g->map.arr[(g->ply.po.y / BLOCK) + 1][g->ply.po.x / BLOCK] == 'G')
			die(g);
		if (g->map.arr[(g->ply.po.y / BLOCK) + 1][g->ply.po.x / BLOCK] == 'C')
		{
			g->map.arr[(g->ply.po.y / BLOCK) + 1][g->ply.po.x / BLOCK] = '0';
			g->to_coll--;
		}
		if (g->map.arr[(g->ply.po.y / BLOCK) + 1][g->ply.po.x / BLOCK] == 'E')
			check_exit(g);
		if (g->map.arr[(g->ply.po.y / BLOCK) + 1][g->ply.po.x / BLOCK] != 'E')
		{
			g->empty.po.x = g->ply.po.x;
			g->empty.po.y = g->ply.po.y;
			g->ply.po.y += BLOCK;
			walk_animat(g, "sprites/pd1.xpm", "sprites/pd2.xpm");
		}
	}
}

static void	move_right(t_game *g)
{
	if (g->map.arr[g->ply.po.y / BLOCK][(g->ply.po.x / BLOCK) + 1] != '1')
	{
		if (g->map.arr[g->ply.po.y / BLOCK][(g->ply.po.x / BLOCK) + 1] != 'E')
		{
			g->ply.steps++;
			print_moves(g);
		}
		if (g->map.arr[g->ply.po.y / BLOCK][(g->ply.po.x / BLOCK) + 1] == 'G')
			die(g);
		if (g->map.arr[g->ply.po.y / BLOCK][(g->ply.po.x / BLOCK) + 1] == 'C')
		{
			g->map.arr[g->ply.po.y / BLOCK][(g->ply.po.x / BLOCK) + 1] = '0';
			g->to_coll--;
		}
		if (g->map.arr[g->ply.po.y / BLOCK][(g->ply.po.x / BLOCK) + 1] == 'E')
			check_exit(g);
		if (g->map.arr[g->ply.po.y / BLOCK][(g->ply.po.x / BLOCK) + 1] != 'E')
		{
			g->empty.po.x = g->ply.po.x;
			g->empty.po.y = g->ply.po.y;
			g->ply.po.x += BLOCK;
			walk_animat(g, "sprites/pr1.xpm", "sprites/pr2.xpm");
		}
	}
}

static void	move_left(t_game *g)
{
	if (g->map.arr[g->ply.po.y / BLOCK][(g->ply.po.x / BLOCK) - 1] != '1')
	{
		if (g->map.arr[g->ply.po.y / BLOCK][(g->ply.po.x / BLOCK) - 1] != 'E')
		{
			g->ply.steps++;
			print_moves(g);
		}
		if (g->map.arr[g->ply.po.y / BLOCK][(g->ply.po.x / BLOCK) - 1] == 'G')
			die(g);
		if (g->map.arr[g->ply.po.y / BLOCK][(g->ply.po.x / BLOCK) - 1] == 'C')
		{
			g->map.arr[g->ply.po.y / BLOCK][(g->ply.po.x / BLOCK) - 1] = '0';
			g->to_coll--;
		}
		if (g->map.arr[g->ply.po.y / BLOCK][(g->ply.po.x / BLOCK) - 1] == 'E')
			check_exit(g);
		if (g->map.arr[g->ply.po.y / BLOCK][(g->ply.po.x / BLOCK) - 1] != 'E')
		{
			g->empty.po.x = g->ply.po.x;
			g->empty.po.y = g->ply.po.y;
			g->ply.po.x -= BLOCK;
			walk_animat(g, "sprites/pl1.xpm", "sprites/pl2.xpm");
		}
	}
}
