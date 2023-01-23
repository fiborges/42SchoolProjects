/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:46:37 by firibeir          #+#    #+#             */
/*   Updated: 2022/11/05 19:32:36 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (str == NULL)
		return (NULL);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*int main()
{
    char src[] = "maria borges almeida";
 
    // A copy of source is created dynamically
    // and pointer to copy is returned.
    char* dest1 = strdup(src);
    printf("%s \n", dest1);
    char* dest2 = ft_strdup(src);
    printf("%s\n", dest2);
    
    return 0;
}*/
