#include "push_swap.h"

// Function to create a new node
t_node *create_node(int value)
{
	t_node *new_node;

	ft_printf("CREATING NEW NODE\n");
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->target_value = -1; // Initialize target_value as -1 to flag not been sorted
	new_node->next = NULL;
	ft_printf("A new node has been created: %d\n", new_node->value);

	return (new_node);
}

// Function to create a new stack
t_stack *create_stack(void)
{
	ft_printf("------ CREATING A NEW STACK ------\n\n");
	t_stack *new_stack;
	
	new_stack = malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->top = NULL;
	new_stack->size = 0;
	ft_printf("A new stack has been created with size: %d\n", new_stack->size);

	return (new_stack);
}

// Example of pushing a value onto the stack
void put_value_to_stack(t_stack *stack, int value)
{
	t_node *new_node;
	
	ft_printf("\n----- PUTTING NEW VALUE INTO STACK -----\n");
	new_node = create_node(value);
	if (!new_node)
		return;
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size++;
	ft_printf("A value of: %i has been put in stack\n", value);

}


int free_nodes_from_stack(t_stack *stack)
{
	ft_printf("FREEING NODE FROM STACK\n");
	t_node *top_node;

	top_node = stack->top;
	stack->top = top_node->next;
	free(top_node);
	stack->size--;

	
	return (stack->size);
}

// Free the stack and its nodes
void free_stack(t_stack *stack)
{
	ft_printf("\n----- FREEING STACK -----\n");
	if (!stack)
    {
        ft_printf("Stack is NULL, nothing to free.\n");
        return;
    }
	while (stack->size > 0)
	{
		ft_printf("Stack Size: %d\n", stack->size);
		ft_printf("Node Value: %i\n", stack->top->value);
		free_nodes_from_stack(stack);
	}
	free(stack);
	ft_printf("\n----- Stack has been fully freed.-----\n");
}

void	print_stack(t_stack *stack)
{
	t_node	*current;

    if (!stack || !stack->top)
    {
        ft_printf("Stack is empty.\n");
        return ;
    }
	current = stack->top;
	while (current != NULL)
	{
		ft_printf("\n%i", current->value);
		current = current->next;
	}
}