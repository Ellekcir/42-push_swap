#include "push_swap.h"

void assign_targets(t_stack *a)
{
	t_node *current;
	t_node *min_node;
	int index;
	int min_value;

	index = 0;
	while (index < a->size)
	{
		current = a->top;
		min_value = INT_MAX;
		min_node = NULL;

		while (current)
		{
			if (current->target == -1 && current->value < min_value)
			{
				min_value = current->value;
				min_node = current;
			}
			current = current->next;
		}
		if (min_node)
			min_node->target = index++;
	}
}

void push_swap(t_stack *a, t_stack *b)
{
	// ft_printf("Stack before operations:\n");
	// ft_printf("Top: %d\n", a->top->value);
	// if (a->top->next)
	// 	ft_printf("Next: %d\n", a->top->next->value);
	assign_targets(a);
	if (a->size <= 3)
		sort_small(a);
	else if (a->size <= 20)
		sort_insertion(a, b);
	// else if (a->size > 20)
	//  	sort_large(a, b);
	//print_stack(a);
}
