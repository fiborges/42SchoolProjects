/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:18:45 by firibeir          #+#    #+#             */
/*   Updated: 2022/11/02 18:09:56 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset (s, 0, n);
}

/*int main(void)
{
    char buffer[80];
    char buffer1[80];

    bzero( buffer, 80 );
    return EXIT_SUCCESS;
    ft_bzero(buffer1, 80);
    return EXIT_SUCCESS;
}*/

// as vezes a memoria dinamica precisa de ser zerada!
//substituida por zeros para limpara valor de lixo.
