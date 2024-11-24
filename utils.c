#include "push_swap.h"

void	ft_error(t_stack *a, t_stack *b)
{
	if (a)
		free_stack(&a);
	if (b)
		free_stack(&b);
	write(2, "Error\n", 6);
	exit(1);
}

int	find_max(t_stack *stack)
{
	t_node	*current;
	int		max_value;

	if (stack == NULL || stack->top == NULL)
		return (INT_MIN);
	current = stack->top;
	max_value = current->value;
	while (current != NULL)
	{
		if (current->value > max_value)
			max_value = current->value;
		current = current->next;
	}
	return (max_value);
}

int	find_min(t_stack *stack)
{
	t_node	*current;
	int		min_value;

	if (stack == NULL || stack->top == NULL)
		return (INT_MAX);
	current = stack->top;
	min_value = current->value;
	while (current)
	{
		if (current->value < min_value)
			min_value = current->value;
		current = current->next;
	}
	return (min_value);
}

int	ft_isempty(t_stack *stack)
{
	return (stack == NULL || stack->size == 0);
}

void	print_stack_contents(t_node *stack_top, char *stack_name)
{
	t_node	*temp;

	temp = stack_top;
	if (temp)
	{
		ft_printf("\n|####################|");
		ft_printf("\n|--------------------|");
		ft_printf("\n    %s\n", stack_name);
		ft_printf("|--------------------|");
		while (temp)
		{
			ft_printf("\n\t%d\n  +----------------+", temp->value);
			temp = temp->next;
		}
		ft_printf("\n\tNULL\n|--------------------|");
	}
}

void	print_stacks(t_stack *a, t_stack *b)
{
	if (a)
		print_stack_contents(a->top, "STACK A");
	if (b)
		print_stack_contents(b->top, "STACK B");
	ft_printf("\n|####################|");
	ft_printf("\n|####################|\n");
}

void print_stack(t_stack *stack) {
	t_node *current_node;

	if (!stack || !stack->top) {
		ft_printf("Stack is empty.\n");
		return;
	}
	ft_printf("Stack (size %d):\n", stack->size);
	current_node = stack->top;
	ft_printf("Stack: ");
	while (current_node != NULL) 
	{
		ft_printf("\n\t Value: %d \t", current_node->value);
		ft_printf("Target: %d \n", current_node->target);
		current_node = current_node->next;
	}

	ft_printf("\n");
}