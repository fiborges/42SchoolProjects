#include "Push_swap.h"

/*
typedef struct s_list
{
	void			*content;
	int				nb;
	int				index;
	struct s_list	*next;
}	t_list;
*/

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		erro;
	int		number_args;

	stack_a = NULL;
	stack_b = NULL;
	erro = 0;
	number_args = fill_stack(argc, argv, &erro, &stack_a);
	if (erro)
		return (ft_putstr_fd("Error \n", 2), -1);
	give_index(&stack_a);//distribuir index
	if (is_corret(&stack_a))
		return (ft_lstclear_adp(&stack_a), 0);//limpa a lista e retorna 0
	if (number_args >= 6)
		long_stack(&stack_a, &stack_b);//radix sort
	else if (number_args >= 2)
		short_stack(&stack_a, &stack_b, number_args);
	ft_lstclear_adp(&stack_a);//limpa a lista a
	ft_lstclear_adp(&stack_b);//limpa lista b
	return (0);
}
