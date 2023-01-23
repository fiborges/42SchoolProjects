#include "Push_swap.h"

/*
The function check_duplicate takes in a list, an integer value, 
and a pointer to an error variable. 
It iterates through the list, comparing the integer value to each element
of the list. If it finds a match, it sets the error variable to 1 and returns 1, indicating that a duplicate
has been found. If it doesn't find a match, it returns 0 indicating that 
the integer value is not present in the list.
*/

int	check_double(t_list *stack, int number, int *erro)
{
	t_list	*aux;

	aux = stack;
	while (aux)
	{
		if (number == aux->nb)
		{
			*erro = 1;///encontrou um duplicado
			return (1);
		}
		aux = aux->next;
	}
	return (0);
}

/*
This function takes in a 2D character array (char **stack) as an 
argument and frees the memory allocated to it. It first checks if the 
array is empty, if it is then it returns without doing anything. 
In each iteration, it frees the memory allocated to the element 
at the current index using the free function and increments i. Finally, it 
frees the memory allocated to the array itself using the free function.
*/

static void	free_stack(char **stack)
{	
	int	i;

	if (!stack)
		return ;
	i = -1;
	while (stack[++i])
		free(stack[i]);
	free (stack);
}

/*
splits the first argument (a string of numbers separated by 
spaces) into an array of strings, and iterates through each element of that 
array. It converts each element to an integer and assigns it to a variable 
'nb'. The function then checks if the integer is a valid number and if it is 
a duplicate in the list. If it is a duplicate or not a valid number, 
the function sets the error flag to 1, frees the memory allocated for the 
list, and returns -1. Otherwise, it creates a new list element with the 
integer 'nb' as its value and adds it to the list. Finally, it frees the 
memory allocated for the args array and returns the number of elements added
to the list.
*/

static int	str_arg(char **argv, int *erro, t_list **stack)
{
	int		i;
	int		number;
	char	**args;
	t_list	*new_element;

	args = ft_split(argv[1], ' ');// progrm "2 3 4 5 6"
	i = -1;
	while (args[++i])
	{
		number = ft_atoi_adp(args[i], erro);// 2...
		if (*erro == 1 || check_double(*stack, number, erro))
		{
			ft_lstclear_adp(stack);
			free_stack(args);
			return (-1);// limpa a lista e retorna erro
		}
		new_element = ft_lstnew_adp(number);// adiciona o 2 ao new_element
		ft_lstadd_back(stack, new_element);
	}
	free_stack(args);
	return (i);// retorna o numero de  elementos adicionados a lista 
}
/*
iterates through the arguments, starting from the second one,
 and converts each argument to an integer. 
If the conversion fails or if the number already exists in the list, it sets
the error flag to 1 and returns. Otherwise, it creates a new list element 
with the number and adds it to the list. It continues this process until 
all arguments have been processed.
 */

static void	multiple_args(int argc, char **argv, int *erro,
	t_list **stack)
{
	int		i;
	int		number;
	t_list	*new_element;

	i = 0;
	while (++i < argc)
	{
		number = ft_atoi_adp(argv[i], erro);
		if (*erro == 1 || check_double(*stack, number, erro))
		{
			ft_lstclear_adp(stack);
			return ;
		}
		new_element = ft_lstnew_adp(number);
		ft_lstadd_back(stack, new_element);
	}
}

/*
argc: the number of command line arguments
argv: an array of strings containing the command line arguments
erro: a pointer to an integer to store an error code
stack: a pointer to a pointer to the head of the linked list
The function checks if the number of command line arguments is 2, 
in which case it will parse a single string argument and split it on spaces 
to get individual integers. If the number of command line arguments is 
greater than 2, it will iterate through the arguments and convert each 
argument to an integer, adding it to the linked list.
It returns the number of integers stored in the list, if it failed to 
fill the list it returns -1. The function also sets the error variable 
passed by reference to 1 if it encounters an error, such as a non-numeric 
argument or a duplicate value.
*/

int	fill_stack(int argc, char **argv, int *erro, t_list **stack)
{
	if (argc == 2)
		return (str_arg(argv, erro, stack));
	if (argc > 2)
		multiple_args(argc, argv, erro, stack);
	return (argc - 1);
}
