#include "push_swap.h"

int ft_chunk_size(int stack_size)
{
	int chunk_size;

	if (stack_size <= 6)
		return (stack_size);
	chunk_size = stack_size / 5;
	return (chunk_size);
}

void push_chunks_to_b(t_stack *a, t_stack *b, int chunk_start, int chunk_size)
{
	int pushed_count = 0;

	while (pushed_count < chunk_size)
	{

		if (a->top->target >= chunk_start && a->top->target < (chunk_start + chunk_size))
		{
			ft_pb(a, b);
			pushed_count++;
		}
		else
			ft_ra(a); 
		// print_stack(a);
		// print_stack(b);
	}
}

int distance_to_target(t_stack *stack, int target)
{
	t_node *current = stack->top;
	int position = 0;
	while (current != NULL)
	{
		if (current->target == target)
			break;
		current = current->next;
		position++;
	}
	if (current == NULL)
		return -1;

	if (position <= stack->size / 2)
		return position;
	return stack->size - position;
}

void merge_chunks_back(t_stack *a, t_stack *b)
{
	int target;

	while (b->top != NULL)
	{
		target = b->top->target;
		int distance;
		while (a->top->target != target)
		{
			distance = distance_to_target(a, target);

			if (distance <= a->size / 2)
			{
				ft_ra(a);
			}
			else
			{
				ft_rra(a);
			}
		}
		ft_pa(b, a);
	}
}

// Main merge sort function that processes chunks based on target index
void sort_large(t_stack *a, t_stack *b)
{
	int chunk_size;
	int chunk_start;
	int stack_total = a->size;

	chunk_start = 0;
	chunk_size = ft_chunk_size(a->size);
	// ft_printf("CHUNK SIZE:%i \n", chunk_size);
	//  Determine chunk size eg: 100/5 =20
	if (a->size <= 6)
	{
		sort_medium(a, b);
		return;
	}
	while (chunk_start < (stack_total / 5))
	{
		push_chunks_to_b(a, b, chunk_start, chunk_size);
		chunk_start += chunk_size;
	}
	if (a->size != 0)
	{
		if (a->size <= 3)
			sort_small(a);
		else
			sort_medium(a, b);
	}
	merge_chunks_back(a, b);
}