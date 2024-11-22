#include "push_swap.h"

int ft_isint(char *arg)
{
    int sign = 1;
    long value = 0;

    // Skip leading spaces
    while ((*arg >= 9 && *arg <= 13) || *arg == 32)
        arg++;

    // Check if the string is empty
    if (*arg == '\0')
        return 0;

    // Handle sign (+ or -)
    if (*arg == '-' || *arg == '+')
    {
        if (*arg == '-')
    		sign = -1;
		else
    		sign = 1;
	
        arg++;  // Move to the next character
    }

    // Process digits
    while (*arg)
    {
        if (!ft_isdigit(*arg))  // Ensure it's a digit
            ft_error(NULL, NULL);

        value = value * 10 + (*arg - '0');

        // Check for overflow
        if ((value > INT_MAX && sign == 1) || (value > (long)INT_MAX + 1 && sign == -1))
            ft_error(NULL, NULL);

        arg++;
    }

    value *= sign;

    // Check boundaries
    if (value < INT_MIN || value > INT_MAX)
        ft_error(NULL, NULL);

    return (int)value;
}

int	ft_isdup(t_stack *a)
{
	t_node	*current_node;	
	t_node	*next_node;

	if (!a || !a)
		return (1);
	current_node = a->top;
	while (current_node != NULL)
	{
		next_node = current_node->next;
		while (next_node != NULL)
		{
			if (current_node->value == next_node->value)
				return (0);
			next_node = next_node->next;
		}
		current_node = current_node->next;
	}
	return (1);
}

int ft_issorted(t_stack *stack)
{
	t_node	*current_node;

	if (!stack || !stack->top || !stack->top->next)
		return (1);
	current_node = stack->top;
	while (current_node->next != NULL) 
	{        
		if (current_node->value < current_node->next->value)
			return (0);
		current_node = current_node->next;
	}
	return (1);
}