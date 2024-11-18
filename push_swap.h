#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "./libft/libft.h"
// Standard library for memory allocation/ and exit funciton
#include <stdlib.h>
// Standard library to use write
#include <unistd.h>
#include <limits.h>
#include <stdbool.h>

//---------------------------------------------------//
//---------------------LINKED LISTS------------------//
//---------------------------------------------------//
// Defines a node
// Value, index, target index and next element in stack
typedef struct s_node
{
	int value;
	int target; // target - index of the target position element will need to be when sorted
	struct s_node *next;
} t_node;

// Defines a stack
// Top element of stack, max value in stack, size of stack
typedef struct s_stack
{
	t_node *top;
	int size;
} t_stack;

//---------------------------------------------------//
//--------------Push Swap Main-----------------------//
//---------------------------------------------------//
// Initiates the push swap program
int main(int argc, char **argv);
//---------------------------------------------------//
//--------------Stacks-------------------------------//
//---------------------------------------------------//
t_stack	*create_stack(void);
void	put_value_to_stack(t_stack *stack, int value);
t_node	*create_node(int value);
void	free_stack(t_stack	*stack);
int	free_nodes_from_stack(t_stack *stack);
//---------------------------------------------------//
//--------------Input Handling-----------------------//
//---------------------------------------------------//
void parse_input(t_stack *a, t_stack *b, char **argv, int argc);
//static void	ft_handle_args(t_stack *a, char **argv, int argc);
//static void	ft_handle_string_args(t_stack *a, char *arg);
//---------------------------------------------------//
//--------------Input Validation---------------------//
//---------------------------------------------------//
int ft_issorted(t_stack *stack);
int	ft_isdup(t_stack *a);
int	ft_isint(const char *arg);
//---------------------------------------------------//
//--------------Stack Operations---------------------//
//---------------------------------------------------//
void	ft_push(t_stack *from, t_stack *to);
void	ft_rev_rotate(t_stack *stack);
void	ft_rotate(t_stack *stack);
void	ft_swap(t_stack *stack);

void	ft_pa(t_stack *a, t_stack *b);
void	ft_pb(t_stack *a, t_stack *b);
void	ft_rra(t_stack *a);
void	ft_rrb(t_stack *b);
void	ft_rrr(t_stack *a, t_stack *b);
void	ft_ra(t_stack *a);
void	ft_rb(t_stack *b);
void	ft_rr(t_stack *a, t_stack *b);
void	ft_sa(t_stack *a);
void	ft_sb(t_stack *b);
void	ft_ss(t_stack *a, t_stack *b);

//---------------------------------------------------//
//---------------- Utils ----------------------------//
//---------------------------------------------------//
void	ft_error(t_stack *a, t_stack *b);
int	find_max(t_stack *stack);
int	find_min(t_stack *stack)
;
int ft_isempty(t_stack *stack);
void	print_stacks(t_stack *a, t_stack *b);
void print_stack(t_stack *stack);

//---------------------------------------------------//
// //---------------Stack Functions---------------------//
// //---------------------------------------------------//
void push_swap(t_stack *a, t_stack *b);
void	sort_small(t_stack *a);

void sort_medium(t_stack *a, t_stack *b);
void	sort_large(t_stack *a, t_stack *b);


//void merge_sort(t_stack *a, t_stack *b);
//void ft_quick_sort_array(int *arr, int left, int right);
//---------------------------------------------------//
//--------------Push Swap Main-----------------------//
//---------------------------------------------------//
// Initiates the creation of the the stacks
// static void	ft_init_stacks(t_stack **a, t_stack **b);
// Splits, validates and handles string arguments, populates stack
// static void	ft_handle_string_args(t_stack *a, t_stack *b, char *arg);
// Handles arguments, validates input, and populates stack
// static void	ft_handle_args(t_stack *a, char **argv, int argc);
// Creates stacks, handles arguments, sorts if not sorted
// int	main(int argc, char **argv);

// //---------------------------------------------------//
// //---------------Input Validation--------------------//
// //---------------------------------------------------//
// // Checks stack is sorted in ascending order
// int ft_issorted(t_stack **stack);
// // Checks if argument is an integer and checks boundaries
// int ft_isint(const char *arg);
// // Checks if argument is has a duplicate
// int ft_isdup(t_stack **a);

// //---------------------------------------------------//
// //---------------Stack Functions---------------------//
// //---------------------------------------------------//
// // Function to create a new node
// t_node *create_node(int value);
// // Function to create a new stack
// t_stack *create_stack(void);
// // Example of pushing a value onto the stack
// void put_value_to_stack(t_stack **stack, int value);
// // Example of popping a value from the stack
// int free_nodes_from_stack(t_stack **stack);
// // Free the stack and its nodes
// void free_stack(t_stack **stack);

