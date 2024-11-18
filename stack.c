#include "push_swap.h"

t_node	*create_node(int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;

	return (new_node);
}

t_stack	*create_stack(void)
{
	t_stack	*new_stack;
	
	new_stack = malloc(sizeof(t_stack));
	if (!new_stack)
	{
//		ft_printf("Failure to create stacks");
		ft_error(NULL, NULL);
	}
	new_stack->top = NULL;
	new_stack->size = 0;
//	ft_printf("Stack created\n");
	return (new_stack);
}

void	put_value_to_stack(t_stack *stack, int value)
{
	if (!stack)
    {
//        ft_printf("Error: Stack is NULL\n");
        ft_error(stack, NULL);
    }
	t_node	*new_node;
	
	new_node = create_node(value);
	if (!new_node)
		return ;
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size++;
//	ft_printf("Value added to stack: %d\n", value);
//	ft_printf("Stack size: %d\n", stack->size);
//	print_stack(stack);
}


int	free_nodes_from_stack(t_stack *stack)
{
	t_node	*top_node;

	if (!stack)
		return (0);
	top_node = stack->top;
	stack->top = top_node->next;
	free(top_node);
	stack->size--;

	return (stack->size);
}

void	free_stack(t_stack	*stack)
{
	if (!stack)
		return ;
	while (stack->size > 0)
		free_nodes_from_stack(stack);
	free(stack);
	stack = NULL;
}