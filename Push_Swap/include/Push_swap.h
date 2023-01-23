#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "libft.h"


/*
An enumeration, or "enum," is a user-defined data type that 
consists of a set of named values. In this case, the enumeration is 
named "e_instr" and it contains a set of named values for different 
instructions: SA, SB, SS, PA, PB, RA, RB, RR, RRA, RRB, and RRR. 
These values can be used in your code to represent the different instructions,
making it more readable and maintainable.
*/

enum e_instr
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
};

void	give_index(t_list **stack);
int		is_corret(t_list **stack);
int	    ft_atoi_adp(const char *str, int *error);
t_list		*ft_lstnew_adp(int nb);
void	ft_lstclear_adp(t_list **lst);
int		fill_stack(int argc, char **argv, int *erro, t_list **stack);
void	push(t_list **stack_a, t_list **stack_b, int instr);
void	swap(t_list **stack_a, t_list **stack_b, int instr);
void	rotate(t_list **stack_a, t_list **stack_b, int instr);
void	reverse_rotate(t_list **stack_a, t_list **stack_b, int instr);
void	short_stack(t_list **stack_a, t_list **stack_b, int number_args);
int		get_position(t_list **stack, int lower_index);
void	sort_two(t_list **stack_a, t_list **stack_b, int lower_index);
void	sort_four(t_list **stack_a, t_list **stack_b, int lower_index);
void	sort_five(t_list **stack_a, t_list **stack_b, int lower_index);
void	sort_three(t_list **stack_a, t_list **stack_b, int lower_index);
void	long_stack(t_list **stack_a, t_list **stack_b);

#endif