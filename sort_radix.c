#include "push_swap.h"

// Assigns a new index to the element based off
// its value and where it should be within the
// completed sorted stack
// Assigns the node's "Target" position using
// its new index by comparing each value and 
// increasing the index count for every element 
// that is less than the current element
static void assign_target_index(t_stack *stack)
{
	t_node	*current;
	t_node	*compare_next_node;
	int		index;

	current = stack->top;
	while (current != NULL)
	{
		index = 0;
		compare_next_node = stack->top;
		while (compare_next_node != NULL)
		{
			if (current->value > compare_next_node->value)
				index++;
			compare_next_node = compare_next_node->next;
		}
		current->target = index;
		current = current->next;
	}
}

static void process_bit(t_stack *a, t_stack *b, int bit, int size)
{
	int	count;

	count = 0;
	while (count < size)
	{
		if (((a->top->target >> bit) & 1) == 0)
			ft_pb(a, b);
		else
			ft_ra(a);
		count++;
	}
}

// This will start a radix sort by finding the maximum bits needed for the maximum target index which will be assigned to every node based it values.
void sort_large(t_stack *a, t_stack *b)
{
	int	max_bits;
	int	bit;
	int	stack_size;
	t_node *current;

	assign_target_index(a);
	current = a->top;
	max_bits = 0;
	while (current != NULL)
	{
		if (current->target > (1 << max_bits) - 1)
			max_bits++;
		current = current->next;
	}

	stack_size = a->size;
	bit = 0;
	while (bit < max_bits)
	{
		process_bit(a, b, bit, stack_size);
		while (b->top != NULL)
			ft_pa(a, b);
		bit++;
	}
}
