#include "push_swap.h"

void	ft_error(t_stack *a, t_stack *b)
{
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	write(2, "Error\n", 6);
	exit (1);
}



int	find_max(t_stack *stack)
{
	t_node	*current;
	int		max_value;

	if (stack == NULL || stack->top == NULL)
		return (0);
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
	int min_value;

	if (stack == NULL || stack->top == NULL)
		return (1);
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

int ft_isempty(t_stack *stack)
{
	return (stack == NULL || stack->size == 0);
}

void	print_stacks(t_stack *a, t_stack *b)
{
	t_node *temp_a;
	t_node *temp_b;

	temp_a = a->top;
	temp_b = b->top;
	if (a)
	{
		ft_printf("\n|####################|");
		ft_printf("\n|####################|");
		ft_printf("\n|--------------------|");
		ft_printf("\n    STACK A\n");
		ft_printf("|--------------------|");
		while (temp_a)
		{
			ft_printf("\n\t%d\n  +----------------+", temp_a->value);
			temp_a = temp_a->next;
		}
		ft_printf("\n\tNULL\n|--------------------|\n");
	}
	if (b)
	{
		ft_printf("|####################|");
		ft_printf("\n|####################|");
		ft_printf("\n|--------------------|");
		ft_printf("\n    STACK B\n");
		ft_printf("|--------------------|");
		while (temp_b)
		{
			ft_printf("\n\t%d\n +----------------+", temp_b->value);
			temp_b = temp_b->next;
		}
		ft_printf("\n\tNULL\n|--------------------|");
		ft_printf("\n|####################|");
		ft_printf("\n|####################|\n");
	}
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
