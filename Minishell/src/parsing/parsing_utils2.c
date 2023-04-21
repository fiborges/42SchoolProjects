#include "minishell.h"

void	quote_size(char **str, int *i, char quote)
{
	int	num_slash;

	while (**str != quote && **str)
	{
		num_slash = 0;
		while (quote == '"' && **str == '\\')
		{
			(*i)++;
			(*str)++;
			num_slash++;
		}
		if (num_slash && !(num_slash % 2))
		{
			(*str)--;
			(*i)--;
		}
		(*i)++;
		(*str)++;
	}
}