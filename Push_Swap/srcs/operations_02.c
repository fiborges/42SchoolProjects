#include "Push_swap.h"

/*
The function rotate_stack takes in a double pointer to a singly
linked list and rotates the elements of the list. It starts by defining 
a pointer "top" that points to the first element of the list and a pointer
"end" that points to the last element of the list. If the list has only 
one element, the function returns without doing anything. Otherwise, 
it sets the double pointer to point to the second element of the list, 
sets the next pointer of the last element to point to the first element,
and sets the next pointer of the first element to NULL. This effectively 
rotates the elements of the list by moving the first element to the end 
of the list.
*/

static void	rotate_stack(t_list **stack)
{
	t_list	*top;
	t_list	*end;

	top = *stack;// head = 1 elemento da lista
	end = ft_lstlast(*stack); // tail = ultimo elemento da lista
	if (!top->next)// se nao tiver mais elementos retorna
		return ;
	*stack = top->next;// vai receber o valor a seguir
	end->next = top;//o ultimo elemento recebe o 1 elemento
	top->next = NULL;
}

void	rotate(t_list **stack_a, t_list **stack_b, int instr)
{
	if (instr == RA)
	{
		rotate_stack(stack_a);
		ft_putstr_fd("ra\n", 1);
	}		
	if (instr == RB)
	{
		rotate_stack(stack_b);
		ft_putstr_fd("rb\n", 1);
	}
	if (instr == RR)
	{
		rotate_stack(stack_a);
		rotate_stack(stack_b);
		ft_putstr_fd("rr\n", 1);
	}	
}

/*
The function reverse_rotate_stack takes in a pointer to a pointer
 to a t_list (a singly-linked list), and performs a reverse rotation on 
 the list. It does this by first initializing a pointer aux to the head 
 of the list, and another pointer keep_save to NULL. Then, it iterates 
 through the list until it reaches the last element, using keep_save to 
 keep track of the previous element. Once it reaches the last element, 
 it sets the next pointer of that element to the head of the list, and sets 
 the next pointer of the previous element to NULL, effectively moving the 
 last element to the front of the list. Finally, it updates the pointer to 
 the head of the list to point to the new first element, which completes the 
 reverse rotation.
 */

static void	reverse_rotate_stack(t_list **stack)
{
	t_list	*aux;
	t_list	*keep_save;

	aux = *stack;
	keep_save = NULL;
	while (aux->next)
	{
		keep_save = aux;
		aux = aux->next;
	}
	aux->next = *stack;
	keep_save->next = NULL;
	*stack = aux;
}

void	reverse_rotate(t_list **stack_a, t_list **stack_b, int instr)
{
	if (instr == RRA)
	{
		reverse_rotate_stack(stack_a);
		ft_putstr_fd("rra\n", 1);
	}		
	if (instr == RRB)
	{
		reverse_rotate_stack(stack_b);
		ft_putstr_fd("rrb\n", 1);
	}
	if (instr == RRR)
	{
		reverse_rotate_stack(stack_a);
		reverse_rotate_stack(stack_b);
		ft_putstr_fd("rrr\n", 1);
	}	
}
