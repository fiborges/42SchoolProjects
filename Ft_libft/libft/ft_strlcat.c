/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:02:26 by firibeir          #+#    #+#             */
/*   Updated: 2022/11/10 11:07:31 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	n;
	size_t	dst_size;

	n = 0;
	if (dst)
		dst_size = ft_strlen(dst);
	else
		dst_size = 0;
	i = dst_size;
	if (size == 0)
		return (ft_strlen(src));
	if (size < dst_size)
		return (ft_strlen(src) + size);
	else
	{
		while (src[n] && (dst_size + n) < size)
			dst[i++] = src[n++];
		if ((dst_size + n) == size && dst_size < size)
			dst[--i] = '\0';
		else
			dst[i] = '\0';
		return (ft_strlen(src) + dst_size);
	}
}

/*int main(void)
{
    char first[] = "i love you ";
    char last[] = "maria viera borges de almeida";
    
    int resultado;
    int size = 42;
    
    char buffer[size];

    strcpy(buffer, first);
    resultado = ft_strlcat (buffer, last, size);

    puts(buffer);
    printf("valor: %d\n", resultado);
    if(resultado > size)
        puts("string truncated");
    else
        puts("string was fully copied");

return(0);  
}*/
