/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:41:55 by firibeir          #+#    #+#             */
/*   Updated: 2022/11/07 09:22:16 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		i;
	size_t		size;
	char		*strtrim;

	if (!s1 || !set)
		return (NULL);
	size = ft_strlen(s1);
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (size > i && ft_strchr(set, s1[size]))
		size--;
	strtrim = ft_substr((char *)s1, i, (size - i) + 1);
	if (!strtrim)
		return (NULL);
	return (strtrim);
}

/*int main(void)
 {
    char *str;
    char *c;
    char *f;
    char *new;
    char *new2;

    str = "   :filipa:maria:      ";
    c = " ";
    f = ":";
    
    new = ft_strtrim (str, c);
    printf("%s\n", new);
    new2 = ft_strtrim (str, c);
    printf("%s\n", new2);
    return(0);
    
}*/
