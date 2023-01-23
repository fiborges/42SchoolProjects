/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:01:59 by firibeir          #+#    #+#             */
/*   Updated: 2022/11/05 19:24:55 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if ((c >= 32 && c <= 126))
		return (1);
	return (0);
}

/*int main(void)
{
    int maria;
    int joao;
    
    maria = '\n';
    
    joao = ft_isprint(maria);
    if(joao > 0)
    {
       printf("É um carater imprimivel!");
    }
    else
        printf("não é um carater imprimivel!!");
    return(0);
}*/
