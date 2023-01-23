#include "Push_swap.h"

/*
finds the next element with the minimum value in a singly linked list 
(passed as the parameter that has an index of -1)

It starts by creating a pointer that points to the head of 
the linked list, and two other pointers "min" and "first" that point to 
the minimum element found so far, and a flag indicating if it is the first 
element found, respectively.
It then iterates through the linked list using a while loop, for each 
element in the list, it checks if the element has an index of -1 and if the 
current element is smaller than the current minimum element found or if it 
is the first element found. If either condition is true, it updates the "min"
pointer to point to the current element and updates the "first" flag to 1.
Finally, it returns the pointer "min" that points to the element with the 
minimum value.
*/

static t_list	*get_lower_index(t_list **stack)
{
	t_list	*min;
	t_list	*aux;
	int		first;

	aux = *stack;//list[0]
	min = NULL;
	first = 0;
	while (aux)
	{
		if (aux->index == -1 && (!first || aux->nb < min->nb))
		{	
			min = aux;
			first = 1;
		}
	aux = aux->next;
	}
	return (min);
}

/*
assigns an index to each element of a singly linked list based on their 
value (passed as the parameter) in ascending order.
uses a while loop that iterates as many times as the length of the 
list, in each iteration, it calls the helper function with 
the list pointer, which returns the element with the minimum value and an 
index of -1.
It assigns the current value of the index variable to the index of the 
returned element and increment the value of the index variable.
It continues iterating until the list has been fully traversed and all 
elements have been assigned an index based on their value.
If the 'index' field of the current element is -1, this means that the 
current element is a candidate to be the next minimum element in the list.
If the 'first' variable is 0 (not set), this means that the current element
 is the first element in the list, so it will be considered as the next 
 minimum element.
If the 'first' variable is set to 1, this means that the current element
 is not the first element in the list, so the function compares the 'nb' 
 field of the current element with the 'nb' field of the current minimum 
 element. If the 'nb' field of the current element is less than the 'nb' 
 field of the current minimum element, the current element becomes the new 
 minimum element.
If the condition is true, the current element becomes the new minimum
 element, the 'min' pointer is set to point to the current element and the 
 'first' variable is set to 1.
 */

void	give_index(t_list **stack)
{
	int		index;
	int		listlen;
	t_list	*tmp;

	index = 0;
	listlen = ft_lstsize(*stack);
	while (listlen--)
	{
		tmp = get_lower_index(stack);
		tmp->index = index++;
	}
}

/*
sort in ascending order based on the index of the elements.
It starts by checking if the list is empty, if it is, it returns 1 
(true), indicating that the list is sorted.
it then creates a pointer "aux" that points to the head of the 
linked list and uses a while loop to iterate through the linked list.
In each iteration, it checks if the current element's index is greater 
than or equal to the next element's index, if it is, it returns 0 (false), 
indicating that the list is not sorted. If not, it continues to the next 
element in the list.If the while loop completes, it returns 1 (true), indicating that the list 
is in the corret order.
*/

int	is_corret(t_list **stack)
{
	t_list	*aux;

	if (!*stack)
		return (1);
	aux = *stack;
	while (aux->next)
	{
		if (aux->index >= aux->next->index)
			return (0);
		aux = aux->next;
	}
	return (1);
}
