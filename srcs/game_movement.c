/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 14:26:08 by apires-d          #+#    #+#             */
/*   Updated: 2021/09/05 15:11:42 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_move(int key, void *param)
{
	t_game *game = (t_game*)param;
	
	// mlx_clear_window(game->mlx, game->window.ref);
	game->player.ref = mlx_xpm_file_to_image(game->mlx, PLAYER, &game->player.width, &game->player.height);
	game->player.pixels = (int *)mlx_get_data_addr(game->player.ref, &game->player.bpp, &game->player.line_size, &game->player.endian);
	if (key == UP)
		game->player.pos.y -= BLOCK;
	if (key == DOWN)
		game->player.pos.y += BLOCK;
	if (key == RIGHT)
		game->player.pos.y += BLOCK;
	if (key == LEFT)
		game->player.pos.y -= BLOCK;
	mlx_put_image_to_window(game->mlx, game->window.ref, game->player.ref, game->player.pos.x, game->player.pos.y);
	return (0);
}