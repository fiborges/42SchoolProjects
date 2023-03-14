#include "../includes/so_long.h"

t_img	*img(void)
{
	static t_img	img;

	return (&img);
}

static void	tiles(t_tile *tile, char *path)
{
	tile->img = mlx_xpm_file_to_image(open_window()->mlx, path, &tile->width, &tile->height);
	if (tile->img == NULL)
	{
		clear_img();
		mlx_destroy_display(open_window()->mlx);
		free(open_window()->mlx);
		exit_game(EXIT_FAILURE, STDERR_FILENO,
			"\033[0;31mError.\nWhile loading textures.\n\033[0m");
	}
	tile->addr = mlx_get_data_addr(tile->img, &tile->bits_per_pixel,
			&tile->line_length, &tile->endian);
}

void	img_initialize(void)
{
	img()->format = 64;
	tiles(&img()->ground, "./Tiles/ground.xpm");
	tiles(&img()->wall, "./Tiles/wall.xpm");
	tiles(&img()->collectible, "./Tiles/collectible.xpm");
	tiles(&img()->exit, "./Tiles/exit.xpm");
	tiles(&img()->character, "./Tiles/character.xpm");
	img()->character_current = img()->character;
}
