#include "push_swap.h"

// 2.
// This helper function determines the chunk size
// it will take the stacks size and return a chunk
// size depending on the size of the stack
int ft_chunk_size(int stack_size)
{
	if (stack_size <= 10)
		return (stack_size);
	if (stack_size <= 100)
		return (stack_size / 7);
	return (stack_size / 15);
}

// 3.
// Pushes chunks of elements from stack a to b
// While the number of pushed elements is less than the chunk size
// it will find the closest target by utilising the values 'target(index)'
// in stack a.
void push_chunks_to_b(t_stack *a, t_stack *b, int chunk_start, int chunk_size)
{
	int pushed_count;
	int target_position;

	pushed_count = 0;
	while (pushed_count < chunk_size && a->size > 0)
	{	
		target_position = a->top->target;
		target_position = find_closest_target(a, chunk_start, chunk_size);
		if (target_position != -1)
		{
			rotate_and_push(a, b, target_position);
			pushed_count++;
		}
	}
}


int find_max_target(t_stack *stack)
{
	t_node *current;
	int max_target;

	if (stack->top == NULL)
		return (-1);
	current = stack->top;
	max_target = current->target;
	while (current)
	{
		if (current->target > max_target)
			max_target = current->target;
		current = current->next;
	}
	return (max_target);
}

// 4.
int find_closest_target(t_stack *a, int chunk_start, int chunk_size)
{
	t_node	*current;
	int		min_distance;
	int		target_position;
	int		i;

	current = a->top;
	min_distance = a->size;
	target_position = -1;
	i = 0;
	while (current != NULL)
	{
		if (current->target >= chunk_start && current->target < chunk_start + chunk_size)
		{
			int distance = i;
			if (i > a->size / 2)
				distance = a->size - i;
			if (distance < min_distance)
			{
				min_distance = distance;
				target_position = i;
			}
		}
		current = current->next;
		i++;
	}
	return (target_position);
}

t_node *get_last_node(t_stack *stack)
{
    t_node *current;

    if (!stack || !stack->top)
        return (NULL); // Return NULL if the stack is empty
    current = stack->top;
    while (current->next)
        current = current->next; // Traverse to the last node
    return (current);
}

// 5.
// 
void rotate_and_push(t_stack *a, t_stack *b, int target_position)
{
	t_node *b_last_node;

	b_last_node = get_last_node(b);
	if (target_position <= a->size / 2)
	{
		while (target_position > 0)
		{
			if (b->size > 2 && b->top->target < b->top->next->target)
				rr(a, b);
			else
				ra(a);
			target_position--;
		}
	}
	else
	{
		while (target_position < a->size )
		{
			if (b->size > 2 && b->top->target < b_last_node->target)
				rrr(a, b);
			else
				rra(a);
			target_position++;
		}
	}
	pb(a, b);
}


int distance_to_target(t_stack *stack, int target)
{
	t_node *current;
	int position;

	if (stack->top == NULL)
		return (-1);
	current = stack->top;
	position = 0;
	while (current != NULL)
	{
		if (current->target == target)
			break;
		current = current->next;
		position++;
	}
	if (current == NULL)
		return (-1);
	if (position <= stack->size / 2)
		return (position);
	return (position - stack->size);
}

void merge_chunks_back(t_stack *a, t_stack *b)
{
	int max_target;
	int distance;

	while (b->size > 0)
	{
		max_target = find_max_target(b);
		distance = distance_to_target(b, max_target);
		while (b->top->target != max_target)
		{
			if (distance > 0)
			{
				rb(b);
				distance--;
			}
			else
			{
				rrb(b);
				distance++;
			}
		}
		pa(a, b);
	}
}

// 1.
// Main merge sort function that processes chunks based on target index
// If stack a is less than 10 elements it will do insertion sort
// if its got more it will assign each value with a target index
// push chunk by chunk to the b stack using the target index value 
// this is so it will now be sorting in consecutaive order using only 
// positive values
void sort_large(t_stack *a, t_stack *b)
{
	int chunk_size;
	int chunk_start;
	int stack_total;

	stack_total = a->size;
	chunk_size = ft_chunk_size(a->size);
	chunk_start = 0;
	if (stack_total <= 10)
	{
		sort_medium(a, b);
		return ;
	}
	else
	{
		assign_targets(a);
		while (chunk_start < stack_total)
		{
			push_chunks_to_b(a, b, chunk_start, chunk_size);
			chunk_start += chunk_size;
		}
		if (a->size > 0)
			sort_medium(a, b);
	}
	merge_chunks_back(a, b);
}