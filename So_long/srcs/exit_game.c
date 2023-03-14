#include "../includes/so_long.h"

int	print_and_exit(char *msg)
{
	exit_game(EXIT_SUCCESS, STDOUT_FILENO, msg);
	return (0);
}

void	clear_map(void)
{
	int	i;

	i = 0;
	if (fill_map())
	{
		while (fill_map()->map[i])
		{
			free(fill_map()->map[i]);
			i++;
		}
		free(fill_map()->map);
	}
}

void	clear_img(void)
{
	if (img()->ground.img)
		mlx_destroy_image(open_window()->mlx, img()->ground.img);
	if (img()->wall.img)
		mlx_destroy_image(open_window()->mlx, img()->wall.img);
	if (img()->collectible.img)
		mlx_destroy_image(open_window()->mlx, img()->collectible.img);
	if (img()->exit.img)
		mlx_destroy_image(open_window()->mlx, img()->exit.img);
	if (img()->character.img)
		mlx_destroy_image(open_window()->mlx, img()->character.img);
}

int	exit_game(int EXIT_CODE, int STD, char *msg)
{
	clear_map();
	if (STD != STDERR_FILENO)
	{
		clear_img();
		mlx_destroy_window(open_window()->mlx, open_window()->mlx_win);
		mlx_loop_end(open_window()->mlx);
		mlx_destroy_display(open_window()->mlx);
		free(open_window()->mlx);
	}
	ft_putstr_fd(msg, STD);
	exit(EXIT_CODE);
	return (0);
}
