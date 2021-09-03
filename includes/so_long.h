#ifndef SO_LONG_H
# define SO_LONG_H
# include "../mlx_linux/mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

# define BLOCK 50
# define PLAYER "sprites/player.xpm"
# define EMPTY "sprites/empty.xpm"
# define EXIT "sprites/out.xpm"
# define COLLECT "sprites/collect.xpm"
# define WALL "sprites/wall.xpm"

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_map
{
	int		cols;
	int		lines;
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
	int		*pixels;
	int		bpp;
	int		line_size;
	int		endian;
	char	type[10];
	int		posx;
	int		posy;
}	t_sprite;

typedef struct	s_game
{
	void		*mlx;
	t_window	window;
	t_sprite	player;
	t_sprite	collect;
	t_sprite	wall;
	t_sprite	empty;
	t_sprite	exit;
	t_map		map;
	t_pos		pos;
}	t_game;

void	game_start(t_game *game, int argc, char **argv);
int		check_map(t_game *game, char **argv);
int		game_display(t_game *game);

# endif