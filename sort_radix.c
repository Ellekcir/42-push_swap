#include "push_swap.h"


int	find_max(t_stack *stack)
{
	t_node	*temp;
	int		max_value;

	temp = stack->top;
	max_value = temp->index;
	while (temp != NULL)
	{
		if (temp->index > max_value)
			max_value = temp->index;
		temp = temp->next;
	}
	return (max_value);
}

void	index_value(t_stack *stack)
{
	t_node	*current;
	t_node	*compare;
	int		index;
	int		stack_size;

	stack_size = 0;
	ft_printf("\n----- INDEXING VALUES -----\n");
	current = stack->top;
	while (current != NULL)
	{
		stack_size++;
		current = current->next;
	}
	current = stack->top;
	while (current != NULL)
	{
		index = 0;
		compare = stack->top;
		while (compare != NULL)
		{
			if (current->value > compare->value)
				index++;
			compare = compare->next;
		}
		ft_printf("Value %d gets index %d\n", current->value, index);
		current->target_index = index;
		current = current->next;
	}
	ft_printf("----- INDEXING COMPLETE -----\n");
	stack->max_value = stack_size - 1;
}


static void	process_bits(t_stack *a, t_stack *b, int i, int size)
{
	int	j;
	int	current;

	j = 0;
	while (j < size)
	{
		current = a->top->target_index;
		ft_printf("Current number: %d, ", current);
		if ((current >> i) & 1)
		{
			ft_ra(a);
			ft_printf("Rotating A\n");
		}
		else
		{
			ft_pb(a, b);
			ft_printf("Pushing to B\n");
		}
		ft_printf("Stack A after operation:\n");
		print_stack(a);
		ft_printf("Stack B after operation:\n");
		print_stack(b);
		j++;
	}
}

void	sort_radix(t_stack *a, t_stack *b)
{
	int	max_bits;
	int	i;
	int	size;

	ft_printf("\n----- ENTERING SORT RADIX -----\n");
	ft_printf("\nInitial Stack A:\n");
	print_stack(a);
	ft_printf("\nInitial Stack B:\n");
	print_stack(b);
	size = a->size;
	index_value(a);
	max_bits = 0;
	while ((a->max_value >> max_bits) != 0)
		++max_bits; // ?max_bits++;
	ft_printf("\nMax value: %d, Number of bits: %d\n", a->max_value, max_bits);
	ft_printf("\nAfter indexing Stack A:\n");
	print_stack(a);
	i = 0;
	while (i < max_bits)
	{
		ft_printf("\n----- Processing bit %d -----\n", i);
		process_bits(a, b, i, size);
		ft_printf("\n----- Pushing all elements back to A -----\n");
		while (!is_empty(b))
		{
			ft_pa(a, b);
			ft_printf("Pushing from B to A\n");
			ft_printf("Stack A:\n");
			print_stack(a);
			ft_printf("Stack B:\n");
			print_stack(b);
		}
		i++;
	}
	ft_printf("\n----- RADIX SORT COMPLETED -----\n");
	ft_printf("\nFinal Stack A:\n");
	print_stack(a);
	ft_printf("\nFinal Stack B:\n");
	print_stack(b);
}