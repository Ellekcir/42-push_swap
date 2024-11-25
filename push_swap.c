#include "push_swap.h"

void assign_targets(t_stack *a)
{
	t_node *current;
	t_node *min_node;
	int index;
	int min_value;

	index = 0;
	if (!a)
		ft_error(a, NULL);
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
		{
			min_node->target = index;
			index++;
		}
	}
}

void push_swap(t_stack *a, t_stack *b)
{
	//assign_targets(a);
	// print_stack(a);
	if (!a || !b)
		ft_error(a, b);
	if (a->size <= 3)
		sort_small(a);
	else if (a->size <= 6)
		sort_medium(a, b);
	else
	 	sort_large(a, b);
	 //void assign_targets(t_stack *a)
}

