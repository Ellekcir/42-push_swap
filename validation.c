#include "push_swap.h"

int	ft_isint(const char *arg)
{
	int	sign;
	long	value;

	while ((*arg >= 9 && *arg <= 13) || *arg == 32)
		arg++;
	if (*arg == '\0')
	{
//		ft_printf("Input is empty");
		return (0);
	}
	value = 0;
	sign = 1;
	if (*arg == '-' || *arg == '+')
	{
		if (*arg == '-')
			sign = -1;
		arg++;
	}
	while (*arg)
	{		
		if (!ft_isdigit(*arg)) //|| (*arg != '-' && *arg != '+')
		{
//			ft_printf("Not a digit");
			ft_error(NULL, NULL);
		}
		value = value * 10 + (*arg - '0');
		arg++;
		if (value * sign > 2147483647) // Check for overflow
		{
//          ft_printf("Out of integer boundaries");
			ft_error(NULL, NULL);
		}
		if (value * sign < -2147483648)
		{
//            ft_printf("Out of integer boundaries");
			ft_error(NULL, NULL);
		}
	}
	return ((int)(value * sign));
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

	if (!stack || !stack || !stack->top || !stack->top->next)
		return (1);
	current_node = stack->top;
	while (current_node->next != NULL) 
	{        
		if (current_node->value > current_node->next->value)
			return (0);
		current_node = current_node->next;
	}
	return (1);
}
