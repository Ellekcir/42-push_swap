#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

// Includes the necessary libraries
#include "./libft/libft.h"  // For standard libft functions
#include <stdlib.h>         // For memory allocation and exit functions
#include <unistd.h>         // For write functionality
#include <limits.h>         // For INT_MAX and INT_MIN
#include <stdbool.h>        // For boolean values

//---------------------------------------------------//
//---------------------LINKED LISTS------------------//
//---------------------------------------------------//

// Node structure representing an element in the stack
// It holds the value, target position (when sorted), and a pointer to the next node
typedef struct s_node
{
    int value;         // Value of the node
    int target;        // Target index where the node should go after sorting
    struct s_node *next; // Pointer to the next node in the stack
} t_node;

// Stack structure representing the entire stack
// It holds the top node, the size of the stack, and a reference to the stack's head
typedef struct s_stack
{
    t_node *top;   // Top element of the stack (most recent item pushed)
    int size;      // Size of the stack
} t_stack;

//---------------------------------------------------//
//------------------Push Swap Main-------------------//
//---------------------------------------------------//

// Main function for the push_swap program, processes input and starts operations
int main(int argc, char **argv);

//---------------------------------------------------//
//--------------------STACK OPERATIONS----------------//
//---------------------------------------------------//

// Creates and returns a new empty stack
t_stack *create_stack(void);

// Pushes a value onto the stack
void put_value_to_stack(t_stack *stack, int value);

// Creates and returns a new node with a given value
t_node *create_node(int value);

// Frees the entire stack (and its nodes)
void free_stack(t_stack **stack);

// Frees all nodes from the stack but not the stack itself
void free_nodes_from_stack(t_stack *stack);

//---------------------------------------------------//
//--------------------INPUT HANDLING----------------//
//---------------------------------------------------//

// Parses the input arguments and fills stacks a and b
void parse_input(t_stack *a, t_stack *b, char **argv, int argc);

//---------------------------------------------------//
//--------------------INPUT VALIDATION--------------//
//---------------------------------------------------//

// Checks if the stack is sorted
int is_sorted(t_stack *stack);

// Checks if there are any duplicates in stack a
int has_duplicates(t_stack *a);

// Validates if the argument is a valid integer
int	is_valid_int(const char *arg);

//---------------------------------------------------//
//--------------------STACK OPERATIONS----------------//
//---------------------------------------------------//

// Pushes an element from one stack to another
void ft_push(t_stack *from, t_stack *to);

// Rotates the stack (moves the top element to the bottom)
void ft_rotate(t_stack *stack);

// Reverses the rotation of the stack (moves the bottom element to the top)
void ft_rev_rotate(t_stack *stack);

// Swaps the top two elements of the stack
void ft_swap(t_stack *stack);

//--------------------- Operations ----------------//
void pa(t_stack *a, t_stack *b);   // Push element from stack b to stack a
void pb(t_stack *a, t_stack *b);   // Push element from stack a to stack b
void rra(t_stack *a);              // Reverse rotate stack a
void rrb(t_stack *b);              // Reverse rotate stack b
void rrr(t_stack *a, t_stack *b);  // Reverse rotate both stacks
void ra(t_stack *a);               // Rotate stack a
void rb(t_stack *b);               // Rotate stack b
void rr(t_stack *a, t_stack *b);   // Rotate both stacks
void sa(t_stack *a);               // Swap top two elements of stack a
void sb(t_stack *b);               // Swap top two elements of stack b
void ss(t_stack *a, t_stack *b);   // Swap top two elements of both stacks

//---------------------------------------------------//
//-------------------UTILITY FUNCTIONS--------------//
//---------------------------------------------------//

// Assign target positions for elements in stack a based on their sorted order
void assign_targets(t_stack *a);

// Prints error message and frees both stacks
void ft_error(t_stack *a, t_stack *b);

// Finds and returns the maximum value in the stack
int find_max(t_stack *stack);

// Finds and returns the minimum value in the stack
int find_min(t_stack *stack);

// Checks if the stack is empty
int ft_isempty(t_stack *stack);

// Prints the entire state of both stacks a and b
void print_stacks(t_stack *a, t_stack *b);

// Prints the state of a single stack
void print_stack(t_stack *stack);

//---------------------------------------------------//
//-----------------SORTING FUNCTIONS----------------//
//---------------------------------------------------//

// Main sorting function, handles the entire sorting process
void push_swap(t_stack *a, t_stack *b);

// Sorts small stack (with 3 or fewer elements)
void sort_small(t_stack *a);

// Sorts stack using insertion sort algorithm
void sort_medium(t_stack *a, t_stack *b);

// Sorts stack using merge sort algorithm (planned for future)
void sort_large(t_stack *a, t_stack *b);
void rotate_b_to_target(t_stack *b, int distance);
void merge_chunks_back(t_stack *a, t_stack *b);
void rotate_to_top(t_stack *stack, int distance, char stack_name);
int calculate_distance(t_stack *stack, int target_position);
// int find_best_target_position(t_stack *a, int chunk_start, int chunk_size);
// int calculate_distance(int stack_size, int index);
int ft_chunk_size(int stack_size);
int find_max_target(t_stack *stack);
int find_closest_target(t_stack *a, int chunk_start, int chunk_size);
void rotate_and_push(t_stack *a, t_stack *b, int target_position);
int distance_to_target(t_stack *stack, int target);
// int find_min_value(t_node *node);
void dual_rotate(t_stack *a, t_stack *b, int distance_a, int distance_b);
int find_closest_in_chunk(t_stack *a, int chunk_start, int chunk_size)
;
// void rotate_to_top(t_stack *stack, int distance, char stack_name);

// void push_chunks_to_b(t_stack *a, t_stack *b, int chunk_start, int chunk_size);
// int distance_to_target(t_stack *stack, int target);
// int find_max_value(t_node *node);

// int find_max_target(t_stack *stack);
// int find_closest_in_chunk(t_stack *a, int chunk_start, int chunk_size);
// Determines the size of a chunk for chunk-based sorting
int ft_chunk_size(int stack_size);
void free_split(char **split_args);

long	ft_atol(const char *arg);
int	is_in_range(const char *arg);


#endif
