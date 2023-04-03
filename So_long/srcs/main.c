/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <firibeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:35:35 by firibeir          #+#    #+#             */
/*   Updated: 2023/03/14 15:48:02 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_moves(void)
{
	ft_putstr_fd("Moves : ", 1);
	ft_putnbr_fd(game()->count_movements, 1);
	ft_putchar_fd('\n', 1);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd(ERR_ARGS, 2);
		return (EXIT_SUCCESS);
	}
	map_initialize(argv[1]);
	open_window()->mlx = mlx_init();
	img_initialize();
	window_initialize(open_window());
	game_initialize();
	game_play();
	mlx_loop(open_window()->mlx);
	return (EXIT_SUCCESS);
}
