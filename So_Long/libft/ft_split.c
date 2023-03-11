/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:41:11 by firibeir          #+#    #+#             */
/*   Updated: 2022/11/06 20:19:11 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sep(char c, char s)
{
	if (c == s || c == '\0')
		return (1);
	return (0);
}

static int	count_words(char *str, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i] != '\0')
	{
		if (is_sep(str[i + 1], c) && !is_sep(str[i], c))
			words++;
		i++;
	}
	return (words);
}

static void	write_w(char *dst, const char *src, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

static void	write_t(char **str_s, const char *str, char c)
{
	int	i;
	int	j;
	int	word;

	i = 0;
	word = 0;
	while (str[i] != '\0')
	{
		if (is_sep(str[i], c))
			i++;
		else
		{
			j = 0;
			while (!is_sep(str[i + j], c))
				j++;
			str_s[word] = malloc(sizeof(char) * (j + 1));
			write_w(str_s[word], str + i, j);
			i = i + j;
			word++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		words;

	if (s == NULL)
		return (NULL);
	words = count_words((char *)s, c);
	str = malloc(sizeof(char *) * (words + 1));
	if (!str)
		return (NULL);
	str[words] = 0;
	write_t(str, s, c);
	return (str);
}

/*int main(void)
{
	char const *s;
	char c;
	char **split;

	s = "Filipa,manuela,ribeiro";
	c = ',';
	split = ft_split(s, c);
	printf("%s \n", split[0]);
	printf("%s \n", split[1]);
	printf("%s \n", split[2]);
	return(0);
	
}*/
