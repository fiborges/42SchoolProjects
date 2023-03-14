#include "../includes/so_long.h"

static void	display_image(t_tile *tile, int i, int j)
{
	mlx_put_image_to_window(open_window()->mlx, open_window()->mlx_win, tile->img,
		i * img()->format, j * img()->format);
}

static void	redraw_map(void)
{
	int	i;
	int	j;

	i = 0;
	while (fill_map()->map[i])
	{
		j = 0;
		while (fill_map()->map[i][j])
		{
			if (fill_map()->map[i][j] == '1')
				display_image(&img()->wall, j, i);
			else if (fill_map()->map[i][j] == '0')
				display_image(&img()->ground, j, i);
			else if (fill_map()->map[i][j] == 'E')
				display_image(&img()->exit, j, i);
			else if (fill_map()->map[i][j] == 'C')
				display_image(&img()->collectible, j, i);
			else if (fill_map()->map[i][j] == 'P')
				display_image(&img()->character_current, j, i);
			j++;
		}
		i++;
	}
}

static void	move_charater(int y_mov, int x_mov)
{	
	if (fill_map()->map[game()->p_pos_y + y_mov][game()->p_pos_x + x_mov] == '0' ||
			fill_map()->map[game()->p_pos_y + y_mov][game()->p_pos_x + x_mov] == 'C')
	{
		if (fill_map()->map[game()->p_pos_y + y_mov][game()->p_pos_x + x_mov] == 'C')
			game()->collected_coll++;
		fill_map()->map[game()->p_pos_y][game()->p_pos_x] = '0';
		fill_map()->map[game()->p_pos_y + y_mov][game()->p_pos_x + x_mov] = 'P';
		game()->p_pos_x += x_mov;
		game()->p_pos_y += y_mov;
		game()->count_movements++;
		print_moves();
	}
	else if (fill_map()->map[game()->p_pos_y][game()->p_pos_x + x_mov] == 'E'
			&& game()->count_coll == game()->collected_coll)
		exit_game(EXIT_SUCCESS, STDOUT_FILENO, "\033[32mSUCCESS!, YOU WIN\033[0m");
}

int	keyboard_input (int key, t_display *display)
{
	if (key == D || key == RIGHT)
	{
		img()->character_current = img()->character;
		move_charater(0, 1);
	}
	else if (key == A || key == LEFT)
	{
		img()->character_current = img()->character;
		move_charater(0, -1);
	}
	else if (key == W || key == TOP)
	{
		img()->character_current = img()->character;
		move_charater(-1, 0);
	}
	else if (key == S || key == BOTTOM)
	{
		img()->character_current = img()->character;
		move_charater(1, 0);
	}
	else if (key == ESC)
		exit_game(EXIT_SUCCESS, STDOUT_FILENO, "\033[33;1mGame exited by user.\033[0m\n");
	redraw_map();
	(void)display;
	return (0);
}

void	game_play(void)
{
	redraw_map();
	mlx_key_hook(open_window()->mlx_win, keyboard_input, open_window());
}
