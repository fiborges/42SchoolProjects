#include "Push_swap.h"

/*
It starts by creating pointers "top_orig" and "top_dest" that point to the 
head of the two linked lists, respectively. It then checks if the head of 
the "top_orig" is null, if so it returns without doing anything.

It creates a temporary pointer "aux" that points to the head of the 
"top_orig" linked list, then it updates the head of the "top_orig" linked 
list to point to the next element.

It then checks if the head of the "top_dest" linked list is null. If it is, 
it sets the head of the "top_dest" linked list to the temporary pointer "aux" 
and sets the next pointer of "aux" to null.

Otherwise, it sets the next pointer of "aux" to point to the current head of 
the "top_dest" linked list, and sets the head of the "top_dest" linked list to 
"aux".

Finally, it updates the "top_orig" and "top_dest" pointers to point to the 
updated head of the linked lists respectively.

It's important to note that this function is modifying the original linked 
list passed as arguments, it is not returning a new linked list.
*/

static void	push_number(t_list **stack_orig, t_list **stack_dest)
{
	t_list	*top_orig;
	t_list	*top_dest;
	t_list	*aux;

	top_orig = *stack_orig;
	top_dest = *stack_dest;
	if (!top_orig)
		return ;
	aux = top_orig;
	top_orig = top_orig->next;
	if (!top_dest)
	{
		top_dest = aux;
		top_dest->next = NULL;
	}
	else
	{
		aux->next = top_dest;
		top_dest = aux;
	}
	*stack_orig = top_orig;
	*stack_dest= top_dest;
}

/*
moves an element from the front of one linked list to the front of another 
linked list, based on the input instruction passed as the parameter "instr".

It checks if the instruction is equal to "PA", if so it calls the helper 
function "push_number" with the stack_b and stack_a pointers, which moves the 
element from the front of stack_b to the front of stack_a.
It then prints the instruction "pa\n" to the standard output.

It checks if the instruction is equal to "PB", if so it calls the helper 
function "push_number" with the stack_a and stack_b pointers, which moves the 
element from the front of stack_a to the front of stack_b.
It then prints the instruction "pb\n" to the standard output.
*/

void	push(t_list **stack_a, t_list **stack_b, int instr)
{
	if (instr == PA)
	{
		push_number(stack_b, stack_a);
		ft_putstr_fd("pa\n", 1);
	}
	if (instr == PB)
	{
		push_number(stack_a, stack_b);
		ft_putstr_fd("pb\n", 1);
	}		
}

/*
helper function that swaps the first two elements of a linked list 
(passed as the parameter "list").

Updates the next pointer of the "first" element to point to 
the next element of the "second" element and updates the next pointer of the 
"second" element to point to the "first" element.

Finally, it updates the list pointer to point to the "second" element, 
effectively swapping the first two elements of the linked list.

 */

static void	swap_number(t_list **stack)
{
	t_list	*top;
	t_list	*first;
	t_list	*second;

	top = *stack;
	first = top;
	second = first->next;
	if (!top || !top->next)
		return ;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

/*
This code is a function called "swap" that swaps the first two elements of
 a singly linked list based on the input instruction passed as the parameter 
 "instr".

It checks if the instruction is equal to "SA", if so it calls the helper 
function "swap_number" with the stack_a pointer, which swaps the first two 
elements of the stack_a. It then prints the instruction "sa\n" to the standard
 output.

It checks if the instruction is equal to "SB", if so it calls the helper 
function "swap_number" with the stack_b pointer, which swaps the first two
 elements of the stack_b. It then prints the instruction "sb\n" to the 
 standard output.

It checks if the instruction is equal to "SS", if so it calls the helper 
function "swap_number" with the stack_a and stack_b pointers, which swaps 
the first two elements of both stack_a and stack_b. It then prints the 
instruction "ss\n" to the standard output.
*/

void	swap(t_list **stack_a, t_list **stack_b, int instr)
{
	if (instr == SA)
	{
		swap_number(stack_a);
		ft_putstr_fd("sa\n", 1);
	}
	if (instr == SB)
	{
		swap_number(stack_b);
		ft_putstr_fd("sb\n", 1);
	}
	if (instr == SS)
	{
		swap_number(stack_a);
		swap_number(stack_b);
		ft_putstr_fd("ss\n", 1);
	}		
}
