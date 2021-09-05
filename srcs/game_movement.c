/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 14:26:08 by apires-d          #+#    #+#             */
/*   Updated: 2021/09/05 15:43:27 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	move_up(t_game *game);
static void	move_down(t_game *game);
static void	move_right(t_game *game);
static void	move_left(t_game *game);

int	ft_move(int key, void *param)
{
	t_game *game = (t_game*)param;
	
	if (key == UP)
		move_up(game);
	if (key == DOWN)
		move_down(game);
	if (key == RIGHT)
		move_right(game);
	if (key == LEFT)
		move_left(game);
	return (0);
}

static void	move_up(t_game *game)
{
	game->empty.pos.x = game->player.pos.x;
	game->empty.pos.y = game->player.pos.y;
	game->player.pos.y -= BLOCK;
	mlx_put_image_to_window(game->mlx, game->window.ref, game->empty.ref, game->empty.pos.x, game->empty.pos.y);
	mlx_put_image_to_window(game->mlx, game->window.ref, game->player.ref, game->player.pos.x, game->player.pos.y);
}

static void	move_down(t_game *game)
{
	game->empty.pos.x = game->player.pos.x;
	game->empty.pos.y = game->player.pos.y;
	game->player.pos.y += BLOCK;
	mlx_put_image_to_window(game->mlx, game->window.ref, game->empty.ref, game->empty.pos.x, game->empty.pos.y);
	mlx_put_image_to_window(game->mlx, game->window.ref, game->player.ref, game->player.pos.x, game->player.pos.y);
}

static void	move_right(t_game *game)
{
	game->empty.pos.x = game->player.pos.x;
	game->empty.pos.y = game->player.pos.y;
	game->player.pos.x += BLOCK;
	mlx_put_image_to_window(game->mlx, game->window.ref, game->empty.ref, game->empty.pos.x, game->empty.pos.y);
	mlx_put_image_to_window(game->mlx, game->window.ref, game->player.ref, game->player.pos.x, game->player.pos.y);
}

static void	move_left(t_game *game)
{
	game->empty.pos.x = game->player.pos.x;
	game->empty.pos.y = game->player.pos.y;
	game->player.pos.x -= BLOCK;
	mlx_put_image_to_window(game->mlx, game->window.ref, game->empty.ref, game->empty.pos.x, game->empty.pos.y);
	mlx_put_image_to_window(game->mlx, game->window.ref, game->player.ref, game->player.pos.x, game->player.pos.y);
}
