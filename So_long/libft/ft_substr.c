/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:46:31 by firibeir          #+#    #+#             */
/*   Updated: 2022/11/06 18:23:47 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		str = ft_calloc(1, 1);
		if (!str)
			return (NULL);
		return (str);
	}
	i = 0;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*int main(void)
{
    char src[31] = "substr function Implementation";
 
    int start = 7;
    int len = 12;
 
    char* dest = ft_substr(src, start, len);
 
    printf("%s\n", dest);
 
    return 0;
}*/
