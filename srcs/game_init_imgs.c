/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_imgs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 08:45:11 by apires-d          #+#    #+#             */
/*   Updated: 2021/09/05 11:09:01 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_imgs(t_game *game)
{
	game->player.ref = mlx_xpm_file_to_image(game->mlx, PLAYER, &game->player.width, &game->player.height);
	game->player.pixels = (int *)mlx_get_data_addr(game->player.ref, &game->player.bpp, &game->player.line_size, &game->player.endian);
	
	game->empty.ref = mlx_xpm_file_to_image(game->mlx, EMPTY, &game->empty.width, &game->empty.height);
	game->empty.pixels = (int *)mlx_get_data_addr(game->empty.ref, &game->empty.bpp, &game->empty.line_size, &game->empty.endian);
	
	game->wall.ref = mlx_xpm_file_to_image(game->mlx, WALL, &game->wall.width, &game->wall.height);
	game->wall.pixels = (int *)mlx_get_data_addr(game->wall.ref, &game->wall.bpp, &game->wall.line_size, &game->wall.endian);
	
	game->collect.ref = mlx_xpm_file_to_image(game->mlx, COLLECT, &game->collect.width, &game->collect.height);
	game->collect.pixels = (int *)mlx_get_data_addr(game->collect.ref, &game->collect.bpp, &game->collect.line_size, &game->collect.endian);

	game->exit.ref = mlx_xpm_file_to_image(game->mlx, EXIT, &game->exit.width, &game->exit.height);
	game->exit.pixels = (int *)mlx_get_data_addr(game->exit.ref, &game->exit.bpp, &game->exit.line_size, &game->exit.endian);

}