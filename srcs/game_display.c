/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 17:51:17 by apires-d          #+#    #+#             */
/*   Updated: 2021/09/03 19:16:08 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	display_sprite(t_game *game, t_sprite *sprite, char *path)
{
	int	i;
	int	j;

	i = 0;
	game->pos.x *= BLOCK;
	game->pos.y *= BLOCK;
	while (i < game->map.lines)
	{
		j = 0;
		while (j < game->map.cols)
		{
			sprite->ref = mlx_xpm_file_to_image(game->mlx, path, &sprite->width, &sprite->height);
			sprite->pixels = (int *)mlx_get_data_addr(sprite->ref, &sprite->bpp, &sprite->line_size, &sprite->endian);
			//ver se pode mandar imprimir tudo aqui agora ou se eu só carrego na memoria pra imprimir dpois...
			mlx_put_image_to_window(game->mlx, game->window.ref, sprite->ref, game->pos.x, game->pos.y);
			j++;
		}
		i++;
	}
	
}

static void	check_sprite(t_game *game, char sprite)
{
	if (sprite == '1')
		display_sprite(game, &game->wall, WALL);
	else if (sprite == '0')
		display_sprite(game, &game->empty, EMPTY);
	else if (sprite == 'C')
		display_sprite(game, &game->collect, COLLECT);
	else if (sprite == 'P')
		display_sprite(game, &game->player, PLAYER);
	else if (sprite == 'E')
		display_sprite(game, &game->exit, EXIT);
}

int	game_display(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.lines)
	{
		j = 0;
		while (j < game->map.cols)
		{
			game->pos.x = i;
			game->pos.y = j;
			check_sprite(game, game->map.array[i][j]);
			j++;
		}
		i++;
	}
	return (0);
}