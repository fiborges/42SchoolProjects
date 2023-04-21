#include "minishell.h"

int	check_special(char **input, int *i, t_data *data)
{
	if ((*input)[*i] == '\'')
	{
		(*i)++;
		while ((*input)[*i] != '\'')
			(*i)++;
	}
	else if ((*input)[*i] == '|')
	{
		parser_pipe((*input), data);
		return (1);
	}
	else if ((*input)[*i] == ';')
	{
		parser_semicolon((*input), *i, data);
		return (1);
	}
	(*i)++;
	return (0);
}

int	parser(char *input, t_minishell_state *shell_state, int piped)
{
	int		i;
	int		num_escapes;

	i = 0;
	while (input[i])
	{
		if (input[i] == '"')
		{
			i++;
			while (input[i] != '"')
			{
				num_escapes = 0;
				while (input[i] == '\\' && ++i)
					num_escapes++;
				if (num_escapes && !(num_escapes % 2))
					i--;
				i++;
			}
		}
		if (check_special(&input, &i, shell_state))
			return (0);
	}
	return (process_and_execute_input(input, shell_state, piped));
}

int	execute_commands_from_input(char *input, t_minishell_state *shell_state)
{
	char	*clean_input;

	if ((check_parse_errors(input)) != 0)
		return (0);
	clean_input = clean_input_str(input);
	shell_state->input = NULL;
	if (clean_input == 0)
	{
		ft_putstr("This minishell does not support multiline commands.\n");
		return (0);
	}
	if (!*clean_input)
	{
		free(clean_input);
		return (0);
	}
	return (parser(clean_input, shell_state, 0));
}
