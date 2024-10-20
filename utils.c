#include "push_swap.h"
#include "./libft/libft.h"
/* Initialize a new stack */
t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		exit_error();
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

/* Check if the stack is sorted in ascending order */
int	is_sorted(t_stack *stack)
{
	t_node	*temp;

	if (!stack || stack->size < 2)
		return (1);
	temp = stack->top;
	while (temp->next)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

/* Parse input arguments and push them to stack A */
int	parse_args(t_stack *stack, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_int(argv[i]))
			return (0);
		push(stack, (argv[i]));
		i++;
	}
	return (1);
}

int	find_max(t_stack *stack)
{
	t_node	*current;
	int		max_value;

	if (!stack || stack->size == 0)
		return (0);

	current = stack->top;
	max_value = current->value;
	while (current)
	{
		if (current->value > max_value)
			max_value = current->value;
		current = current->next;
	}
	return (max_value);
}
