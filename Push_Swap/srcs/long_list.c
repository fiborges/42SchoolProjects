#include "Push_swap.h"

/*
This function is finding the maximum number of bits needed to represent 
the given list length. It is doing this by continually shifting the stack size
 to the right (divide by 2) and counting the number of times it can be
 shifted before the value becomes 0. This number of shifts is equal to the 
 number of bits needed to represent the stack size. The returned value is 
 bits.

 */

static int	total_bits(int size)
{
	int	bits;

	bits = 0;
	while ((size >> bits) != 0)
		bits++;
	return (bits);
}

/*
The function long_stack is a sorting algorithm that sorts a linked 
list of integers in ascending order. It first finds the maximum number of 
bits required to represent the largest index value in the stack using the 
function total_bits. 
It then iterates through each bit position, 
starting from the least significant bit and moving towards the most 
significant bit. 
For each bit position, it iterates through the list and 
pushes elements with a 1 at that bit position to the stack_b, otherwise it 
rotates that element to the top of stack_a. 
It continues this process until all elements have been sorted into stack_b. 
Finally, it pushes all elements from stack_b back to stack_a in the
correct order.
This sorting algorithm is known as "Binary Tree Sort" or "Radix Sort".
*/
 
void	long_stack(t_list **stack_a, t_list **stack_b)
{
	int		i;
	int		j;
	int		size;
	int		bits;
	t_list	*aux;

	i = -1;
	size = ft_lstsize(*stack_a);
	bits = total_bits(size - 1);
	while (++i < bits)
	{
		j = -1;
		while (++j < size)
		{
			aux = *stack_a;
			if (((aux->index >> i) & 1) == 1)//vai para o fim pk esse ja vimos queremos passar para o a seguir
				rotate(stack_a, stack_b, RA);// rotates the elements of the list by moving the first element to the end of the list. 
			else
				push(stack_a, stack_b, PB);// which moves the element from the front of list_a to the front of list_b.
		}
		aux = *stack_b;//list_b[0]
		while (ft_lstsize(*stack_b))
			push(stack_a, stack_b, PA);//moves the element from the front of list_b to the front of list_a.
	}
}
