#ifndef SO_LONG_H
# define SO_LONG_H
#include "../mlx_linux/mlx.h"
#include "../libft/libft.h"

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

}	t_game;


# endif