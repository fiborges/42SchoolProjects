#include "minishell.h"

t_minishell_state g_shell_state;

int	print_parser_err(char *token)
{
	char	*err_msg;
	char	*tmp;

	if (token == NULL)
		return (print_error(NULL, NULL, strerror(errno), errno + 128));
	err_msg = ft_strjoin("syntax error near unexpected token `", token);
	free(token);
	if (err_msg == NULL)
		return (print_error(NULL, NULL, strerror(errno), errno + 128));
	tmp = err_msg;
	err_msg = ft_strjoin(err_msg, "\'");
	free(tmp);
	if (err_msg == NULL)
		return (print_error(NULL, NULL, strerror(errno), errno + 128));
	g_shell_state.status = print_error(NULL, NULL, err_msg, 258);
	free(err_msg);
	return (258);
}

int	print_error(char *command, char *arg, char *err_msg, int exit_code)
{
	write(2, "minishell: ", 11);
	if (command != NULL)
	{
		write(2, command, ft_strlen(command));
		write(2, ": ", 2);
	}
	if (arg != NULL)
	{
		write(2, arg, ft_strlen(arg));
		write(2, ": ", 2);
	}
	g_shell_state.status = exit_code;
	write(2, err_msg, ft_strlen((err_msg)));
	write(2, "\n", 1);
	return (exit_code);
}
