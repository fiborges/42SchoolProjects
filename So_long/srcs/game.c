/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipa <filipa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:34:49 by firibeir          #+#    #+#             */
/*   Updated: 2023/04/03 14:02:10 by filipa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

int check_exit_condition(int y_mov, int x_mov)
{
    if (fill_map()->map[game()->p_pos_y + y_mov][game()->p_pos_x + x_mov] == 'E')
    {
        if (game()->count_coll == game()->collected_coll)
            return 1;
        else
            return 0;
    }
    return -1;
}

static void move_charater(int y_mov, int x_mov)
{
    int exit_condition = check_exit_condition(y_mov, x_mov);
    int current_tile = fill_map()->map[game()->p_pos_y][game()->p_pos_x];

    if (exit_condition == 1)
    {
        exit_game(EXIT_SUCCESS, STDOUT_FILENO, "\033[32mSUCCESS!, YOU WIN\033[0m");
    }
    else if (exit_condition == 0)
    {
        fill_map()->map[game()->p_pos_y][game()->p_pos_x] = '0';
        fill_map()->map[game()->p_pos_y + y_mov][game()->p_pos_x + x_mov] = 'P';
        game()->p_pos_x += x_mov;
        game()->p_pos_y += y_mov;
        game()->count_movements++;
        print_moves();
    }
    else if (fill_map()->map[game()->p_pos_y + y_mov][game()->p_pos_x + x_mov] == '0' 
				|| fill_map()->map[game()->p_pos_y + y_mov][game()->p_pos_x + x_mov] == 'C')
    {
        if (fill_map()->map[game()->p_pos_y + y_mov][game()->p_pos_x + x_mov] == 'C')
            game()->collected_coll++;
        if (current_tile == 'E')
            fill_map()->map[game()->p_pos_y][game()->p_pos_x] = 'E';
        else
            fill_map()->map[game()->p_pos_y][game()->p_pos_x] = '0';
        fill_map()->map[game()->p_pos_y + y_mov][game()->p_pos_x + x_mov] = 'P';
        game()->p_pos_x += x_mov;
        game()->p_pos_y += y_mov;
        game()->count_movements++;
        print_moves();
    }
}

int keyboard_input(int key, t_display *display)
{
    int x_mov = 0, y_mov = 0;

    if (key == D || key == RIGHT)
    {
        x_mov = 1;
    }
    else if (key == A || key == LEFT)
    {
        x_mov = -1;
    }
    else if (key == W || key == TOP)
    {
        y_mov = -1;
    }
    else if (key == S || key == BOTTOM)
    {
        y_mov = 1;
    }
    else if (key == ESC)
    {
        exit_game(EXIT_SUCCESS, STDOUT_FILENO,
                  "\033[33;1mGame exited by user.\033[0m\n");
    }

    if (x_mov != 0 || y_mov != 0)
    {
        img()->character_current = img()->character;
        move_charater(y_mov, x_mov);
        redraw_map();
    }

    (void)display;
    return (0);
}


void	game_play(void)
{
	redraw_map();
	mlx_key_hook(open_window()->mlx_win, keyboard_input, open_window());
}
