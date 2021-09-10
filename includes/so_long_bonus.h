#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include "../mlx_linux/mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

# define BLOCK 50
# define PLAYER "sprites/player.xpm"
# define EMPTY "sprites/empty.xpm"
# define EXIT "sprites/exit.xpm"
# define COLLECT "sprites/collect.xpm"
# define WALL "sprites/wall.xpm"
# define ENEMY "sprites/gengar.xpm"
# define ESC 0xff1b
# define RIGHT 0x64
# define LEFT 0x61
# define UP 0x77
# define DOWN 0x73
# define EXIT_GAME 17

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_map
{
	int		cols;
	int		lines;
	char	**arr;

}	t_map;

typedef struct s_sprite
{
	void	*ref;
	int		width;
	int		height;
	int		*pixels;
	int		bpp;
	int		line;
	int		endian;
	char	type[10];
	t_pos	po;
	int		animate;
	int		steps;
	int		left;

}	t_sprite;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_sprite	ply;
	t_sprite	coll;
	t_sprite	wall;
	t_sprite	empty;
	t_sprite	exit;
	t_sprite	enemy;
	t_map		map;
	int			to_coll;

}	t_game;

void	game_start(t_game *game, int argc, char **argv);
int		check_map(t_game *game, char **argv);
int		game_display(t_game *game);
void	init_imgs(t_game *game);
int		ft_move(int key, void *param);
void	check_exit(t_game *game);
void	check_map_errors(t_game *game);
void	walk_animat(t_game *g, char *img1, char *img2);
void	free_map(t_game *game);
void	exit_err(t_game *game, char *msg);
int		exit_game(t_game *game);
int		enemy_move(t_game *g, t_sprite *e);
void	print_moves(t_game *game);
void	die(t_game *game);
int		display_expose(t_game *game);

#endif