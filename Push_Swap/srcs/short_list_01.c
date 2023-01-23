#include "Push_swap.h"

void	short_stack(t_list **stack_a, t_list **stack_b, int number_args)
{
	if (number_args == 2)
		sort_two(stack_a, stack_b, 0);
	if (number_args == 3)
		sort_three(stack_a, stack_b, 0);
	if (number_args == 4)
		sort_four(stack_a, stack_b, 0);
	if (number_args == 5)
		sort_five(stack_a, stack_b, 0);
}

/*
finds the position of an element in a singly linked list (passed as the parameter 
"list") with a specific index value (passed as the parameter "lower_index").
while loop to iterate through the linked list. 
For each element in the list, it checks if the element's index is equal to the 
specified "lower_index". If it is, it returns the current position 
of the element in the list, indicating that the element has 
been found.
If the element is not found, it increments the variable and 
continues to the next element in the list.
If the while loop completes, it returns the final value variable, which is
 the position of the element with the specified index in the list.
*/

int	get_position(t_list **stack, int lower_index)
{
	t_list	*aux;
	int		pos;

	pos = 0;
	aux = *stack;
	while (aux)
	{
		if (aux->index == lower_index)
			return (pos);
		pos++;
	aux = aux->next;
	}
	return (pos);
}


void	sort_two(t_list **stack_a, t_list **stack_b, int lower_index)
{
	int		min_pos;

	min_pos = get_position(stack_a, lower_index);
	if (min_pos == 1)
		swap(stack_a, stack_b, SA);
}

void	sort_four(t_list **stack_a, t_list **stack_b, int lower_index)
{
	int		min_pos;
	int		size;
	int		reverse;
	t_list	*top;

	min_pos = get_position(stack_a, lower_index);
	size = ft_lstsize(*stack_a);
	reverse = 0;
	top = *stack_a;
	if (min_pos > size / 2)
		reverse = 1;
	while (top->index != lower_index)
	{
		if (!reverse)
			rotate(stack_a, stack_b, RA);
		else if (reverse)
			reverse_rotate(stack_a, stack_b, RRA);
		top = *stack_a;
	}
	push(stack_a, stack_b, PB);
	sort_three(stack_a, stack_b, lower_index + 1);
	push(stack_a, stack_b, PA);
}

void	sort_five(t_list **stack_a, t_list **stack_b, int lower_index)
{
	int		min_pos;
	int		size;
	int		reverse;
	t_list	*top;

	min_pos = get_position(stack_a, lower_index);
	size = ft_lstsize(*stack_a);
	reverse = 0;
	top = *stack_a;
	if (min_pos > size / 2)
		reverse = 1;
	while (top->index != lower_index)
	{
		if (!reverse)
			rotate(stack_a, stack_b, RA);
		else if (reverse)
			reverse_rotate(stack_a, stack_b, RRA);
		top = *stack_a;
	}
	push(stack_a, stack_b, PB);
	sort_four(stack_a, stack_b, 1);
	push(stack_a, stack_b, PA);
}
