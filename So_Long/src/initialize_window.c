#include "../includes/so_long.h"

t_display	*open_window(void)
{
	static t_display	display;

	return (&display);
}

void	window_initialize(t_display *window)
{
	window->screen_height = fill_map()->height * img()->format;
	window->screen_width = fill_map()->width * img()->format;
	window->mlx_win = mlx_new_window(window->mlx, window->screen_width, window->screen_height,
			"./so_long");
	mlx_hook(window->mlx_win, 17, 0, print_and_exit, "Game exited by user\n");
}
