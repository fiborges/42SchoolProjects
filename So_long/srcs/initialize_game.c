#include "../includes/so_long.h"

t_game	*game(void)
{
	static t_game	game;

	return (&game);
}

void	game_initialize(void)
{
	game()->count_coll = fill_map()->count_obj;
	game()->count_movements = 0;
	game()->collected_coll = 0;
}
