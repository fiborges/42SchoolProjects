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
#define ERR_UNSOLVABLE ANSI_COLOR_RED "Error.\nMap is Unsolvable\n" ANSI_COLOR_RESET

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
//2D point in space x an y coordinates
typedef struct s_point
{
	int x;
	int y;
}	t_point;

//represents the game map
typedef struct s_map
{
	char	**map;
	int		height;
	int		width;
	int		count_exit;
	int		count_obj;
	int		count_pos;
}	t_map;
//represents a display window
typedef struct s_display
{
	void	*mlx;
	void	*mlx_win;
	int		screen_height;
	int		screen_width;
}	t_display;
//represents the game state
typedef struct s_game
{
	int	p_pos_x;
	int	p_pos_y;
	int	count_coll;
	int	collected_coll;
	int	count_movements;
}	t_game;
//represents a single tile in the game
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
//represents the images used in the game
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
// Initializes the game map from the given file path
void		map_initialize(char *file_path);
// Validates the map by checking all conditions
void		check_map(void);
// Fills map struct with map data from the file
t_map		*fill_map(void);
// Deletes a matrix from memory
void	clean_path(char **path);

/*
**	Initialize window
*/
// Initializes the game window with specified display settings
void		window_initialize(t_display *window);
// Opens a window and returns the window struct
t_display	*open_window(void);

/*
**	Initialize img
*/
// Initializes image assets for the game
void		img_initialize(void);
// Returns a pointer to the img structure containing all game images
t_img		*img(void);
//draw a specified image at a given grid position (i, j) on the screen using the MiniLibX library
void	display_image(t_tile *tile, int i, int j);

/*
**	Game
*/
// Returns a pointer to the game structure containing game state information
t_game		*game(void);
// Initializes the game state
void		game_initialize(void);
// Starts the game loop and manages events
void		game_play(void);

/*
**	Exit game
*/
// Clears map from memory
void		clear_map(void);
// Exits the game with a given exit code, output stream, and error message
int			exit_game(int exit, int STD, char *msg);
// Prints an error message and exits the game
int			print_and_exit(char *msg);
// Clears image assets from memory
void		clear_img(void);

/*
**	Map_utils
*/

bool	flood_fill(t_map *map, t_point curr, char **path);
static void	isvalid_border(int y, int x);
static void	isvalid_char(char c, int y, int x);

/*
**	Main
*/
// Prints the number of moves taken by the player
void		print_moves(void);

#endif
