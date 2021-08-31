#ifndef SO_LONG_H
# define SO_LONG_H
# include "../mlx_linux/mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

# define BLOCK 50

typedef struct s_map
{
	int		column;
	int		line;
	char	**array;
	char	*ref;
}	t_map;

typedef struct s_window
{
	void	*ref;
	int		x;
	int		y;
}	t_window;

typedef struct	s_sprite
{
	void	*ref;
	int		width;
	int		height;
	char	*pixels;
	int		bpp;
	int		line_size;
	int		endian;
	int		quant;
	char	type[10];
	//int	posx;
	//int	posy;
}	t_sprite;

typedef struct	s_game
{
	void		*mlx;
	t_window	window;
	t_sprite	player;
	t_sprite	collect;
	t_sprite	wall;
	t_sprite	empty;
	t_map		map;

}	t_game;

void	game_start(t_game *game, int argc, char **argv);
int		check_map(t_game *game, char **argv);


# endif