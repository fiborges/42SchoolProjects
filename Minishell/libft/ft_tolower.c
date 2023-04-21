/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:50:01 by firibeir          #+#    #+#             */
/*   Updated: 2022/11/05 19:26:05 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if ((c >= 'A' && c <= 'Z'))
		return (c + 32);
	return (c);
}

/*int main(void)
{
    int maria;
    char joao;
    
    maria = 'A';
    
    joao = ft_tolower(maria);
    printf("A LETRA A = %c", joao);
    
    return(0);
}*/
