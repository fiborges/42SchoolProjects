#include "minishell.h"

void	copy_inside_quotes(char **src, char **dst, char quote)
{
	int	slash_count;

	while (**src != quote)
	{
		slash_count = 0;
		while (**src == '\\' && quote == '"')
		{
			*((*dst)++) = *((*src)++);
			slash_count++;
		}
		if (slash_count && !(slash_count % 2))
			*((*dst)--) = *((*src)--);
		*((*dst)++) = *((*src)++);
	}
}

void	input_copy(char *dst, char *src)
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
			copy_inside_quotes(&src, &dst, quote);
			*(dst++) = *(src++);
		}
		else if (*src == '\\' && *(src + 1))
			escape_char(&dst, &src);
		else
			*(dst++) = *(src++);
	}
	*dst = '\0';
}

static int	input_len(char *str, int *len, int quote)
{
	while (*str)
	{
		if (*str == ' ' && (*(str + 1) == ' ' || *(str + 1) == '\0'))
			str++;
		else if (*str == '\t' && (*(str + 1) == '\t' || *(str + 1) == '\0'))
			str++;
		else if (*str == '\\' && (str + 2))
		{
			*len += 4;
			str += 2;
		}
		else if (*str == '"' || *str == '\'')
		{
			quote = *(str++);
			quote_len(&str, len, quote);
			if (!*str)
				return (-1);
			str++;
			*len += 2;
		}
		else if (str++)
			*len = *len + 1;
	}
	return (*len);
}

char	*input_cleaner(char *str)//
{
	int		len;
	char	quote;
	char	*clean_input;
	char	*str_start;

	quote = 0;
	str_start = str;
	while (*str == ' ' && *str)
		str++;
	len = 0;
	len = input_len(str, &len, quote);
	if (len == -1)
		return (0);
	clean_input = (char *)malloc((len + 1) * sizeof(char));
	if (!clean_input)
		exit(EXIT_FAILURE);
	input_copy(clean_input, str);
	free(str_start);
	return (clean_input);
}

int	process_and_execute_input(char *clean_input, t_data *data, int piped)
{
	char	**inputs;
	int		oldfd[2];

	oldfd[0] = dup(1);
	oldfd[1] = dup(0);
	clean_input = input_cleaner(clean_input);
	parser_redir(&clean_input, data);
	clean_input = expand_variables(clean_input, data);
	clean_input = input_cleaner(clean_input);
	if (*clean_input != 0)
	{
		inputs = input_split(clean_input);
		free(clean_input);
		select_cmd(inputs, data);
		free_inputs(inputs);
	}
	dup2(oldfd[0], 1);
	dup2(oldfd[1], 0);
	close_fds(data);
	close(oldfd[0]);
	close(oldfd[1]);
	if (piped)
		exit_pipe(data);
	return (0);
}