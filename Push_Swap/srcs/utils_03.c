#include "Push_swap.h"

/*
This is a conditional statement that checks for errors in 
the conversion process. The *error variable is set to 1 if any of the 
following conditions are met:
str[i] is not a null character, indicating that there are non-numeric
characters after the number.
result is not equal to tmp, indicating that the number is out of int 
range
sign > 0 and ft_strlen(str) > 10, indicating that the positive number 
is too long to fit in an int
sign < 0 and ft_strlen(str) > 11, indicating that the negative number 
is too long to fit in an int
It is important to note that the ft_strlen() function is a custom 
implementation of the standard strlen() function and it is used here to 
check the length of the string.
This implementation is useful to keep track of the error and handle it 
properly in the main program.
*/

int	ft_atoi_adp(const char *str, int *error)
{
	int			i;
	int			sign;
	long long	result;
	int			tmp;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{	
		sign = -sign;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + str[i++] - '0';
	result *= sign;
	tmp = (int)result;
	if (str[i] || result != tmp || (sign > 0 && ft_strlen(str) > 10)
		|| (sign < 0 && ft_strlen(str) > 11))
		*error = 1;
	return (result);
}

/*
creates a new element of a linked list, called t_list. 
The function takes an integer 'nb' as an argument, and it allocates memory 
for a new t_list element using the malloc function. 
The element's 'nb' field is set to the value of the argument passed to the function,
'index' field is set to -1 and the 'next' field is set to NULL.
The function returns the newly created element, or NULL if the malloc
function failed to allocate memory.
*/

t_list	*ft_lstnew_adp(int nb)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->nb = nb;
	new->index = -1;
	new->next = NULL;
	return (new);
}

/*
The function first checks if the passed pointer is a null pointer by using
 the ! operator and return if it is the case.
 The function then initializes two pointers, tmp and tmp_prev, and assigns 
the value of the passed pointer to tmp.
The function then enters a while loop that will iterate through the entire 
linked list, freeing each element of the list one by one. It uses the 
tmp_prev pointer to temporarily store the current node, then assigns the 
value of the next node to the tmp pointer.
It then frees the memory allocated for the current node using the free() 
function, and continues iterating until the end of the list.
After the loop, the passed pointer is set to NULL, effectively clearing 
the entire list.
This function is useful when you want to clear all the elements of a list 
and release the memory they were using.
*/

void	ft_lstclear_adp(t_list **lst)
{
	t_list	*tmp_prev;
	t_list	*tmp;

	if (!lst)
		return ;
	tmp = *lst;
	while (tmp)
	{
		tmp_prev = tmp;
		tmp = tmp_prev->next;
		free(tmp_prev);
	}
	*lst = NULL;
}
