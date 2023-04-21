#include "minishell.h"

static int	set_control_token_type(char *input, t_token *previous_token, char *str)
{
	int	token_info;

	if (input[0] == ';')
		token_info = SEMICOLON;
	if (input[0] == '>' || input[0] == '<')
		token_info = REDIR;
	if (input[0] == '|')
		token_info = PIPE;
	if (token_info == REDIR && previous_token->token_type == REDIR)
		return (print_parser_err(str));
	if ((token_info == SEMICOLON || token_info == PIPE) && \
			previous_token->token_type != WORD)
		return (print_parser_err(str));
	previous_token->token_type = token_info;
	return (0);
}

static int	validate_word_input(char *input, t_token *previous_token, char *str, int size)
{
	int	next_char;
	int	fd_true;

	next_char = 1 * (input[size] == '>' || input[size] == '<');
	fd_true = is_file_descriptor(input);
	if ((next_char && fd_true && (previous_token->token_type == REDIR)))
		return (print_parser_err(str));
	previous_token->token_type = WORD;
	return (0);
}

static int	update_parser_token(char *input, int size, t_token *previous_token, int id)
{
	char	*str;
	int		parser_result;

	if (previous_token->str != NULL)
		free(previous_token->str);
	str = ft_substr(input, 0, size);
	if (str == NULL)
		return (print_error(NULL, NULL, strerror(errno), errno + 128));
	if (id == 1)
		parser_result = set_control_token_type(input, previous_token, str);
	else
		parser_result = validate_word_input(input, previous_token, str, size);
	previous_token->str = str;
	return (parser_result);
}

static int	parser_err_finalize(t_token *token)
{
	int	exit_code;

	exit_code = 0;
	if (token->token_type != SEMICOLON && token->token_type != WORD && token->token_type != 0)
		exit_code = print_parser_err(token->str);
	else
		if (token->str != NULL)
			free(token->str);
	return (exit_code);
}

int	check_parse_errors(char *input)
{
	int		i;
	int		token_size;
	int		parser_error_code;
	t_token	token;

	i = 0;
	ft_memset(&token, 0, sizeof(t_token));
	parser_error_code = 0;
	while (input[i])
	{
		token_size = get_word_size(input + i);
		if (token_size > 0)
			parser_error_code = update_parser_token(input + i, token_size, &token, 0);
		else
		{
			token_size = get_control_op_size(input + i);
			if (token_size > 0)
				parser_error_code = update_parser_token(input + i, token_size, &token, 1);
		}
		if (parser_error_code != 0)
			return (parser_error_code);
		i += token_size;
		i += is_whitespace(input[i]);
	}
	return (parser_err_finalize(&token));
}