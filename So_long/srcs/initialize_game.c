/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipa <filipa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:35:01 by firibeir          #+#    #+#             */
/*   Updated: 2023/04/01 15:30:59 by filipa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void clean_path(char **path)
{
    int i;

    if (!path)
        return;

    i = 0;
    while (path[i])
    {
        free(path[i]);
        i++;
    }
    free(path);
}


