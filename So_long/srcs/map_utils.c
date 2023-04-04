
#include "../includes/so_long.h"
#include "../libft/libft.h"

bool	flood_fill(t_map *map, t_point curr, char **path)
{
	static int	collectives = 0;
	static bool	found_exit = false;

	if (path[curr.y][curr.x] == '1')
		return (false);
	else if (path[curr.y][curr.x] == 'C')
		collectives++;
	else if (path[curr.y][curr.x] == 'E')
		found_exit = true;
	path[curr.y][curr.x] = '1';
	flood_fill(map, (t_point){curr.x + 1, curr.y}, path);
	flood_fill(map, (t_point){curr.x - 1, curr.y}, path);
	flood_fill(map, (t_point){curr.x, curr.y + 1}, path);
	flood_fill(map, (t_point){curr.x, curr.y - 1}, path);
	return (collectives == map->count_obj && found_exit);
}

static void	isvalid_border(int y, int x)
{
	if ((y == 0 || y == fill_map()->height - 1 || x == 0
			|| x == fill_map()->width - 1) && fill_map()->map[y][x] != '1')
		exit_game(EXIT_SUCCESS, STDERR_FILENO, ERR_BORDERS);
}

static void	isvalid_char(char c, int y, int x)
{
	if (c == 'P')
	{
		fill_map()->count_pos++;
		game()->p_pos_x = x;
		game()->p_pos_y = y;
	}
	else if (c == 'E')
		fill_map()->count_exit++;
	else if (c == 'C')
		fill_map()->count_obj++;
	else if (c == '1' || c == '0')
		return ;
	else
		exit_game(EXIT_SUCCESS, STDERR_FILENO, ERR_INVALIDCHAR);
}