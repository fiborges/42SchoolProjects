/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_map_checker.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipa <filipa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:35:17 by firibeir          #+#    #+#             */
/*   Updated: 2023/04/04 12:41:13 by filipa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/libft.h"

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
		new[i] = ft_strdup(map->map[i]);
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

void check_dimensions(void)
{
    int x;
    int y;

    y = 0;
    while (fill_map()->map[y])
    {
        x = 0;
        while (fill_map()->map[y][x])
        {
            x++;
        }
        if (x != fill_map()->width)
            exit_game(EXIT_SUCCESS, STDERR_FILENO, ERR_WIDTH);
        y++;
    }
}

void check_elements_count(void)
{
    if (fill_map()->count_pos != 1)
        exit_game(EXIT_SUCCESS, STDERR_FILENO, ERR_STARTP);
    if (fill_map()->count_exit != 1)
        exit_game(EXIT_SUCCESS, STDERR_FILENO, ERR_EXIT);
    if (fill_map()->count_obj < 1)
        exit_game(EXIT_SUCCESS, STDERR_FILENO, ERR_NOCOLL);
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
        y++;
    }

    check_dimensions();
    check_elements_count();

    valid_path = has_valid_path(fill_map(), game());
    if (!valid_path)
        exit_game(EXIT_SUCCESS, STDERR_FILENO, ERR_UNSOLVABLE);
}
