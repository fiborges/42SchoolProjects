/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <firibeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:35:24 by firibeir          #+#    #+#             */
/*   Updated: 2023/03/14 15:51:39 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/libft.h"

t_map	*fill_map(void)
{
	static t_map	map;

	return (&map);
}

static uint8_t	is_not_ber(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (len < 5 || *(path + len - 5) == '/')
		return (1);
	if (ft_strcmp(path + len - 4, ".ber"))
		return (1);
	else
		return (0);
}

static void	get_map_info(char *file_path)
{
	int		fd;
	char	*line;

	fill_map()->height = 0;
	fd = open(file_path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		if (fill_map()->height == 0)
			fill_map()->width = (int)ft_strlen(line) - 1;
		fill_map()->height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

static void	get_map_format(char *file_path)
{
	char	*tmp;
	char	*line;
	int		fd;
	int		y;

	fill_map()->map = malloc((fill_map()->height + 1) * sizeof(char **));
	if (!fill_map()->map)
		exit_game(EXIT_FAILURE, STDERR_FILENO, ERR_MEM);
	fd = open(file_path, O_RDONLY);
	y = 0;
	tmp = get_next_line(fd);
	while (tmp)
	{
		line = ft_strtrim(tmp, "\n");
		fill_map()->map[y] = line;
		free(tmp);
		y++;
		tmp = get_next_line(fd);
	}
	fill_map()->map[y] = NULL;
	close(fd);
}

void	map_initialize(char *file_path)
{
	if (is_not_ber(file_path))
	{
		ft_putstr_fd(ERR_BER, 2);
		exit(EXIT_SUCCESS);
	}
	get_map_info(file_path);
	get_map_format(file_path);
	check_map();
}
