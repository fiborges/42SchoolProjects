/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_map_checker.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipa <filipa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:35:17 by firibeir          #+#    #+#             */
/*   Updated: 2023/04/01 15:29:28 by filipa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

bool	has_valid_path(t_map *map, t_game *game)
{
	char	**new;
	bool	is_valid;
	int		i;

	i = 0;
	new = calloc(map->height + 1, sizeof(char *));
	if (!new)
		exit_game(EXIT_SUCCESS, STDERR_FILENO, "Failed allocation on has_valid_path()\n");
	while (i < map->height)
	{
		new[i] = strdup(map->map[i]);
		if (!new[i])
		{
			clean_path(new);
			exit_game(EXIT_SUCCESS, STDERR_FILENO, "Failed allocation on has_valid_path()\n");
		}
		i++;
	}
	is_valid = flood_fill(map, (t_point){game->p_pos_x, game->p_pos_y}, new);
	clean_path(new);
	return (is_valid);
}

void check_map(void)
{
    int x;
    int y;
    bool valid_path;

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
    valid_path = has_valid_path(fill_map(), game());
    if (!valid_path)
        exit_game(EXIT_SUCCESS, STDERR_FILENO, ERR_UNSOLVABLE);
}

