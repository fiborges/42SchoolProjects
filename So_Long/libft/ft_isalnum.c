/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:25:24 by firibeir          #+#    #+#             */
/*   Updated: 2022/11/05 19:24:08 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

/*int main(void)
{
    int maria;
    int joao;
    
    maria = '+';
    
    joao = ft_isalnum(maria);
    if(joao > 0)
    {
       printf("É alfanumerico!!");
    }
    else
        printf("não é alfanumerico");
    return(0);
}*/
