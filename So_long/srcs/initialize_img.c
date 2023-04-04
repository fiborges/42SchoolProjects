/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipa <filipa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:35:09 by firibeir          #+#    #+#             */
/*   Updated: 2023/04/03 09:16:23 by filipa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_img	*img(void)
{
	static t_img	img;

	return (&img);
}

static void	tiles(t_tile *tile, char *path)
{
	tile->img = mlx_xpm_file_to_image(open_window()->mlx,
			path, &tile->width, &tile->height);
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

void	display_image(t_tile *tile, int i, int j)
{
	mlx_put_image_to_window(open_window()->mlx,
		open_window()->mlx_win, tile->img,
		i * img()->format, j * img()->format);
}
