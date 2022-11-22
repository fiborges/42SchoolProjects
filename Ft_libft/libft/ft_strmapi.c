/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:14:13 by firibeir          #+#    #+#             */
/*   Updated: 2022/11/06 20:23:18 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	if (!s || !f)
		return (NULL);
	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s)) + 1);
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*char my_func(unsigned int i, char str)
{
		printf("My function: index = %d and %c\n", i, str);
		return (str - 32);
}

int main()
{
	char str[10] = "maria.";
	char *result;
	
 	printf("The result is %s\n", str);
 	result = ft_strmapi(str, my_func);
 	printf("The result is %s\n", result);
 	return 0;
}*/
