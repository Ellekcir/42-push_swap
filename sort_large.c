#include "push_swap.h"

int	get_max_value(t_stack *stack)
{
	t_node	*temp;
	int		max_value;

	temp = stack->top;
	max_value = temp->value;
	while (temp != NULL)
	{
		if (temp->value > max_value)
			max_value = temp->value;
		temp = temp->next;
	}
	return (max_value);
}

int	stack_size(t_stack *stack)
{
	t_node	*temp;
	int		size;

	temp = stack->top;
	size = 0;
	while (temp != NULL)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}

void	process_digit(t_stack *a, t_stack *b, int digit_place)
{
	int	stack_size_value;
	int	i;
	int	current_value;
	int	digit;

	stack_size_value = stack_size(a);
	i = 0;
	while (i < stack_size_value)
	{
		current_value = a->top->value;
		digit = (current_value / digit_place) % 10;
		if (digit < 5)
			push(a, b);
		else
			rotate(a);
		i++;
	}
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	max_value;
	int	digit_place;

	max_value = get_max_value(a);
	digit_place = 1;
	while (max_value / digit_place > 0)
	{
		process_digit(a, b, digit_place);
		while (!is_empty(b))
			push(b, a);
		digit_place *= 10;
	}
}

void	sort_large(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return ;
	radix_sort(a, b);
}