// //---------------------------------------------------//
// //--------------Stack Operations---------------------//
// //---------------------------------------------------//
// // Pushes the top element from one stack to another
// void ft_push(t_stack **from, t_stack **to);
// // Swaps top two elements of the stack
// void ft_swap(t_stack **stack);
// // Rotates stack by moving the top element to the bottom
// void ft_rotate(t_stack **stack);
// // Reverses the rate by moving the bottom element to the top
// void ft_reverse_rotate(t_stack **stack);

// //---------------------------------------------------//
// //---------------Stack Instructins-------------------//
// //---------------------------------------------------//
// // Pushes top element of stack B to top of Stack A
// void ft_pa(t_stack **a, t_stack **b);
// // Pushes top element of Stack A to top of Stack B
// void ft_pb(t_stack **a, t_stack **b);
// // Swap the first two elements at the top of Stack A
// void ft_sa(t_stack **a);
// // Swap the first two elements at the top of Stack B
// void ft_sb(t_stack **b);
// // Swap the first two elements at the top of Stack A
// void ft_ss(t_stack **a, t_stack **b);
// // Moves the top of Stack A to the bottom.
// void ft_ra(t_stack **a);
// // Moves the top of Stack B to the bottom.
// void ft_rb(t_stack **b);
// // Simultaneously rotates both Stacks A and B
// void ft_rr(t_stack **a, t_stack **b);
// // Moves the bottom of Stack A to the top.
// void ft_rra(t_stack **a);
// // Moves the bottom of Stack B to the top.
// void ft_rrb(t_stack **b);
// // Simultaneously reverse rotates both Stacks A and B
// void ft_rrr(t_stack **a, t_stack **b);


// //---------------------------------------------------//
// //---------------Sorting three or less---------------//
// //---------------------------------------------------//
// // Sorts two arguments
// void	sort_two(t_stack **a);
// // Sorts three arguments
// void	sort_three(t_stack **a);
// // Sorts five or less arguments
// void	sort_three_or_less(t_stack **a);


// //---------------------------------------------------//
// //---------------Sorting four or more ---------------//
// //---------------------------------------------------//

// void push_all_but_three_to_b(t_stack **a, t_stack **b);

// void sort_four_or_more(t_stack **a, t_stack **b);

// //---------------------------------------------------//
// //---------------- Sort - Actions -------------------//
// //---------------------------------------------------//

// void rotate_to_target(t_stack **a, t_stack **b, int target_value, int direction);

// int do_moves_rr(t_stack **a, t_stack **b, int target_value);

// int do_moves_rrr(t_stack **a, t_stack **b, int n);

// int do_moves_rra_rb(t_stack **a, t_stack **b, int n);

// //---------------------------------------------------//
// //-------------- Sort - Count -----------------------//
// //---------------------------------------------------//

// int calculate_moves_rr(t_stack **a, t_stack **b, int target_value);

// int calculate_moves_rrr(t_stack **a, t_stack **b, int target_value);

// int calculate_moves_rra_rb(t_stack **a, t_stack **b, int target_value);

// int	calculate_minimum_move(t_stack **a, t_stack **b);

// //---------------------------------------------------//
// //---------------- Utils - Stack --------------------//
// //---------------------------------------------------//
// // Return the bottom node of a stack
// int find_min_index(t_stack *a);
// int	find_min(t_stack *stack);
// int	find_max(t_stack *stack);
// int	ft_isempty(t_stack *stack);
// t_node	*ft_bottom_node(t_stack *stack);


// //---------------------------------------------------//
// //---------------- Utils - Helpers ------------------//
// //---------------------------------------------------//
// // Error message end exit
// void	ft_error(void);
// // void	ft_error(char *s);
// // Prints stack 
// void	print_stacks(t_stack **a, t_stack **b);
// // Compares strings
// int	ft_strcmp(const char *s1, const char *s2);

// //---------------------------------------------------//
// //-----------------Utils - Sort ---------------------//
// //---------------------------------------------------//
// //int find_target_position_to_insert_to_b(t_stack **b, int a_top_value);
// //int find_place_in_a(t_stack **a, int n);
// //This will return the position (index) of where the next node needs to be placed into B
// int	find_target_index(t_stack *stack, int target_value);
// // Function to transfer the sorted elements back from Stack B to Stack A
// void transfer_sorted_values_back_to_a(t_stack **a, t_stack **b);
// // Retrieve the index of target_value in stack;  returns -1 if not found
// // used in function - find_min_and_rotate_min_to_top(t_stack *a)
// int get_node_index(t_stack *stack, int target_value);
// // Function to rotate elements in Stack A to bring the minimum element to the top
// void find_min_and_rotate_min_to_top(t_stack **a);



#endif