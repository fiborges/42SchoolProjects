/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipa <filipa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:41:11 by firibeir          #+#    #+#             */
/*   Updated: 2023/03/18 12:18:51 by filipa           ###   ########.fr       */
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

/*
There is a problem with the fill_words function in this program. In the while loop where it is 
copying the words from the input string to the array, it is not 
incrementing the index i or moving to the next word in the string.
 Instead, it is copying the same word over and over again, leading to
  an infinite loop and eventually causing a segmentation fault when the
   program tries to access memory that it should not.

To fix this, you need to update the loop in fill_words to move to the
 next word after each copy. You can do this by adding the line i += word_size(&str[i]); 
 after the call to copy_word. This will move the index to the next word in the string,
  skipping over any whitespace characters.
In the fill_words function, the copy_word function is called with the 
argument &str[i]. This is because str is a pointer to the beginning of the
 input string, and i is an index into the string indicating the current
  position that we are copying from. By using the address-of operator (&) to take 
  the address of the character at index i in str, we are passing a pointer to the 
  current word to the copy_word function.

The copy_word function takes a pointer to a character and copies a word
 from that point in the string, so by passing it &str[i] we are
  effectively telling it to copy the word starting at index i in the 
  input string.

Note that this is a common C idiom for passing a substring to a 
function - you pass a pointer to the start of the substring, and then
 let the function figure out the length of the substring by scanning 
 for the end-of-string marker (in this case, either a space, tab,
  newline, or null terminator).
*/