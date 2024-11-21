#include "push_swap.h"

static void print_stackz(t_stack *stack)
{
    t_node *current = stack->top;
    while (current != NULL)
    {
        ft_printf("Value: %d, Target: %d\n", current->value, current->target);
        current = current->next;
    }
}

/*
Split Stack A into Chunks:
Divide stack A into smaller chunks, which can be handled individually. The size of the chunks depends on the total number of elements.
*/
// The chunk size will be determined by the stack size, it shall be sorted in chucks of 20% of the stack size at a time or if the stack is below 20 elements, it will be sorted in just one chunk.
int ft_chunk_size(int stack_size)
{
	int chunk_size;

	if (stack_size <= 10)
		return (stack_size);
	chunk_size = stack_size / 5;
//	if (stack_size % 5 != 0)
//		chunk_size++;
	return (chunk_size);
	// if (stack->size <= 100)
	// return (stack->size / 5);
	// return (stack->size / 10);
}

/*
Push Chunks to Stack B:
Move each chunk from stack A to stack B in a way that maintains partial sorting in B. For example, smaller elements should go to the top of B.
*/

// Function to push a chunk of elements from stack A to stack B based on target index
void push_chunk_to_b(t_stack *a, t_stack *b, int chunk_start, int chunk_size)
{
	int pushed_count = 0;

	while (pushed_count < chunk_size) // Loop while pushing elements of the current chunk
	{
		//print_stack(a);
		//print_stack(b);
		if (a->top->target >= chunk_start && a->top->target < (chunk_start + chunk_size))
		{
			ft_pb(a, b); // Push to Stack B
			pushed_count++;
		}
		else
		{
			ft_ra(a); // Rotate Stack A
 // Increment only when a rotation happens
		}
		print_stack(a);
		print_stack(b);
	}
}


static int distance_to_target(t_stack *stack, int target)
{
	t_node *current = stack->top;
	int position = 0;

	// Traverse stack to find the target
	while (current != NULL)
	{
		if (current->target == target)
			break;
		current = current->next;
		position++;
	}

	// Handle case where the target is not found (just a safeguard)
	if (current == NULL)
		return -1;

	// Calculate forward vs. reverse rotation distance
	if (position <= stack->size / 2)
		return position;		   // Forward rotation
	return stack->size - position; // Reverse rotation
}

/*
Sort and Merge Back:
Merge chunks from B back into A while keeping A sorted. Use efficient rotation and push operations to minimize the number of instructions.
*/
void merge_chunks_back(t_stack *a, t_stack *b)
{
    while (b->top != NULL)
    {
        int target = b->top->target;

        // Debug: Print the current state of Stack A and Stack B
        ft_printf("\n--- DEBUG: Starting new iteration ---\n");
        ft_printf("Current Stack A (size: %d):\n", a->size);
        print_stackz(a); // Replace with your stack printing function
        ft_printf("Current Stack B (size: %d):\n", b->size);
        print_stackz(b);
        ft_printf("Target to bring to top of A: %d\n", target);

        // Rotate Stack A until the target is at the top
        while (a->top->target != target)
        {
            // Debug: Print the distance to target and current top
            int distance = distance_to_target(a, target);
            ft_printf("Distance to target %d in Stack A: %d\n", target, distance);
            ft_printf("Current top of Stack A: %d\n", a->top->target);

            // Find the shortest path
            if (distance <= a->size / 2)
            {
                ft_printf("Rotating forward (ft_ra): Current top: %d\n", a->top->target);
                ft_ra(a); // Rotate forward
            }
            else
            {
                ft_printf("Rotating reverse (ft_rra): Current top: %d\n", a->top->target);
                ft_rra(a); // Rotate reverse
            }

            // Debug: Print the stack state after each rotation
            ft_printf("Stack A after rotation:\n");
            print_stackz(a);
        }

        // Push the target from Stack B to Stack A
        ft_printf("Pushing target %d from Stack B to Stack A (ft_pa)\n", b->top->target);
        ft_pa(b, a);

        // Debug: Print the stack state after the push
        ft_printf("Stack A after pushing:\n");
        print_stackz(a);
        ft_printf("Stack B after pushing:\n");
        print_stackz(b);
    }
}

// Main merge sort function that processes chunks based on target index
void sort_merge(t_stack *a, t_stack *b)
{
	int chunk_size;
	int chunk_start;
	int stack_total = a->size;

	chunk_start = 0;
	chunk_size = ft_chunk_size(a->size); 
	ft_printf("CHUNK SIZE:%i \n", chunk_size);
	// Determine chunk size eg: 100/5 =20
	assign_target_position(a);
	if (a->size <= 10)
	{
		sort_insertion(a, b);
		return ;
	}
	while (chunk_start < stack_total)
	{
		push_chunk_to_b(a, b, chunk_start, chunk_size);
		chunk_start += chunk_size;
	}

	merge_chunks_back(a, b);
}
