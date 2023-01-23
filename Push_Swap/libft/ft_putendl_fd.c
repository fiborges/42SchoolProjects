/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:25:08 by firibeir          #+#    #+#             */
/*   Updated: 2022/11/06 17:41:57 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}

/*#include <stdio.h>
#include <fcntl.h>

int main () 
{
     char s[20] = "Life if good.";


	int	fd;
       	fd = open("text.txt", O_WRONLY);
	ft_putendl_fd(s, fd);
	close(fd);
     return(0);
}*/
