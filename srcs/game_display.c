/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 17:51:17 by apires-d          #+#    #+#             */
/*   Updated: 2021/09/05 09:58:39 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	display_sprite(t_game *game, t_sprite *sprite, t_pos pos)
{
	// int	i;
	// int	j;

	// i = 0;
	sprite->pos.x = pos.x * BLOCK;
	sprite->pos.y = pos.y * BLOCK;

	//ver se pode mandar imprimir tudo aqui agora ou se eu só carrego na memoria pra imprimir dpois...
	mlx_put_image_to_window(game->mlx, game->window.ref, sprite->ref, sprite->pos.x, sprite->pos.y);
	
	// while (i < game->map.lines)
	// {
	// 	j = 0;
	// 	while (j < game->map.cols)
	// 	{
	// 		sprite->ref = mlx_xpm_file_to_image(game->mlx, path, &sprite->width, &sprite->height);
	// 		sprite->pixels = (int *)mlx_get_data_addr(sprite->ref, &sprite->bpp, &sprite->line_size, &sprite->endian);
	// 		//ver se pode mandar imprimir tudo aqui agora ou se eu só carrego na memoria pra imprimir dpois...
	// 		mlx_put_image_to_window(game->mlx, game->window.ref, sprite->ref, game->pos.x, game->pos.y);
	// 		j++;
	// 	}
	// 	i++;
	// }
	
}

static void	check_sprite(t_game *game, char sprite, t_pos pos)
{
	if (sprite == '1')
		display_sprite(game, &game->wall, pos);
	else if (sprite == '0')
		display_sprite(game, &game->empty, pos);
	else if (sprite == 'C')
		display_sprite(game, &game->collect, pos);
	else if (sprite == 'P')
		display_sprite(game, &game->player, pos);
	else if (sprite == 'E')
		display_sprite(game, &game->exit, pos);
}

int	game_display(t_game *game)
{
	int		i;
	int		j;
	t_pos	pos;

	i = 0;
	while (i < game->map.lines)
	{
		j = 0;
		while (j < game->map.cols)
		{
			pos.y = i;
			pos.x = j;
			check_sprite(game, game->map.array[i][j], pos);
			j++;
		}
		i++;
	}
	return (0);
}

// int	game_display(t_game *game)
// {


// 	game->pos.y = 0;
// 	game->pos.x = 0;
// 	check_sprite(game, game->map.array[0][0]);

// 	game->pos.x = (game->pos.x + 1) * BLOCK;
// 	game->pos.y = (game->pos.y + 1) * BLOCK;
// 	check_sprite(game, game->map.array[0][0]);


// 	return (0);
// }