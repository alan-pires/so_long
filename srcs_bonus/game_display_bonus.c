/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_display_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apires-d <apires-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 17:51:17 by apires-d          #+#    #+#             */
/*   Updated: 2021/09/09 08:06:02 by apires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	display_sprite(t_game *game, t_sprite *sprite, t_pos pos);
static void	check_sprite(t_game *game, char sprite, t_pos pos);

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
			check_sprite(game, game->map.arr[i][j], pos);
			j++;
		}
		i++;
	}
	return (0);
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
		display_sprite(game, &game->ply, pos);
	else if (sprite == 'E')
		display_sprite(game, &game->exit, pos);
	else if (sprite == 'G')
		display_sprite(game, &game->enemy, pos);
}

static void	display_sprite(t_game *game, t_sprite *sprite, t_pos pos)
{
	sprite->pos.x = pos.x * BLOCK;
	sprite->pos.y = pos.y * BLOCK;
	mlx_put_image_to_window(game->mlx, game->window.ref, sprite->ref, sprite->pos.x, sprite->pos.y);
}
