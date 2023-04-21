#include "minishell.h"

int	is_file_descriptor(char *input)
{
	int	i;

	i = 0;
	while (input[i] && !ft_strrchr(";|\t <>", input[i]))
	{
		if (!ft_isdigit(input[i]))
			return (0);
		i++;
	}
	return (i);
}

int	get_quote_status(char input, int quote)
{
	if (input == '\"')
		return (quote * (quote != 2) + 2 * (quote == 0));
	if (input == '\'')
		return (quote * (quote != 1) + 1 * (quote == 0));
	return (quote * (quote != 3) + 3 * (quote == 0 && input == '\\'));
}

int	get_word_size(char *input)
{
	int	i;
	int	quote;

	i = 0;
	quote = 0;
	while ((!ft_strchr(";|\n\t\v\r<> ", input[i]) || quote) && input[i])
	{
		if (input[i] == '\\' && input[i + 1] == '"' && quote == 2)
			i += 2;
		quote = get_quote_status(input[i], quote);
		i++;
	}
	return (i);
}

int	get_control_op_size(char *input)
{
	int	i;
	int	op_size;

	i = 0;
	op_size = 0;
	if (input[i] == ';' || input[i] == '|' || input[i] == '\n')
		op_size++;
	if (input[i] == '>')
	{
		op_size++;
		if (input[i + op_size] == '>')
			op_size++;
	}
	if (input[i] == '<')
		op_size++;
	return (op_size);
}

int	is_whitespace(char input)
{
	if (!ft_strrchr(" \t\v\f\r", input))
		return (0);
	return (1);
}
