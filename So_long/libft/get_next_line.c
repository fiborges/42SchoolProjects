/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <firibeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:56:03 by firibeir          #+#    #+#             */
/*   Updated: 2023/03/14 15:56:04 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <limits.h>

char	*ft_read(int fd, char *s)
{
	char	*str;
	int		size;

	str = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!str)
		return (NULL);
	size = 1;
	while (!ft_strchr1(s, '\n') && size != 0)
	{
		size = read(fd, str, BUFFER_SIZE);
		if (size == -1)
		{
			free(str);
			return (NULL);
		}
		str[size] = '\0';
		s = ft_strjoin(s, str);
	}
	free(str);
	return (s);
}

char	*get_next_line(int fd)
{
	char		*get;
	static char	*str[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str[fd] = ft_read(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	get = ft_line(str[fd]);
	str[fd] = ft_new(str[fd]);
	return (get);
}
