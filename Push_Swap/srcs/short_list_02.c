#include "Push_swap.h"

static void	index_two(t_list **stack_a, t_list **stack_b,
t_list	*first_number, t_list *second_number)
{
	if (first_number->nb < second_number->nb)
		reverse_rotate(stack_a, stack_b, RRA);
	else if (first_number->nb > second_number->nb)
	{	
		rotate(stack_a, stack_b, RA);
		swap(stack_a, stack_b, SA);
	}
}

static void	index_zero(t_list **stack_a, t_list **stack_b,
t_list	*second_number, t_list	*third_number)
{
	if (second_number->nb > third_number->nb)
	{
		swap(stack_a, stack_b, SA);
		rotate(stack_a, stack_b, RA);
	}
}

static void	index_one(t_list **stack_a, t_list **stack_b,
t_list	*first_number, t_list	*third_number)
{
	if (first_number->nb < third_number->nb)
		swap(stack_a, stack_b, SA);
	else if (first_number->nb > third_number->nb)
		rotate(stack_a, stack_b, RA);
}

void	sort_three(t_list **stack_a, t_list **stack_b, int lower_index)
{
	int		min_pos;
	t_list	*first_number;
	t_list	*second_number;
	t_list	*third_number;

	min_pos = get_position(stack_a, lower_index);
	first_number = *stack_a;
	second_number = first_number->next;
	third_number = second_number->next;
	if (min_pos == 0)
		index_zero(stack_a, stack_b, second_number, third_number);
	if (min_pos == 1)
		index_one(stack_a, stack_b, first_number, third_number);
	if (min_pos == 2)
		index_two(stack_a, stack_b, first_number, second_number);
}
