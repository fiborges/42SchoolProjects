#include "../includes/so_long.h"
#include "../libft/libft.h"

static void	isvalid_border(int y, int x)
{
	if ((y == 0 || y == fill_map()->height - 1 || x == 0 || x == fill_map()->width - 1)
		&& fill_map()->map[y][x] != '1')
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

void	check_map(void)
{
	int	x;
	int	y;

	y = 0;
	if (!fill_map()->map[0])
		exit_game(EXIT_SUCCESS, STDERR_FILENO, ERR_NOMAP);
	while (fill_map()->map[y])
	{
		x = 0;
		while (fill_map()->map[y][x])
		{
			isvalid_char(fill_map()->map[y][x], y, x);
			isvalid_border(y, x);
			x++;
		}
		if (x != fill_map()->width)
			exit_game(EXIT_SUCCESS, STDERR_FILENO, ERR_WIDTH);
		y++;
	}
	if (fill_map()->count_pos > 1 || fill_map()->count_pos < 1)
		exit_game(EXIT_SUCCESS, STDERR_FILENO, ERR_STARTP);
	if (fill_map()->count_exit > 1 || fill_map()->count_exit < 1)
		exit_game(EXIT_SUCCESS, STDERR_FILENO, ERR_EXIT);
	if (fill_map()->count_obj < 1)
		exit_game(EXIT_SUCCESS, STDERR_FILENO, ERR_NOCOLL);
}
