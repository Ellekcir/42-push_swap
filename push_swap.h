#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#define INT_MIN -2147483648
#define INT_MAX 2147483647

#include "./libft/libft.h"
// Standard library for memory allocation/ and exit funciton
#include <stdlib.h>
// Standard library to use write
#include <unistd.h>
// MAX & MIN
#include <limits.h>
//
#include <string.h>
//---------------------------------------------------//
//---------------------LINKED LISTS------------------//
//---------------------------------------------------//
// defines a node in the stack
// holds a value and a pointer to the next node.
typedef struct s_node
{
	int value;
	int target_index;
	int index;
	struct s_node *next;
} t_node;

// defines a stack
// holds a pointer to the top node and the size of the stack
typedef struct s_stack
{
	t_node *top;// Pointer to the top node of the stack
	int max_value;  
	int size;	 // Size of the stack (number of elements)
} t_stack;
//---------------------------------------------------//
//--------------Stack operations---------------------//
//---------------------------------------------------//
// Pushs an element from one stack to another
void ft_push(t_stack *from, t_stack *to);
// Swaps top two elements of the stack
void ft_swap(t_stack *stack);
// Rotates the stack
// (move the top element to the bottom)
void ft_rotate(t_stack *stack);
// Function to reverse rotate the stack
//( move the bottom element to the top)
void ft_reverse_rotate(t_stack *stack);
//---------------------------------------------------//
//---------------Stack instructins-------------------//
//---------------------------------------------------//
// Pushes first element of stack B and puts it at the top of Stack A
void ft_pa(t_stack *a, t_stack *b);
// Pushes the first element of Stack A and put it at top of Stack B
void ft_pb(t_stack *a, t_stack *b);
// Moves the top of Stack A to the bottom.
void ft_ra(t_stack *a);
// Moves the top of Stack B to the bottom.
void ft_rb(t_stack *b);
// Simultaneously rotates both Stacks A and B
void ft_rr(t_stack *a, t_stack *b);
// Moves the bottom of Stack A to the top.
void ft_rra(t_stack *a);
// Moves the bottom of Stack B to the top.
void ft_rrb(t_stack *b);
// Simultaneously reverse rotates both Stacks A and B
void ft_rrr(t_stack *a, t_stack *b);
// Swap the first two elements at the top of Stack A
void ft_sa(t_stack *a);
// Swap the first two elements at the top of Stack B
void ft_sb(t_stack *b);
// Swap the first two elements at the top of Stack A
void ft_ss(t_stack *a, t_stack *b);
//---------------------------------------------------//
//---------------Stack Functions---------------------//
//---------------------------------------------------//
// Function to create a new node
t_node *create_node(int value);
// Function to create a new stack
t_stack *create_stack(void);
// Example of pushing a value onto the stack
void put_value_to_stack(t_stack *stack, int value);
// Example of popping a value from the stack
int free_nodes_from_stack(t_stack *stack);
// Free the stack and its nodes
void free_stack(t_stack *stack);
//---------------------------------------------------//
//---------------Input Validation--------------------//
//---------------------------------------------------//
int ft_issorted(t_stack *stack);
int ft_isint(const char *arg);
int ft_isdup(char **argv);
void ft_check_args_are_valid(char **argv);
//---------------------------------------------------//
//-----------------Utils-----------------------------//
//---------------------------------------------------//
int ft_strcmp(const char *s1, const char *s2);
void ft_error(char *s);
void	print_stack(t_stack *stack);
int is_empty(t_stack *stack);
//---------------------------------------------------//
//---------------Sorting Algorithms------------------//
//---------------------------------------------------//
// Sorts small sets of numbers
// (five or less - Selection Sort)
int find_min(t_stack *stack);
void	sort_two(t_stack *a);
void	sort_three(t_stack *a);
void	sort_to_five(t_stack *a, t_stack *b);
void	sort_five_or_less(t_stack *a, t_stack *b);

// Sorts larger sets of numbers using more complex algorithm
// (Radix Sort)
void assign_sorted_indices(t_stack *stack);
void assign_target_values(t_stack *a);
void sort_radix(t_stack *a, t_stack *b);
int	find_max(t_stack *stack);
int	stack_size(t_stack *stack);
void	process_digit(t_stack *a, t_stack *b, int digit_place);
void index_stack(t_stack *stack);
void    index_value(t_stack *stack);

#endif