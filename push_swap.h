/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgriffit <rgriffit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:23:58 by rgriffit          #+#    #+#             */
/*   Updated: 2024/12/12 20:38:08 by rgriffit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
// Includes the necessary libraries
//  "./libft/libft.h" For custom libft functions
// <stdlib.h> For memory allocation and exit functions
// <unistd.h> For write functionality
// <limits.h> For INT_MAX and INT_MIN
// <stdbool.h> For boolean values
# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
//---------------------------------------------------//
//---------------------LINKED LISTS------------------//
//---------------------------------------------------//
// Node structure representing each element in the stack
// It holds the value, target position (when sorted), 
// and a pointer to the next node in the stack
typedef struct s_node
{
	int				value;
	int				target;
	struct s_node	*next;
}	t_node;
// Stack structure representing the entire stack
// It holds the top node, the size of the stack, 
// and a reference to the stack's head
typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;
//---------------------------------------------------//
//------------------Push Swap Main-------------------//
//---------------------------------------------------//
// Main function for the push_swap program,
// processes input and starts operations
int		main(int argc, char **argv);
//---------------------------------------------------//
//--------------------STACK OPERATIONS---------------//
//---------------------------------------------------//
// Creates and returns a new empty stack
t_stack	*create_stack(void);
// Creates and returns a new node with a given value
t_node	*create_node(int value);
// Pushes a value onto the stack
void	put_value_to_stack(t_stack *stack, int value);
// Frees the entire stack (and its nodes)
void	free_stack(t_stack **stack);
// Frees all nodes from the stack but not the stack itself
void	free_nodes_from_stack(t_stack *stack);
//--------------------------------------------------//
//--------------------INPUT HANDLING----------------//
//--------------------------------------------------//
// Parses the input arguments and fills stacks a and b
void	parse_input(t_stack *a, t_stack *b, char **argv, int argc);
// Handles the args parses the input and fills the stacks
void	handle_args(t_stack *a, t_stack *b, char **argv, int argc);
// Handles args and splits them if they are presented as a string
void	handle_string_args(t_stack *a, t_stack *b, char *arg);
// Frees the memory allocated for the split arguments
void	free_split(char **split_args);
//---------------------------------------------------//
//--------------------INPUT VALIDATION--------------//
//---------------------------------------------------//
// Checks if the stack is sorted
int		is_sorted(t_stack *stack);
// Checks if there are any duplicates in stack a
int		has_duplicates(t_stack *a);
// Checks if elements are in integer range
int		is_in_range(const char *arg);
// Validates if the argument is a valid integer
int		is_valid_int(const char *arg);
//---------------------------------------------------//
//--------------------STACK OPERATIONS----------------//
//---------------------------------------------------//
// Pushes an element from one stack to another
void	ft_push(t_stack *from, t_stack *to);
// Rotates the stack (moves the top element to the bottom)
void	ft_rotate(t_stack *stack);
// Reverses the rotation of the stack (moves the bottom element to the top)
void	ft_rev_rotate(t_stack *stack);
// Swaps the top two elements of the stack
void	ft_swap(t_stack *stack);
//--------------------- Operations ----------------//
// Push element from stack b to stack a
void	pa(t_stack *a, t_stack *b);
// Push element from stack a to stack b
void	pb(t_stack *a, t_stack *b);
// Reverse rotate stack a
void	rra(t_stack *a);
// Reverse rotate stack b
void	rrb(t_stack *b);
// Reverse rotate both stacks
void	rrr(t_stack *a, t_stack *b);
// Rotate stack a
void	ra(t_stack *a);
// Rotate stack b
void	rb(t_stack *b);
// Rotate both stacks
void	rr(t_stack *a, t_stack *b);
// Swap top two elements of stack a
void	sa(t_stack *a);
// Swap top two elements of stack b
void	sb(t_stack *b);
// Swap top two elements of both stacks
void	ss(t_stack *a, t_stack *b);
//---------------------------------------------------//
//-------------------UTILITY FUNCTIONS--------------//
//---------------------------------------------------//
// Helper function to convert string in to a long
long	handle_sign(const char **arg);
long	ft_atol(const char *arg);
// Assign target positions for elements in stack a based on their sorted order
void	assign_targets(t_stack *a);
// Prints error message and frees both stacks
void	ft_error(t_stack *a, t_stack *b);
// Finds and returns the maximum target in the stack
int		find_max_target(t_stack *stack);
// Finds and returns the maximum value in the stack
int		find_max(t_stack *stack);
// Finds and returns the minimum value in the stack
int		find_min(t_stack *stack);
// Checks if the stack is empty
int		ft_isempty(t_stack *stack);
// Prints stacks
void	print_stack_contents(t_node *stack_top, char *stack_name);
void	print_stacks(t_stack *a, t_stack *b);
void	print_stack(t_stack *stack);
//---------------------------------------------------//
//-----------------SORTING FUNCTIONS-----------------//
//---------------------------------------------------//
// Main sorting function, handles the entire sorting process
void	push_swap(t_stack *a, t_stack *b);
// Sorts small stack (with 3 or fewer elements)
void	sort_small(t_stack *a);
void	sort_two(t_stack *a);
void	sort_three(t_stack *a);
// Sorts stack using insertion sort algorithm
void	sort_medium(t_stack *a, t_stack *b);
// static void	push_smallest_a_to_b(t_stack *a, t_stack *b);
// static void	push_all_back_to_a(t_stack *a, t_stack *b);
// Sorts stack using merge sort algorithm (planned for future)
void	sort_large(t_stack *a, t_stack *b);
void	push_chunks_to_b(t_stack *a, t_stack *b, int chunk_start,
			int chunk_size);
void	rotate_downwards(t_stack *a, t_stack *b, int *target_position);
void	rotate_upwards(t_stack *a, t_stack *b, int *target_position);
void	rotate_and_push(t_stack *a, t_stack *b, int target_position);
int		ft_chunk_size(int stack_size);
int		find_closest_target(t_stack *a, int chunk_start, int chunk_size);
int		is_target_closer(int index, int size, int *min_distance);
int		distance_to_target(t_stack *stack, int target);
void	merge_chunks_back(t_stack *a, t_stack *b);
t_node	*get_last_node(t_stack *stack);

#endif
