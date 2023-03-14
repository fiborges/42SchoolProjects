/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:51:05 by firibeir          #+#    #+#             */
/*   Updated: 2022/11/05 19:25:27 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if ((c >= 'a' && c <= 'z'))
		return (c - 32);
	return (c);
}

/*int main(void)
{
    int maria;
    char joao;
    
    maria = 'a';
    
    joao = ft_toupper(maria);
    printf("A LETRA a = %c", joao);
    
    return(0);
}*/
