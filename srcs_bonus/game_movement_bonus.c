/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_movement_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 14:26:08 by apires-d          #+#    #+#             */
/*   Updated: 2021/09/09 13:05:26 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	move_up(t_game *game);
static void	move_down(t_game *game);
static void	move_right(t_game *game);
static void	move_left(t_game *game);

int	ft_move(int key, void *param)
{
	t_game *game = (t_game*)param;

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
	if (g->map.arr[(g->ply.pos.y / BLOCK) - 1][g->ply.pos.x / BLOCK] != '1')
	{
		g->ply.steps++;
		if (g->map.arr[(g->ply.pos.y / BLOCK) - 1][g->ply.pos.x / BLOCK] == 'G')
			exit_err(g, "You were killed by the enemy");
		//printf("%d\n", g->ply.steps);
		print_moves(g);
		if (g->map.arr[(g->ply.pos.y / BLOCK) - 1][g->ply.pos.x / BLOCK] == 'C')
		{
			g->map.arr[(g->ply.pos.y / BLOCK) - 1][g->ply.pos.x / BLOCK] = '0';
			g->to_collect--;
		}
		if (g->map.arr[(g->ply.pos.y / BLOCK) - 1][g->ply.pos.x / BLOCK] == 'E')
			check_exit(g);
		if (g->map.arr[(g->ply.pos.y / BLOCK) - 1][g->ply.pos.x / BLOCK] != 'E')
		{
			g->empty.pos.x = g->ply.pos.x;
			g->empty.pos.y = g->ply.pos.y;
			g->ply.pos.y -= BLOCK;
			walk_animat(g, "sprites/pu1.xpm", "sprites/pu2.xpm");
		}
	}
	enemy_move(g);
}

static void	move_down(t_game *g)
{
	if (g->map.arr[(g->ply.pos.y / BLOCK) + 1][g->ply.pos.x / BLOCK] != '1')
	{
		g->ply.steps++;
		if (g->map.arr[(g->ply.pos.y / BLOCK) + 1][g->ply.pos.x / BLOCK] == 'G')
			exit_err(g, "You were killed by the enemy");
		//printf("%d\n", g->ply.steps);
		print_moves(g);
		if (g->map.arr[(g->ply.pos.y / BLOCK) + 1][g->ply.pos.x / BLOCK] == 'C')
		{
			g->map.arr[(g->ply.pos.y / BLOCK) + 1][g->ply.pos.x / BLOCK] = '0';
			g->to_collect--;			
		}
		if (g->map.arr[(g->ply.pos.y / BLOCK) + 1][g->ply.pos.x / BLOCK] == 'E')
			check_exit(g);
		if (g->map.arr[(g->ply.pos.y / BLOCK) + 1][g->ply.pos.x / BLOCK] != 'E')
		{
			g->empty.pos.x = g->ply.pos.x;
			g->empty.pos.y = g->ply.pos.y;
			g->ply.pos.y += BLOCK;
			walk_animat(g, "sprites/pd1.xpm", "sprites/pd2.xpm");
		}
	}
	enemy_move(g);
}

static void	move_right(t_game *g)
{
	if (g->map.arr[g->ply.pos.y / BLOCK][(g->ply.pos.x / BLOCK) + 1] != '1')
	{
		g->ply.steps++;
		if (g->map.arr[g->ply.pos.y / BLOCK][(g->ply.pos.x / BLOCK) + 1] == 'G')
			exit_err(g, "You were killed by the enemy");
		//printf("%d\n", g->ply.steps);
		print_moves(g);
		if (g->map.arr[g->ply.pos.y / BLOCK][(g->ply.pos.x / BLOCK) + 1] == 'C')
		{
			g->map.arr[g->ply.pos.y / BLOCK][(g->ply.pos.x / BLOCK) + 1] = '0';
			g->to_collect--;
		}
		if (g->map.arr[g->ply.pos.y / BLOCK][(g->ply.pos.x / BLOCK) + 1] == 'E')
			check_exit(g);
		if (g->map.arr[g->ply.pos.y / BLOCK][(g->ply.pos.x / BLOCK) + 1] != 'E')
		{
			g->empty.pos.x = g->ply.pos.x;
			g->empty.pos.y = g->ply.pos.y;
			g->ply.pos.x += BLOCK;
			walk_animat(g, "sprites/pr1.xpm", "sprites/pr2.xpm");
		}
	}
	enemy_move(g);
}

static void	move_left(t_game *g)
{
	if (g->map.arr[g->ply.pos.y / BLOCK][(g->ply.pos.x / BLOCK) - 1] != '1')
	{
		g->ply.steps++;
		if (g->map.arr[g->ply.pos.y / BLOCK][(g->ply.pos.x / BLOCK) - 1] == 'G')
			exit_err(g, "You were killed by the enemy");
		//printf("%d\n", g->ply.steps);
		print_moves(g);
		if (g->map.arr[g->ply.pos.y / BLOCK][(g->ply.pos.x / BLOCK) - 1] == 'C')
		{
			g->map.arr[g->ply.pos.y / BLOCK][(g->ply.pos.x / BLOCK) - 1] = '0';
			g->to_collect--;
		}
		if (g->map.arr[g->ply.pos.y / BLOCK][(g->ply.pos.x / BLOCK) - 1] == 'E')
			check_exit(g);
		if (g->map.arr[g->ply.pos.y / BLOCK][(g->ply.pos.x / BLOCK) - 1] != 'E')
		{
			g->empty.pos.x = g->ply.pos.x;
			g->empty.pos.y = g->ply.pos.y;
			g->ply.pos.x -= BLOCK;
			walk_animat(g, "sprites/pl1.xpm", "sprites/pl2.xpm");
		}
	}
	enemy_move(g);
}
