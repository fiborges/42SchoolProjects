/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:23:49 by firibeir          #+#    #+#             */
/*   Updated: 2022/11/06 17:40:17 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*#include <stdio.h>
#include <fcntl.h>

int main () 
{
     char c= 'L';


	int	fd;
       	fd = open("text.txt", O_WRONLY);
	ft_putchar_fd(c, fd);
	close(fd);
     return(0);
}*/
