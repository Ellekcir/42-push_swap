#ifndef	PUSH_SWAP_H
# define	PUSH_SWAP_H

#include "./libft/libft.h"
// Standard library for memory allocation
# include <stdlib.h>
// Standard library to use write
# include <unistd.h>

// defines a node in the stack
// holds a value and a pointer to the next node.
typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

// defines a stack
// holds a pointer to the top node and the size of the stack
typedef struct s_stack
{
	t_node	*top; // Pointer to the top node of the stack
	int		size; // Size of the stack (number of elements)
}	t_stack;

//--- Stack Operations ---//
// Pushs an element from one stack to another
void	push(t_stack *from, t_stack *to);
// Swaps top two elements of the stack
void	swap(t_stack *stack);
// Rotates the stack 
// (move the top element to the bottom)
void	rotate(t_stack *stack);
// Function to reverse rotate the stack 
//( move the bottom element to the top)
void	reverse_rotate(t_stack *stack);

//---- Algorithms ---//
// Sorts small sets of numbers 
// (five or less - Selection Sort)
void	sort_small(t_stack *a, t_stack *b);
// Sorts larger sets of numbers using more complex algorithm
// (Radix Sort)
void	sort_large(t_stack *a, t_stack *b);

//--- Utils ---//
// Handle errors and exit the program
void	exit_error(void);
// Initialise a new stack and return its pointer
t_stack	*init_stack(void);
// Checks if the stack is sorted in ascending order
int		is_sorted(t_stack *stack);
// Takes the command-line arguments and populates the stack
int		input_args(t_stack *stack, int argc, char **argv);

#endif