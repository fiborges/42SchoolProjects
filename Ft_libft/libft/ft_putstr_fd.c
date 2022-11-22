/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:28:58 by firibeir          #+#    #+#             */
/*   Updated: 2022/11/06 17:41:24 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	write(fd, s, ft_strlen(s));
}

/*#include <stdio.h>
#include <fcntl.h>

int main () 
{
     char letter[20] = "Life if good.";


	int	fd;
       	fd = open("text.txt", O_WRONLY);
	ft_putstr_fd(letter, fd);
	close(fd);
     return(0);
}*/
