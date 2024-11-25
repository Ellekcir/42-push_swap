#include "push_swap.h"

int find_max_target(t_stack *stack)
{
	t_node *current;
	int max_target;

	if (stack->top == NULL)
		return (-1); // Error: Empty stack

	current = stack->top;
	max_target = current->target;
	while (current)
	{
		if (current->target > max_target)
		{
			max_target = current->target;
			// ft_printf("max_target in B: %d\n", max_target);
		}
		current = current->next;
	}
	return (max_target);
}

int ft_chunk_size(int stack_size)
{
	if (stack_size <= 6)
		return (stack_size);
	if (stack_size <= 100)
		return (stack_size / 6);
	return (stack_size / 10);
}

void push_chunks_to_b(t_stack *a, t_stack *b, int chunk_start, int chunk_size)
{
	int pushed_count;
	t_node *current;
	int min_distance;
	int target_position;
	int i;

	pushed_count = 0;
	while (pushed_count < chunk_size && a->size > 0)
	{
		current = a->top;
		min_distance = a->size;
		target_position = -1;
		i = 0;

		// Find the closest element in the current chunk
		while (current != NULL)
		{
			if (current->target >= chunk_start && current->target < chunk_start + chunk_size)
			{
				int distance;

				distance = i;
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

		// Bring the closest target to the top and push it
		if (target_position <= a->size / 2)
		{
			while (target_position > 0)
			{
				ft_ra(a);
				target_position--;
			}
		}
		else
		{
			while (target_position < a->size)
			{
				ft_rra(a);
				target_position++;
			}
		}
		ft_pb(a, b);
		pushed_count++;
	}
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
				ft_rb(b);
				distance--;
			}
			else
			{
				ft_rrb(b);
				distance++;
			}
		}
		ft_pa(a, b);
	}
}

// Main merge sort function that processes chunks based on target index
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
	assign_targets(a);
	while (chunk_start < stack_total)
	{
		push_chunks_to_b(a, b, chunk_start, chunk_size);
		chunk_start += chunk_size;
	}
	if (a->size > 0)
		sort_medium(a, b);
	// ft_printf("\tStack A:\n\n");
	// print_stack(a);
	// ft_printf("\tStack B:\n\n");
	// print_stack(b);
	// Merge sorted chunks back to stack A
	merge_chunks_back(a, b);
}