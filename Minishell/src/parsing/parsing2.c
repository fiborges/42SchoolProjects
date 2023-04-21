#include "minishell.h"

void	insert_quotes(char **dst, char **src)
{
	char	quote;

	(*src)++;
	if (**src == '\'')
		quote = '"';
	else
		quote = '\'';
	*((*dst)++) = quote;
	*((*dst)++) = *((*src)++);
	*((*dst)++) = quote;
}

void	get_text_within_quotes(char **src, char **dst, char quote)
{
	int	num_slashes;

	while (**src != quote)
	{
		num_slashes = 0;
		while (**src == '\\' && quote == '"')
		{
			*((*dst)++) = *((*src)++);
			num_slashes++;
		}
		if (num_slashes && !(num_slashes % 2))
			*((*dst)--) = *((*src)--);
		*((*dst)++) = *((*src)++);
	}
}

void	extract_tokens_from_input(char *dst, char *src)
{
	char	quote;

	while (*src)
	{
		if (*src == ' ' && (*(src + 1) == ' ' || *(src + 1) == '\0'))
			src++;
		else if (*src == '\t' && (*(src + 1) == '\t' || *(src + 1) == '\0'))
			src++;
		else if (*src == '"' || *src == '\'')
		{
			*(dst++) = *src;
			quote = *(src++);
			get_text_within_quotes(&src, &dst, quote);
			*(dst++) = *(src++);
		}
		else if (*src == '\\' && *(src + 1))
			insert_quotes(&dst, &src);
		else
			*(dst++) = *(src++);
	}
	*dst = '\0';
}

static int	calculate_input_size(char *str, int *size, int quote)
{
	while (*str)
	{
		if (*str == ' ' && (*(str + 1) == ' ' || *(str + 1) == '\0'))
			str++;
		else if (*str == '\t' && (*(str + 1) == '\t' || *(str + 1) == '\0'))
			str++;
		else if (*str == '\\' && (str + 2))
		{
			*size += 4;
			str += 2;
		}
		else if (*str == '"' || *str == '\'')
		{
			quote = *(str++);
			quote_size(&str, size, quote);
			if (!*str)
				return (-1);
			str++;
			*size += 2;
		}
		else if (str++)
			*size = *size + 1;
	}
	return (*size);
}

char	*clean_input_str(char *str)
{
	int		size;
	char	quote;
	char	*clean_input;
	char	*str_start;

	quote = 0;
	str_start = str;
	while (*str == ' ' && *str)
		str++;
	size = 0;
	size = calculate_input_size(str, &size, quote);
	if (size == -1)
		return (0);
	clean_input = (char *)malloc((size + 1) * sizeof(char));
	if (!clean_input)
		exit(EXIT_FAILURE);
	extract_tokens_from_input(clean_input, str);
	free(str_start);
	return (clean_input);
}