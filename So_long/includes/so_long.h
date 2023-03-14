#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdint.h>
# include <limits.h>
# include <stdio.h>

/*
** Error Messages
*/
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_RESET "\x1b[0m"

#define ERR_ARGS ANSI_COLOR_RED "Error.\nInvalid Number of Arguments.\n" ANSI_COLOR_RESET
#define ERR_NOMAP ANSI_COLOR_RED "Error.\nInvalid Path for Map, or Empty Map.\n" ANSI_COLOR_RESET
#define ERR_STARTP ANSI_COLOR_RED "Error.\nNumber of Starting Positions on the map is not Valid.\n" ANSI_COLOR_RESET
#define ERR_WIDTH ANSI_COLOR_RED "Error.\nMap rows must have the same width.\n" ANSI_COLOR_RESET
#define ERR_EXIT ANSI_COLOR_RED "Error.\nInvalid number of exits in map.\n" ANSI_COLOR_RESET
#define ERR_NOCOLL ANSI_COLOR_RED "Error.\nNo collectibles in map.\n" ANSI_COLOR_RESET
#define ERR_INVALIDCHAR ANSI_COLOR_RED "Error.\nInvalid character in map.\n" ANSI_COLOR_RESET
#define ERR_BORDERS ANSI_COLOR_RED "Error.\nMap borders are not clear.\n" ANSI_COLOR_RESET
#define ERR_MEM ANSI_COLOR_RED "Error.\nMemory error while running malloc().\n" ANSI_COLOR_RESET
#define ERR_BER ANSI_COLOR_RED "Error.\nInvalid map format. \".ber\" map required.\n" ANSI_COLOR_RESET
/*
** Keyboard keys
*/

# define D 100
# define A 97
# define W 119
# define S 115
# define RIGHT 65363
# define LEFT 65361
# define TOP 65362
# define BOTTOM 65364
# define ESC 65307

/*
**	Structures
*/

typedef struct s_map
{
	char	**map;
	int		height;
	int		width;
	int		count_exit;
	int		count_obj;
	int		count_pos;
}	t_map;

typedef struct s_display
{
	void	*mlx;
	void	*mlx_win;
	int		screen_height;
	int		screen_width;
}	t_display;

typedef struct s_game
{
	int	p_pos_x;
	int	p_pos_y;
	int	count_coll;
	int	collected_coll;
	int	count_movements;
}	t_game;

typedef struct s_tile
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			height;
	int			width;
}	t_tile;

typedef struct s_img
{
	t_tile	ground;
	t_tile	wall;
	t_tile	collectible;
	t_tile	exit;
	t_tile	character;
	t_tile	character_current;
	int		format;
}	t_img;

/*
** Initialise map
*/

void		map_initialize(char *file_path);
void		check_map(void);
t_map		*fill_map(void);

/*
**	Initialize window
*/

void		window_initialize(t_display *window);
t_display	*open_window(void);

/*
**	Initialize img
*/

void		img_initialize(void);
t_img		*img(void);

/*
**	Game
*/

t_game		*game(void);
void		game_initialize(void);
void		game_play(void);

/*
**	Exit game
*/

void		clear_map(void);
int			exit_game(int exit, int STD, char *msg);
int			print_and_exit(char *msg);
void		clear_img(void);

/*
**	Utils
*/

void		print_moves(void);

#endif
